/*
 * Copyright 2023 MindMotion Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "device/dcd.h"
#include "hal_usb.h"
#include "hal_rcc.h"

#include "tusb.h"

/* OTG_FS BufferDescriptorTable Buffer. */
static __ALIGNED(512u) USB_BufDespTable_Type usb_bd_tbl = {0u}; /* usb_bufdesp_table */
static uint8_t usb_ep0_buffer[CFG_TUD_ENDPOINT0_SIZE] = {0u};   /* usb_recv_buff. */
static uint8_t usb_setup_buff[8u] = {0u};       /* usb_setup_buff. */
static uint8_t usb_device_addr = 0u;            /* usb_device_addr. */

typedef struct
{
    uint8_t * xfer_buf;
    uint32_t max_packet_size;   /* EndPoint max packet size. */
    uint32_t length;            /* EndPoint xfer data length. */
    uint32_t remaining;         /* EndPoint xfer data remaining. */
    bool  odd_even;          /* EndPoint BD OddEven status. */
    bool  data_n;            /* next packet is DATA0 or DATA1. */
    bool  xfer_done;
} USB_EndPointManage_Type;

static USB_EndPointManage_Type usb_epmng_tbl[16u][2u] = {0u}; /* EndPoint Manage Table. */

void USB_BusResetHandler(void)
{
    USB_EnableOddEvenReset(USB, true);
    USB_EnableOddEvenReset(USB, false);  /* OddEven Reset. */
    USB_SetDeviceAddr(USB, 0x00u);       /* Set USB device addr equal 0x00. */
    USB_EndPointManage_Type epm = {0u};

    for (uint32_t i = 0u; i < USB_BDT_EP_NUM; i++) /* disable all EndPoint. */
    {
        USB_EnableEndPoint(USB, i, USB_EndPointMode_NULL, false);
        usb_epmng_tbl[i][USB_Direction_IN] = epm;
        usb_epmng_tbl[i][USB_Direction_OUT] = epm;
    }

    USB_EnableEndPoint(USB, 0u, USB_EndPointMode_Control, true); /* enable EP0. */
    epm.max_packet_size = CFG_TUD_ENDPOINT0_SIZE;
    epm.length          = CFG_TUD_ENDPOINT0_SIZE;
    epm.remaining       = CFG_TUD_ENDPOINT0_SIZE;
    usb_epmng_tbl[0u][USB_Direction_IN ] = epm;
    usb_epmng_tbl[0u][USB_Direction_OUT] = epm; /* set EP0 ep manage. */

    /* start recv setup data. */
    USB_BufDesp_Xfer(&usb_bd_tbl.Table[0u][USB_Direction_OUT][USB_BufDesp_OddEven_Even], 1u, usb_ep0_buffer, sizeof(usb_setup_buff));
    usb_epmng_tbl[0u][USB_Direction_IN].data_n = true; /* the first Tx data's data_n is 1. */
}

