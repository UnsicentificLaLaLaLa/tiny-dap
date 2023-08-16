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

#include "platform.h"
#include "tusb.h"
#include "DAP.h"

/* cdc task. */
void cdc_task(void);

int main(void)
{
    platform_init(); /* init board. */
    tusb_init(); /* init tinyusb. */
    DAP_Setup(); /* init dap. */

    while (1)
    {
        tud_task();
        cdc_task();
    }
}

/* hid callback. */

/* Invoked when received GET_REPORT control request
 * Application must fill buffer report's content and return its length.
 * Return zero will cause the stack to STALL request
 */
uint16_t tud_hid_get_report_cb(uint8_t itf, uint8_t report_id, hid_report_type_t report_type, uint8_t* buffer, uint16_t reqlen)
{
    (void) itf;
    (void) report_id;
    (void) report_type;
    (void) buffer;
    (void) reqlen;

    return 0;
}

/* Invoked when received SET_REPORT control request or
 * received data on OUT endpoint ( Report ID = 0, Type = 0 )
 */
uint8_t hid_tx_data_buf[CFG_TUD_HID_EP_BUFSIZE];
void tud_hid_set_report_cb(uint8_t itf, uint8_t report_id, hid_report_type_t report_type, uint8_t const* buffer, uint16_t bufsize)
{
    (void) report_type;

    uint32_t response_size = TU_MIN(CFG_TUD_HID_EP_BUFSIZE, bufsize);
    DAP_ExecuteCommand(buffer, hid_tx_data_buf);
    tud_hid_n_report(itf, report_id, hid_tx_data_buf, response_size);
}

/* cdc task & callback. */

void cdc_task(void)
{
    if ( tud_cdc_n_connected(0))
    {
        if (uart_rx_available() && tud_cdc_n_write_available(0) > 0)
        {
            uint8_t rx_buf[64];
            uint32_t rx_cnt = uart_rx(rx_buf, tud_cdc_n_write_available(0));
            tud_cdc_n_write(0, rx_buf, rx_cnt);
            tud_cdc_n_write_flush(0);
        }
        if (uart_tx_idle() && tud_cdc_n_available(0) > 0)
        {
            char tx_buf[128] = "012345678\r\n";
            uint32_t tx_cnt = tud_cdc_n_read(0, tx_buf, sizeof(tx_buf));
            uart_tx((uint8_t*)tx_buf, tx_cnt);
        }
    }
}

/* Invoked when line coding is change via SET_LINE_CODING
 */
void tud_cdc_line_coding_cb(uint8_t itf, cdc_line_coding_t const* p_line_coding)
{
    uart_init(p_line_coding);
}

/* main.c - end */
