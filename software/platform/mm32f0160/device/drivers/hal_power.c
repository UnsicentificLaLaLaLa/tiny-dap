/*
 * Copyright 2022 MindMotion Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "hal_power.h"

void CORE_EnterSleepMode(bool sleep_on_exit, bool sleep_deep, POWER_WakeUp_Type mode)
{
    if (sleep_on_exit)
    {
        SCB->SCR |= SCB_SCR_SLEEPONEXIT_Msk;
    }
    else
    {
        SCB->SCR &= ~SCB_SCR_SLEEPONEXIT_Msk;
    }

    if (sleep_deep)
    {
        SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    }
    else
    {
        SCB->SCR &= ~SCB_SCR_SLEEPDEEP_Msk;
    }

    if (mode ==  POWER_WakeUp_Interrupt)
    {
        __WFI();
    }
    if (mode == POWER_WakeUp_Event)
    {
        __WFE();
    }
}

void POWER_EnterSleepMode(POWER_SleepConf_Type * conf)
{
    CORE_EnterSleepMode(conf->SleepOnExit, false, conf->WakeUpMode);
}

void POWER_EnterStopMode(POWER_StopConf_Type * conf)
{
    PWR_EnterStopMode(PWR, conf->DeepStop);

    CORE_EnterSleepMode(false, true, conf->WakeUpMode);
}

void POWER_EnableWakeUpPin(PWR_WakeUpPinConf_Type * conf)
{
    PWR_EnableWakeUpPin(PWR, conf);
}

void POWER_EnterStandbyMode(POWER_StandbyConf_Type * conf)
{
    PWR_EnterStandbyMode(PWR, conf->Delay);

    CORE_EnterSleepMode(false, true, conf->WakeUpMode);
}

void POWER_SelectMode(POWER_Mode_Type mode, void * conf)
{
    switch (mode)
    {
        case POWER_Mode_Sleep:
            POWER_EnterSleepMode( (POWER_SleepConf_Type *) conf);
            break;
        case POWER_Mode_Stop:
            POWER_EnterStopMode( (POWER_StopConf_Type *) conf);
            break;
        case POWER_Mode_DeepStop:
            POWER_EnterStopMode( (POWER_StopConf_Type *) conf);
            break;
        case POWER_Mode_Standby:
            POWER_EnterStandbyMode( (POWER_StandbyConf_Type *) conf);
            break;
        default:
            break;
    }
}

/* EOF. */
