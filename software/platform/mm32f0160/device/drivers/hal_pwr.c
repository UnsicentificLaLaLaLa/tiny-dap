/*
 * Copyright 2022 MindMotion Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "hal_pwr.h"

void PWR_EnterStopMode(PWR_Type * PWRx, bool deep_stop)
{
    PWRx->CR &= ~PWR_CR_PDDS_MASK;
    
    if (deep_stop)
    {
        PWRx->CR |= PWR_CR_LPDS_MASK;
    }
    else
    {
        PWRx->CR &= ~PWR_CR_LPDS_MASK;
    }
}

void PWR_EnableWakeUpPin(PWR_Type * PWRx,  PWR_WakeUpPinConf_Type * conf)
{
    if (NULL != conf)
    {
        switch(conf->Pins)
        {
            case PWR_WAKEUP_PIN_1:
                PWRx->CSR |= PWR_CSR_EWUP1_MASK;
                break;
            case PWR_WAKEUP_PIN_2:
                PWRx->CSR |= PWR_CSR_EWUP2_MASK;
                break;
            case PWR_WAKEUP_PIN_4:
                PWRx->CSR |= PWR_CSR_EWUP4_MASK;
                break;
            case PWR_WAKEUP_PIN_5:
                PWRx->CSR |= PWR_CSR_EWUP5_MASK;
                break;
            case PWR_WAKEUP_PIN_6:
                PWRx->CSR |= PWR_CSR_EWUP6_MASK;
                break;
        }
        
        if (conf->TrgIn == PWR_WakeUpPinTriggerIn_FallingEdge)
        {
            PWRx->CR1 |= conf->Pins;
        }
        if (conf->TrgIn == PWR_WakeUpPinTriggerIn_RisingEdge)
        {
            PWRx->CR1 &= ~conf->Pins;
        }
    }
    else
    {
        PWRx->CSR &= ~( PWR_CSR_EWUP1_MASK | PWR_CSR_EWUP2_MASK | PWR_CSR_EWUP4_MASK |
                        PWR_CSR_EWUP5_MASK | PWR_CSR_EWUP6_MASK );
    }
}

void PWR_EnterStandbyMode(PWR_Type * PWRx, PWR_StandbyWakeUpDelay_Type delay)
{
    PWRx->CR |= PWR_CR_PDDS_MASK;

    PWRx->SCR |= (   PWR_WAKEUP_PIN_1
                   | PWR_WAKEUP_PIN_2
                   | PWR_WAKEUP_PIN_4
                   | PWR_WAKEUP_PIN_5
                   | PWR_WAKEUP_PIN_6
                 );
    PWRx->CR |= PWR_CR_STDBYFSWK(delay);
}

uint32_t PWR_GetStatus(PWR_Type * PWRx)
{
    return PWRx->SR1;
}

void PWR_ClearStatus(PWR_Type * PWRx, uint32_t flags)
{
    PWRx->SCR &= ~ flags;
}

/* EOF. */
