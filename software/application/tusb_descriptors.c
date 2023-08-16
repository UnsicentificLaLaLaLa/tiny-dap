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

#include "tusb.h"

/*
 * Device Descriptors
 */
const tusb_desc_device_t desc_device =
{
    .bLength            = sizeof(tusb_desc_device_t),
    .bDescriptorType    = TUSB_DESC_DEVICE,
    .bcdUSB             = 0x0110,
    .bDeviceClass       = 0x00,
    .bDeviceSubClass    = 0x00,
    .bDeviceProtocol    = 0x00,
    .bMaxPacketSize0    = CFG_TUD_ENDPOINT0_SIZE,

    .idVendor           = 0x3333,
    .idProduct          = 0x4005,
    .bcdDevice          = 0x0100,

    .iManufacturer      = 0x01,
    .iProduct           = 0x02,
    .iSerialNumber      = 0x03,

    .bNumConfigurations = 0x01
};

/* Invoked when received GET DEVICE DESCRIPTOR
 * Application return pointer to descriptor
 */
uint8_t const * tud_descriptor_device_cb(void)
{
    return (uint8_t const *) &desc_device;
}

/*
 * HID Report Descriptor
 */

const uint8_t desc_hid_report[] =
{
    TUD_HID_REPORT_DESC_GENERIC_INOUT(CFG_TUD_HID_EP_BUFSIZE)
};

/* Invoked when received GET HID REPORT DESCRIPTOR
 * Application return pointer to descriptor
 * Descriptor contents must exist long enough for transfer to complete
 */
uint8_t const * tud_hid_descriptor_report_cb(uint8_t itf)
{
    (void) itf;
    return desc_hid_report;
}

/*
 * Configuration Descriptor
 */

enum
{
    ITF_NUM_HID,
    ITF_NUM_CDC,
    ITF_NUM_CDC_DATA,
    ITF_NUM_TOTAL
};

#define  CONFIG_TOTAL_LEN  (TUD_CONFIG_DESC_LEN + TUD_HID_INOUT_DESC_LEN + TUD_CDC_DESC_LEN)

#define EPNUM_HID           0x01
#define EPNUM_CDC_NOTIF     0x82
#define EPNUM_CDC_OUT       0x03
#define EPNUM_CDC_IN        0x83

uint8_t const desc_configuration[] =
{
    /* Config number, interface count, string index, total length, attribute, power in mA. */
    TUD_CONFIG_DESCRIPTOR(1, ITF_NUM_TOTAL, 0, CONFIG_TOTAL_LEN, 0x00, 100),

    /* Interface number, string index, protocol, report descriptor len, EP Out & In address, size & polling interval. */
    TUD_HID_INOUT_DESCRIPTOR(ITF_NUM_HID, 0, HID_ITF_PROTOCOL_NONE, sizeof(desc_hid_report), EPNUM_HID, 0x80 | EPNUM_HID, CFG_TUD_HID_EP_BUFSIZE, 0),

    /* Interface number, string index, EP notification address and size, EP data address (out, in) and size. */
    TUD_CDC_DESCRIPTOR(ITF_NUM_CDC, 4, EPNUM_CDC_NOTIF, 8, EPNUM_CDC_OUT, EPNUM_CDC_IN, 64),
};

/* Invoked when received GET CONFIGURATION DESCRIPTOR
 * Application return pointer to descriptor
 * Descriptor contents must exist long enough for transfer to complete
 */
uint8_t const * tud_descriptor_configuration_cb(uint8_t index)
{
    (void) index;
    return desc_configuration;
}

/*
 * String Descriptors
 */

/* array of pointer to string descriptors
 */
static char uid_str[9];
char const *string_desc_arr [] =
{
    (const char[]) { 0x09, 0x04 },  /* 0: is supported language is English (0x0409) */
    "MindMotion",                   /* 1: Manufacturer                              */
    "CMSIS-DAP",                    /* 2: Product                                   */
    uid_str,                        /* 3: Serials, should use chip ID               */
    "CDC"                           /* 4: CDC                                       */
};

static uint16_t _desc_str[32];

/* Invoked when received GET STRING DESCRIPTOR request
 * Application return pointer to descriptor, whose contents must exist long enough for transfer to complete
 */
uint16_t const* tud_descriptor_string_cb(uint8_t index, uint16_t langid)
{
  (void) langid;

  uint8_t chr_count;

  uint32_t *des = (uint32_t*)0x1FFFF7E8;
  sprintf(uid_str, "%08X", des[2]);

  if ( index == 0)
  {
    memcpy(&_desc_str[1], string_desc_arr[0], 2);
    chr_count = 1;
  }else
  {
    /* Note: the 0xEE index string is a Microsoft OS 1.0 Descriptors. */
    /* https://docs.microsoft.com/en-us/windows-hardware/drivers/usbcon/microsoft-defined-usb-descriptors */

    if ( !(index < sizeof(string_desc_arr)/sizeof(string_desc_arr[0])) ) return NULL;

    const char* str = string_desc_arr[index];

    /* Cap at max char */
    chr_count = (uint8_t) strlen(str);
    if ( chr_count > 31 ) chr_count = 31;

    /* Convert ASCII string into UTF-16 */
    for(uint8_t i=0; i<chr_count; i++)
    {
      _desc_str[1+i] = str[i];
    }
  }

  /* first byte is length (including header), second byte is string type */
  _desc_str[0] = (uint16_t) ((TUSB_DESC_STRING << 8 ) | (2*chr_count + 2));

  return _desc_str;
}

/* tusb_descriptors.c - end */
