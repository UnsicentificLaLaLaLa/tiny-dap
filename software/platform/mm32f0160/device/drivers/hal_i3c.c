/*
 * Copyright 2022 MindMotion Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "hal_i3c.h"

#define FREQ_1MHZ   1000000
#define FREQ_20MHZ  20000000

/* init. */
void I3C_InitSlave(I3C_Type * I3Cx, I3C_Slave_Init_Type * init)
{
    if (NULL == init) /*  invalid input. */
    {
        return;
    }

    /* calc clock div. */
    I3Cx->DIV = init->ClockFreqHz / FREQ_1MHZ; /* the cycle of CLOCK_SLOW is 1us(1MHz). */
    I3Cx->CONFIG = (I3Cx->CONFIG & ~I3C_CONFIG_BAMAT_MASK) | I3C_CONFIG_BAMAT(1);

    /* calc spike filter. */
    I3Cx->SPKLEN = I3C_SPKLEN_FLTEN_MASK | I3C_SPKLEN_SPKLEN(init->ClockFreqHz / FREQ_20MHZ); /* 50ns(20MHz) filter. */

    /* set static addr. */
    I3Cx->CONFIG = (I3Cx->CONFIG & ~I3C_CONFIG_SADDR_MASK) | I3C_CONFIG_SADDR(init->StaticAddr);
}

/* enable. */
void I3C_Enable(I3C_Type * I3Cx, bool enable)
{
    if (enable)
    {
        I3Cx->CONFIG |= I3C_CONFIG_SLVENA_MASK;
    }
    else
    {
        I3Cx->CONFIG &= ~I3C_CONFIG_SLVENA_MASK;
    }
}

/* status. */
uint32_t I3C_GetStatus(I3C_Type * I3Cx)
{
    return I3Cx->STATUS;
}

/* clear status. */
void I3C_ClearStatus (I3C_Type * I3Cx, uint32_t status)
{
    I3Cx->STATUS |= status;
}

/* get err status. */
uint32_t I3C_GetErrStatus(I3C_Type * I3Cx)
{
    return I3Cx->ERWAR;
}

/* put data. */
void I3C_PutData(I3C_Type * I3Cx, uint8_t data, bool is_last)
{
    if (is_last)
    {
        I3Cx->WDATABE = data;
    }
    else
    {
        I3Cx->WDATAB1 = data;
    }
}

/* get data. */
uint8_t I3C_GetData(I3C_Type * I3Cx)
{
    return I3Cx->RDATAB;
}

/* reset tx fifo. */
void I3C_ResetTxFIFO(I3C_Type * I3Cx)
{
    I3Cx->DATACTRL |= I3C_DATACTRL_FLUSHTB_MASK;
}

/* reset rx fifo. */
void I3C_ResetRxFIFO(I3C_Type * I3Cx)
{
    I3Cx->DATACTRL |= I3C_DATACTRL_FLUSHFB_MASK;
}

/* interrupt. */
void I3C_EnableInterrupts    (I3C_Type * I3Cx, uint32_t interrupts, bool enable)
{
    if (enable)
    {
        I3Cx->INTSET |= interrupts;
    }
    else
    {
        I3Cx->INTCLR |= interrupts;
    }
}

uint32_t I3C_GetEnabledInterrupts(I3C_Type * I3Cx)
{
    return I3Cx->INTSET;
}

/* enable tx dma. */
void I3C_EnableTxDMA(I3C_Type * I3Cx, bool enable)
{
    if (enable)
    {
        I3Cx->DMACTRL |=  I3C_DMACTRL_DMATB_MASK;
    }
    else
    {
        I3Cx->DMACTRL &= ~I3C_DMACTRL_DMATB_MASK;
    }
}

/* enable rx dma. */
void I3C_EnableRxDMA(I3C_Type * I3Cx, bool enable)
{
    if (enable)
    {
        I3Cx->DMACTRL |=  I3C_DMACTRL_DMAFB_MASK;
    }
    else
    {
        I3Cx->DMACTRL &= ~I3C_DMACTRL_DMAFB_MASK;
    }
}

/* get rx addr. */
uint32_t I3C_GetRxDataRegAddr(I3C_Type * I3Cx)
{
    return (uint32_t)(&(I3Cx->RDATAB));
}

/* get tx addr. */
uint32_t I3C_GetTxDataRegAddr(I3C_Type * I3Cx)
{
    return (uint32_t)(&(I3Cx->WDATAB1));
}

/* EOF. */