void USB_TokenDoneHandler(uint8_t rhport) /* roothub port. */
{
    USB_BufDesp_Type             * bd = USB_GetBufDesp(USB); /* get bd. */
    USB_TokenPid_Type           token = USB_BufDesp_GetTokenPid(bd); /* get token pid. */
    uint32_t                     size = USB_BufDesp_GetPacketSize(bd); /* get packet size. */
    uint8_t                    * addr = (uint8_t *)USB_BufDesp_GetPacketAddr(bd); /* get packet addr. */
    uint32_t                 ep_index = USB_GetEndPointIndex(USB); /* which EP Xfer data. */
    USB_Direction_Type         ep_dir = USB_GetXferDirection(USB); /* EP direction. */
    USB_BufDesp_OddEven_Type      odd = USB_GetBufDespOddEven(USB); /* ODD_EVEN. */
    USB_BufDesp_Reset(bd);
    usb_epmng_tbl[ep_index][ep_dir].odd_even = !odd; /* toggle the bd odd_even flag. */
    USB_ClearInterruptStatus(USB, USB_INT_TOKENDONE);/* clear interrupt status. */

    if (0u == ep_index && USB_Direction_OUT == ep_dir ) /* ep0_out include setup packet & out_packet, need to special treatment */
    {
        if (USB_TokenPid_SETUP == token) /* setup packet. */
        {
            for (uint32_t i = 0; i < 8u; i++)
            {
                usb_setup_buff[i] = usb_ep0_buffer[i];
            }
            dcd_event_setup_received(rhport, addr, true);
            USB_EnableSuspend(USB, false);
            usb_epmng_tbl[0u][USB_Direction_IN].data_n = true; /* next in packet is DATA1 packet. */
            usb_epmng_tbl[0u][USB_Direction_OUT].xfer_done = false;
            USB_BufDesp_Xfer(&usb_bd_tbl.Table[0u][USB_Direction_OUT][!odd], 1u, usb_ep0_buffer, sizeof(usb_ep0_buffer));
        }
        else /* out packet. */
        {
            if (0 < size && NULL == usb_epmng_tbl[0u][USB_Direction_OUT].xfer_buf)
            {   /* received data, but tinyusb not prepared. */
                usb_epmng_tbl[0u][USB_Direction_OUT].xfer_done = true;
                USB_BufDesp_Xfer(&usb_bd_tbl.Table[0u][USB_Direction_OUT][!odd], 1u, usb_ep0_buffer, sizeof(usb_ep0_buffer));
                return;
            }
            for (uint32_t i = 0; i < size; i++)
            {
                usb_epmng_tbl[0u][USB_Direction_OUT].xfer_buf[i] = usb_ep0_buffer[i];
            }
            dcd_event_xfer_complete(rhport, 0u, size, XFER_RESULT_SUCCESS, true);
            USB_BufDesp_Xfer(&usb_bd_tbl.Table[0u][USB_Direction_OUT][!odd], 1u, usb_ep0_buffer, sizeof(usb_ep0_buffer));
        }

        /* Continue to receive out packets. */

        return;
    }

    /* xfer next packet if data length more than max_packet_size when start xfer data. */
    uint16_t max_packet_size = usb_epmng_tbl[ep_index][ep_dir].max_packet_size;
    uint16_t          length = usb_epmng_tbl[ep_index][ep_dir].length;
    uint16_t       remaining = usb_epmng_tbl[ep_index][ep_dir].remaining - size;
    if ( (remaining > 0u) && (size == usb_epmng_tbl[ep_index][ep_dir].max_packet_size) )
    {
        usb_epmng_tbl[ep_index][ep_dir].remaining = remaining;
        if(remaining > max_packet_size)
        {
            uint8_t *next_packet_addr    = addr + 2u * max_packet_size;
            uint16_t next_packet_size    = remaining - max_packet_size;
            if(next_packet_size > max_packet_size)
            {
                next_packet_size = max_packet_size;
            }
            USB_BufDesp_Xfer(bd,usb_epmng_tbl[ep_index][ep_dir].data_n, next_packet_addr, next_packet_size);
            usb_epmng_tbl[ep_index][ep_dir].data_n = !usb_epmng_tbl[ep_index][ep_dir].data_n;
        }
        return;
    }

    /* set addr. */
    if(size == 0u && 0u != usb_device_addr)/* ZLP, if usb_device_addr not equal 0, need to set addr to USB. */
    {
        USB_SetDeviceAddr(USB, usb_device_addr);
        usb_device_addr = 0u;
    }

    /* report to tusb. */
    uint8_t ep_addr = ep_index;
    if (USB_Direction_IN == ep_dir)
    {
        ep_addr |= TUSB_DIR_IN_MASK;
    }
    dcd_event_xfer_complete(rhport,  ep_addr, length - remaining, XFER_RESULT_SUCCESS, true);
}




//--------------------------------------------------------------------+
// Controller API
//--------------------------------------------------------------------+

// Initialize controller to device mode
void dcd_init       (uint8_t rhport)
{
    (void) rhport;
    RCC_EnableAHB1Periphs(RCC_AHB1_PERIPH_USB, true);
    RCC_ResetAHB1Periphs(RCC_AHB1_PERIPH_USB);

    USB_Device_Init_Type init = {0u};
    init.BufDespTable_Addr = (uint32_t)&usb_bd_tbl;
    USB_InitDevice(USB, &init);
    USB_Enable(USB, true);
    NVIC_ClearPendingIRQ(USB_IRQn);
}

// Interrupt Handler
void dcd_int_handler(uint8_t rhport)
{
    uint32_t flag = USB_GetInterruptStatus(USB);

    if (flag & USB_INT_TOKENDONE)
    {
        USB_TokenDoneHandler(rhport);
        return;
    }

    if (flag & USB_INT_RESET)
    {
        USB_ClearInterruptStatus(USB, USB_INT_RESET);
        USB_BusResetHandler();

        dcd_event_bus_reset(rhport, TUSB_SPEED_FULL, true);
    }

    if (flag & USB_INT_SLEEP)
    {
        USB_ClearInterruptStatus(USB, USB_INT_SLEEP);

        dcd_event_bus_signal(rhport, DCD_EVENT_SUSPEND, true);
    }
    if (flag & USB_INT_RESUME)
    {
        USB_ClearInterruptStatus(USB, USB_INT_RESUME);

        dcd_event_bus_signal(rhport, DCD_EVENT_RESUME, true);
    }
    if (flag & USB_INT_STALL)
    {
        USB_EnableEndPointStall(USB, USB_EP_0, false);
        dcd_edpt_clear_stall(rhport, 0);
        USB_BufDesp_Xfer(&usb_bd_tbl.Table[0u][USB_Direction_OUT][usb_epmng_tbl[0u][USB_Direction_OUT].odd_even], 1, usb_ep0_buffer, 64);
        USB_ClearInterruptStatus(USB, USB_INT_STALL);
    }
    if (flag & USB_INT_SOFTOK)
    {
        USB_ClearInterruptStatus(USB, USB_INT_SOFTOK);
    }
}

