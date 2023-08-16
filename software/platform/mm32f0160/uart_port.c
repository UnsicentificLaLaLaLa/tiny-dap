/*
 * MIT License
 *
 * Copyright (c) 2023 UnsicentificLaLaLaLa
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include "hal_rcc.h"
#include "hal_gpio.h"
#include "hal_dma.h"
#include "hal_dma_request.h"
#include "hal_uart.h"
#include "tusb.h"

static uint8_t uart_recv_buf[128];
static uint8_t uart_tx_buf[128];

void uart_init(cdc_line_coding_t const* p_line_coding)
{
    RCC_EnableAHB1Periphs(RCC_AHB1_PERIPH_DMA1, true);
    RCC_ResetAHB1Periphs(RCC_AHB1_PERIPH_DMA1);

    DMA_Channel_Init_Type dma_chn_uart_recv_init;
    dma_chn_uart_recv_init.MemAddr            = (uint32_t)uart_recv_buf;
    dma_chn_uart_recv_init.MemAddrIncMode     = DMA_AddrIncMode_IncAfterXfer;
    dma_chn_uart_recv_init.PeriphAddr         = UART_GetRxDataRegAddr(UART2);
    dma_chn_uart_recv_init.PeriphAddrIncMode  = DMA_AddrIncMode_StayAfterXfer;
    dma_chn_uart_recv_init.XferMode           = DMA_XferMode_PeriphToMemory;
    dma_chn_uart_recv_init.XferWidth          = DMA_XferWidth_8b;
    dma_chn_uart_recv_init.XferCount          = sizeof(uart_recv_buf);
    dma_chn_uart_recv_init.ReloadMode         = DMA_ReloadMode_AutoReloadContinuous;
    dma_chn_uart_recv_init.Priority           = DMA_Priority_High;
    DMA_InitChannel(DMA1, DMA_REQ_DMA1_UART2_RX_1, (DMA_Channel_Init_Type*)&dma_chn_uart_recv_init);
    DMA_EnableChannel(DMA1, DMA_REQ_DMA1_UART2_RX_1, true);

    DMA_Channel_Init_Type dma_chn_uart_send_init;
    dma_chn_uart_send_init.MemAddr            = (uint32_t)uart_tx_buf;
    dma_chn_uart_send_init.MemAddrIncMode     = DMA_AddrIncMode_IncAfterXfer;
    dma_chn_uart_send_init.PeriphAddr         = UART_GetTxDataRegAddr(UART2);
    dma_chn_uart_send_init.PeriphAddrIncMode  = DMA_AddrIncMode_StayAfterXfer;
    dma_chn_uart_send_init.XferMode           = DMA_XferMode_MemoryToPeriph;
    dma_chn_uart_send_init.XferWidth          = DMA_XferWidth_8b;
    dma_chn_uart_send_init.XferCount          = 0;
    dma_chn_uart_send_init.ReloadMode         = DMA_ReloadMode_AutoReload;
    dma_chn_uart_send_init.Priority           = DMA_Priority_High;
    DMA_InitChannel(DMA1, DMA_REQ_DMA1_UART2_TX_1, (DMA_Channel_Init_Type*)&dma_chn_uart_send_init);

    UART_WordLength_Type wordlen[] =
    {
        [5] = UART_WordLength_5b,
        [6] = UART_WordLength_6b,
        [7] = UART_WordLength_7b,
        [8] = UART_WordLength_8b,
    };
    UART_StopBits_Type stopbits[] =
    {
        [0] = UART_StopBits_1,
        [1] = UART_StopBits_1_5,
        [2] = UART_StopBits_2,
    };
    UART_Parity_Type parity[] =
    {
        [0] = UART_Parity_None,
        [1] = UART_Parity_Odd,
        [2] = UART_Parity_Even,
    };

    RCC_EnableAPB1Periphs(RCC_APB1_PERIPH_UART2, true);
    RCC_ResetAPB1Periphs(RCC_APB1_PERIPH_UART2);

    UART_Init_Type uart_init;
    uart_init.ClockFreqHz   = 48000000;
    uart_init.BaudRate      = p_line_coding->bit_rate;
    uart_init.WordLength    = wordlen[p_line_coding->data_bits];
    uart_init.StopBits      = stopbits[p_line_coding->stop_bits];
    uart_init.Parity        = parity[p_line_coding->parity];
    uart_init.XferMode      = UART_XferMode_RxTx;
    uart_init.HwFlowControl = UART_HwFlowControl_None;
    uart_init.XferSignal    = UART_XferSignal_Normal;
    uart_init.EnableSwapTxRxXferSignal = false;
    UART_Init(UART2, (UART_Init_Type*)&uart_init);
    UART_Enable(UART2, true);
    UART_EnableDMA(UART2, true);

    RCC_EnableAHB1Periphs(RCC_AHB1_PERIPH_GPIOA, true);

    GPIO_Init_Type gpio_init;
    /* PA3 - UART2_RX. */
    gpio_init.Pins  = GPIO_PIN_3;
    gpio_init.PinMode  = GPIO_PinMode_In_Floating;
    gpio_init.Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &gpio_init);
    GPIO_PinAFConf(GPIOA, gpio_init.Pins, GPIO_AF_1);

    /* PA2 - UART2_TX. */
    gpio_init.Pins  = GPIO_PIN_2;
    gpio_init.PinMode  = GPIO_PinMode_AF_PushPull;
    gpio_init.Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &gpio_init);
    GPIO_PinAFConf(GPIOA, gpio_init.Pins, GPIO_AF_1);
}

static uint32_t last_recv_index = 0;

bool uart_rx_available(void)
{
    uint32_t now_recv_index = sizeof(uart_recv_buf) - DMA1->CH[DMA_REQ_DMA1_UART2_RX_1].CNDTR;
    return now_recv_index != last_recv_index;
}

uint32_t uart_rx(uint8_t *buf, uint32_t buf_len)
{
    uint32_t now_recv_index = sizeof(uart_recv_buf) - DMA1->CH[DMA_REQ_DMA1_UART2_RX_1].CNDTR;
    uint32_t i = 0;
    while(i < buf_len && last_recv_index != now_recv_index)
    {
        buf[i] = uart_recv_buf[last_recv_index];
        last_recv_index++;
        last_recv_index %= sizeof(uart_recv_buf);
        i++;
    }
    return i;
}

bool uart_tx_idle(void)
{
    return (DMA1->CH[DMA_REQ_DMA1_UART2_TX_1].CCR & DMA_CCR_EN_MASK) == 0;
}

uint32_t uart_tx(uint8_t *buf, uint32_t buf_len)
{
    memcpy(uart_tx_buf, buf, buf_len);
    DMA1->CH[DMA_REQ_DMA1_UART2_TX_1].CNDTR = buf_len;
    DMA_EnableChannel(DMA1, DMA_REQ_DMA1_UART2_TX_1, true);
    return buf_len;
}

/* uart_port.c - end */
