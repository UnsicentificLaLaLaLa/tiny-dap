/*
 * Copyright 2021 MindMotion Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "hal_common.h"
#include "hal_rcc.h"

void RCC_EnableAHB1Periphs(uint32_t ahb1_periphs, bool enable)
{
    (enable) ? (RCC->AHBENR |= ahb1_periphs) : (RCC->AHBENR &= ~ahb1_periphs);
}

void RCC_EnableAPB1Periphs(uint32_t apb1_periphs, bool enable)
{
    (enable) ? (RCC->APB1ENR |= apb1_periphs) : (RCC->APB1ENR &= ~apb1_periphs);
}

void RCC_EnableAPB2Periphs(uint32_t apb2_periphs, bool enable)
{
    (enable) ? (RCC->APB2ENR |= apb2_periphs) : (RCC->APB2ENR &= ~apb2_periphs);
}

void RCC_ResetAHB1Periphs(uint32_t ahb1_periphs)
{
    RCC->AHBRSTR |= ahb1_periphs;
    RCC->AHBRSTR &= ~ahb1_periphs;
}

void RCC_ResetAPB1Periphs(uint32_t apb1_periphs)
{
    RCC->APB1RSTR |= apb1_periphs;
    RCC->APB1RSTR &= ~apb1_periphs;
}

void RCC_ResetAPB2Periphs(uint32_t apb2_periphs)
{
    RCC->APB2RSTR |= apb2_periphs;
    RCC->APB2RSTR &= ~apb2_periphs;
}

void RCC_MCOConf(RCC_MCO_Type source)
{
    RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_MCO_MASK) | RCC_CFGR_MCO(source);
}

void RCC_EnableBKPWriteProtect(bool enable)
{
    (enable) ? (RCC->BDCR &= ~RCC_BDCR_DBP_MASK) : (RCC->BDCR |= RCC_BDCR_DBP_MASK);
}

void RCC_EnableBKPReset(bool enable)
{
    (enable) ? (RCC->BDCR |= RCC_BDCR_BDRST_MASK) : (RCC->BDCR &= ~RCC_BDCR_BDRST_MASK);
}

void RCC_EnableRTCClock(bool enable)
{
    (enable) ? (RCC->BDCR |= RCC_BDCR_RTCEN_MASK) : (RCC->BDCR &= ~RCC_BDCR_RTCEN_MASK);
}

void RCC_SetRTCClockSource(uint32_t source)
{
    RCC->BDCR |= RCC_BDCR_RTCSEL(source);
}

void RCC_EnableLSEBypassMode(bool enable)
{
    (enable) ? (RCC->BDCR |= RCC_BDCR_LSEBYP_MASK) : (RCC->BDCR &= ~RCC_BDCR_LSEBYP_MASK);
}

uint32_t GetLSEReadyStatus(void)
{
    return (RCC->BDCR &= RCC_BDCR_LSERDY_MASK);
}

void RCC_EnableLSEClock(bool enable)
{
    (enable) ? (RCC->BDCR |= RCC_BDCR_LSEON_MASK) : (RCC->BDCR &= ~RCC_BDCR_LSEON_MASK);
}

uint32_t GetResetStatus(ResetStatus_Type status )
{
    return (RCC->CSR &= status);
}

void ClearResetStatus(void)
{
    RCC->CSR = RCC_CSR_RMVF_MASK;
}

/* EOF. */
