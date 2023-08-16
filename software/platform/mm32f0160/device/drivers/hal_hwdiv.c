/*
 * Copyright 2022 MindMotion Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "hal_hwdiv.h"

/* Enable unsigned division. */
void HWDIV_EnableUsignBit(HWDIV_Type * HWDIVx, bool isUSIGN)
{
    if(isUSIGN)
    {
        /* Unsigned division. */
        HWDIVx->CR |= HWDIV_CR_USIGN_MASK;
    }
    else
    {
        /* Signed division. */
        HWDIVx->CR &= (0xFFFFFFFFU & ~HWDIV_CR_USIGN_MASK);
    }
}

void HWDIV_EnableInterrupt(HWDIV_Type * HWDIVx, bool enable)
{
    if(enable)
    {
        HWDIVx->CR |= HWDIV_CR_OVFE_MASK;
    }
    else
    {
        HWDIVx->CR &= (0xFFFFFFFFU & ~HWDIV_CR_OVFE_MASK);
    }
}

bool HWDIV_GetOVFBit(HWDIV_Type * HWDIVx)
{
  if(HWDIVx->SR & HWDIV_SR_OVF_MASK)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void HWDIV_ClearOVFBit(HWDIV_Type * HWDIVx)
{
    HWDIVx->SR |= HWDIV_SR_OVF_MASK;
}

bool HWDIV_GetUsignBit(HWDIV_Type * HWDIVx)
{
    /* return the symbol type of the current division. */
    if(HWDIVx->CR & HWDIV_CR_USIGN_MASK)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* Count the signed number. */
int32_t HWDIV_CalcSign(HWDIV_Type * HWDIVx,int32_t dvdr,int32_t dvsr)
{
    HWDIVx->DVDR = dvdr;
    HWDIVx->DVSR = dvsr;

    if(HWDIVx->SR & HWDIV_SR_OVF_MASK)
    {
        return 0xFFFFFFFF;
    }
    else
    {
        return HWDIVx->QUOTR;
    }
}

/* Get the signed remainder. */
int32_t HWDIV_GetRMDRBitsSign(HWDIV_Type * HWDIVx)
{
    return (int32_t)HWDIVx->RMDR;
}

/* Count the unsigned number. */
uint32_t HWDIV_CalcUsign(HWDIV_Type * HWDIVx,uint32_t dvdr,uint32_t dvsr)
{
    HWDIVx->DVDR = dvdr;
    HWDIVx->DVSR = dvsr;

    if(HWDIVx->SR & HWDIV_SR_OVF_MASK)
    {
        return 0xFFFFFFFFU;
    }
    else
    {
        return HWDIVx->QUOTR;
    }
}

/* Get the unsigned remainder. */
uint32_t HWDIV_GetRMDRBitsUsign(HWDIV_Type * HWDIVx)
{
    return (uint32_t)HWDIVx->RMDR;
}

/* EOF. */
