/*
 * Copyright 2022 MindMotion Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __HAL_POWER_H__
#define __HAL_POWER_H__

#include "hal_common.h"
#include "hal_pwr.h"

/*!
 * @brief POWER mode type.
 */
typedef enum
{
    POWER_Mode_Sleep         = 0u, /*!< Sleep mode selected. */
    POWER_Mode_Stop          = 1u, /*!< Stop mode selected. */
    POWER_Mode_DeepStop      = 2u, /*!< Deep stop mode selected. */
    POWER_Mode_Standby       = 3u, /*!< Standby mode selected. */
} POWER_Mode_Type;

/*!
 * @brief POWER wake up type.
 */
typedef enum
{
    POWER_WakeUp_Interrupt = 0u, /*!< Select the interrupt wake up. */
    POWER_WakeUp_Event     = 1u, /*!< Select the event wake up. */
} POWER_WakeUp_Type;

/*!
 * @brief POWER sleep mode parameter type.
 */
typedef struct
{
    bool SleepOnExit; /*!< 'true' to sleep after exit from ISR, 'false' to sleep immediately. */
    POWER_WakeUp_Type WakeUpMode; /*!< Specify wake up mode. See to @ref POWER_WakeUp_Type. */
} POWER_SleepConf_Type;

/*!
 * @brief POWER stop mode parameter type.
 */
typedef struct
{
    bool DeepStop; /*!< 'true' to enable the deep stop mode, 'false' to disable the deep stop mode. */
    POWER_WakeUp_Type WakeUpMode; /*!< Specify wake up mode. See to @ref POWER_WakeUp_Type. */
} POWER_StopConf_Type;

/*!
 * @brief POWER standby mode parameter type.
 */
typedef struct
{
    PWR_StandbyWakeUpDelay_Type Delay; /*!< Specify standby mode wake up delay value. See to @ref PWR_StanbyWakeUpDelay_Type. */
    POWER_WakeUp_Type WakeUpMode; /*!< Specify wake up mode. See to @ref POWER_WakeUp_Type. */
} POWER_StandbyConf_Type;

/*!
 * @brief Select power mode.
 *
 * @param mode power mode. See to @ref POWER_Mode_Type.
 * @param param Pointer to the initialization structure.
 * @return None.
 */
void POWER_SelectMode(POWER_Mode_Type mode, void * conf);

/*!
 * @brief Enter sleep mode.
 *
 * @param param Pointer to the initialization structure. See to @ref POWER_SleepConf_Type.
 * @return None.
 */
void POWER_EnterSleepMode(POWER_SleepConf_Type * conf);

/*!
 * @brief Enter stop mode.
 *
 * @param param Pointer to the initialization structure. See to @ref POWER_StopConf_Type.
 * @return None.
 */
void POWER_EnterStopMode(POWER_StopConf_Type * conf);

/*!
 * @brief Enable standby and shutdown wake up pin.
 *
 * @param PWRx PWR instance.
 * @param init Pointer to the initialization structure. See to @ref PWR_WakeUpPinConf_Type.
 * @return None.
 */
void POWER_EnableWakeUpPin(PWR_WakeUpPinConf_Type * conf);

/*!
 * @brief Enter standby mode.
 *
 * @param param Pointer to the initialization structure. See to @ref POWER_StandbyConf_Type.
 * @return None.
 */
void POWER_EnterStandbyMode(POWER_StandbyConf_Type * conf);

#endif /* __HAL_POWER_H__ */