// Enable device interrupt
void dcd_int_enable (uint8_t rhport)
{
    (void) rhport;
    USB_EnableInterrupts(USB, USB_INT_RESET | USB_INT_TOKENDONE
                                            | USB_INT_SLEEP
                                            | USB_INT_RESUME
                                            | USB_INT_STALL
                                            | USB_INT_SOFTOK, true); /* enable interrupts*/
    NVIC_SetPriority(USB_IRQn, 3u);
    NVIC_EnableIRQ(USB_IRQn);
}

// Disable device interrupt
void dcd_int_disable(uint8_t rhport)
{
    (void) rhport;
    NVIC_DisableIRQ(USB_IRQn);
    USB_EnableInterrupts(USB, USB_INT_RESET | USB_INT_TOKENDONE
                                            | USB_INT_SLEEP
                                            | USB_INT_RESUME
                                            | USB_INT_STALL
                                            | USB_INT_SOFTOK, false); /* enable interrupts*/
}

// Receive Set Address request, mcu port must also include status IN response
void dcd_set_address(uint8_t rhport, uint8_t dev_addr)
{
    usb_device_addr = dev_addr;
    /* get addr, Tx ZLP, then set addr to USB. */
    dcd_edpt_xfer(rhport, tu_edpt_addr(0, TUSB_DIR_IN), NULL, 0);
}

// Wake up host
void dcd_remote_wakeup(uint8_t rhport)
{
    (void) rhport;
    USB_EnableResumeSignal(USB, true);
    uint32_t i = 96000000 / 1000; /* 10ms. */
    while(i--)
    {
        __NOP();
    }
    USB_EnableResumeSignal(USB, false);
}

// Enable/Disable Start-of-frame interrupt. Default is disabled
void dcd_sof_enable(uint8_t rhport, bool en)
{
    (void) rhport;
    if (true == en)
    {
        USB_EnableInterrupts(USB, USB_INT_SOFTOK, true); /* enable interrupts*/
    }
    else
    {
        USB_EnableInterrupts(USB, USB_INT_SOFTOK, false); /* disable interrupts*/
    }
}

//--------------------------------------------------------------------+
// Endpoint API
//--------------------------------------------------------------------+

// Configure endpoint's registers according to descriptor
bool dcd_edpt_open            (uint8_t rhport, tusb_desc_endpoint_t const * desc_ep)
{
    (void) rhport;
    uint8_t ep_index = desc_ep->bEndpointAddress & 0x0fu;
    USB_Direction_Type ep_dir = USB_Direction_OUT;

    /* get direction. */
    if ((desc_ep->bEndpointAddress & TUSB_DIR_IN_MASK) == TUSB_DIR_IN_MASK)
    {
        ep_dir = USB_Direction_IN;
    }

    /* according to usb role, choose the EP mode. */
    USB_EndPointMode_Type ep_mode = USB_EndPointMode_Control;
    if     (TUSB_XFER_ISOCHRONOUS == desc_ep->bmAttributes.xfer)
    {
        ep_mode = USB_EndPointMode_Isochronous;
    }
    else if(TUSB_XFER_BULK == desc_ep->bmAttributes.xfer)
    {
        ep_mode = USB_EndPointMode_Bulk;
    }
    else if(TUSB_XFER_INTERRUPT == desc_ep->bmAttributes.xfer)
    {
        ep_mode = USB_EndPointMode_Interrupt;
    }

    usb_epmng_tbl[ep_index][ep_dir].max_packet_size = desc_ep->wMaxPacketSize;

    USB_EnableEndPoint(USB, ep_index, ep_mode, true);/* enable EPx. */
    return true;
}

// Close all non-control endpoints, cancel all pending transfers if any.
// Invoked when switching from a non-zero Configuration by SET_CONFIGURE therefore
// required for multiple configuration support.
void dcd_edpt_close_all       (uint8_t rhport)
{
    for (uint32_t i = 1u; i < USB_BDT_EP_NUM; i++)
    {
        USB_EnableEndPoint(USB, i, USB_EndPointMode_NULL, false); /* disable all EndPoint. */
        usb_epmng_tbl[i][USB_Direction_IN ].max_packet_size = 0;
        usb_epmng_tbl[i][USB_Direction_IN ].remaining       = 0;
        usb_epmng_tbl[i][USB_Direction_OUT].max_packet_size = 0;
        usb_epmng_tbl[i][USB_Direction_OUT].remaining       = 0;
    }
}

// Close an endpoint.
// Since it is weak, caller must TU_ASSERT this function's existence before calling it.
void dcd_edpt_close           (uint8_t rhport, uint8_t ep_addr)
{
    (void) rhport;
    usb_epmng_tbl[ep_addr & 0x0fu][USB_Direction_IN ].max_packet_size = 0;
    usb_epmng_tbl[ep_addr & 0x0fu][USB_Direction_IN ].remaining       = 0;
    usb_epmng_tbl[ep_addr & 0x0fu][USB_Direction_OUT].max_packet_size = 0;
    usb_epmng_tbl[ep_addr & 0x0fu][USB_Direction_OUT].remaining       = 0;
    USB_EnableEndPoint(USB, ep_addr & 0x0fu, USB_EndPointMode_NULL, false);
}

// Submit a transfer, When complete dcd_event_xfer_complete() is invoked to notify the stack
bool dcd_edpt_xfer            (uint8_t rhport, uint8_t ep_addr, uint8_t * buffer, uint16_t total_bytes)
{
    (void) rhport;
    uint32_t           ep_index = ep_addr & 0x0fu;
    USB_Direction_Type   ep_dir = (ep_addr & TUSB_DIR_IN_MASK) ? USB_Direction_IN : USB_Direction_OUT;
    uint32_t                odd = usb_epmng_tbl[ep_index][ep_dir].odd_even;
    uint32_t    max_packet_size = usb_epmng_tbl[ep_index][ep_dir].max_packet_size;
    uint32_t             data_n = usb_epmng_tbl[ep_index][ep_dir].data_n;

    if (0u == ep_index && ep_dir == USB_Direction_OUT)
    {
        if (true == usb_epmng_tbl[0u][USB_Direction_OUT].xfer_done)
        {
            for (uint32_t i = 0; i < total_bytes; i++)
            {
                buffer[i] = usb_ep0_buffer[i];
            }
            dcd_event_xfer_complete(rhport, 0u, total_bytes, XFER_RESULT_SUCCESS, true);
            usb_epmng_tbl[0u][USB_Direction_OUT].xfer_done = false;
        }
        else
        {
            usb_epmng_tbl[0u][USB_Direction_OUT].xfer_buf = buffer;
        }
        return true;
    }

    if ( USB_BufDesp_IsBusy(&usb_bd_tbl.Table[ep_index][ep_dir][odd]) ) /* BD.OWN not equal 0, mean BD owner is SIE, BD is busy. */
    {
        return false;
    }
    usb_epmng_tbl[ep_index][ep_dir].length    = total_bytes;
    usb_epmng_tbl[ep_index][ep_dir].remaining = total_bytes;
    if (total_bytes > max_packet_size) /* if xfer data length more than EP max_packet_size, divide data. */
    {
        /* more than double max_packet_size, xfer first two packet first. */
        uint32_t len2 = (total_bytes > 2u * max_packet_size) ? max_packet_size : (total_bytes - max_packet_size);
        USB_BufDesp_Xfer(&usb_bd_tbl.Table[ep_index][ep_dir][odd ^ 1u], data_n ^ 1u, buffer + max_packet_size, len2);
        USB_BufDesp_Xfer(&usb_bd_tbl.Table[ep_index][ep_dir][odd     ], data_n     , buffer                  , max_packet_size);
    }
    else
    {
        USB_BufDesp_Xfer(&usb_bd_tbl.Table[ep_index][ep_dir][odd], data_n, buffer, total_bytes);
        usb_epmng_tbl[ep_index][ep_dir].data_n ^= 1;
    }
    return true;
}

// Stall endpoint
void dcd_edpt_stall           (uint8_t rhport, uint8_t ep_addr)
{
    (void) rhport;
    uint32_t ep_index = ep_addr & 0x0fu;
    USB_EnableEndPointStall(USB, 1u << ep_index, true);
}

// clear stall, data toggle is also reset to DATA0
// This API never calls with control endpoints, since it is auto cleared when receiving setup packet
void dcd_edpt_clear_stall     (uint8_t rhport, uint8_t ep_addr)
{
    (void) rhport;
    uint32_t ep_index = ep_addr & 0x0fu;
    USB_EnableEndPointStall(USB, 1u << ep_index, false);
}

/* USB IRQ. */
void USB_IRQHandler(void)
{
    dcd_int_handler(TUD_OPT_RHPORT);
}

/* EOF. */
