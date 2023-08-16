/*
 * Copyright 2022 MindMotion Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __HAL_PWR_H__
#define __HAL_PWR_H__

#include "hal_common.h"

/*!
 * @addtogroup PWR
 * @{
 */

/*!
 * @brief PWR driver version number.
 */
#define PWR_DRIVER_VERSION 2u /*!< PWR_2. */

/*!
 * @addtogroup PWR_WAKEUP_PIN
 * @{
 */
#define PWR_WAKEUP_PIN_1  (1u << 0u) /*!< Wake up pin 1 selected. */
#define PWR_WAKEUP_PIN_2  (1u << 1u) /*!< Wake up pin 2 selected. */
#define PWR_WAKEUP_PIN_4  (1u << 3u) /*!< Wake up pin 4 selected. */
#define PWR_WAKEUP_PIN_5  (1u << 4u) /*!< Wake up pin 5 selected. */
#define PWR_WAKEUP_PIN_6  (1u << 5u) /*!< Wake up pin 6 selected. */
/*!
 * @}
 */

/*!
 * @addtogroup PWR_STATUS
 * @{
 */
#define PWR_STATUS_WAKEUP_PIN_1  (1u << 0u) /*!< Wake up pin 1 flag. */
#define PWR_STATUS_WAKEUP_PIN_2  (1u << 1u) /*!< Wake up pin 2 flag. */
#define PWR_STATUS_WAKEUP_PIN_4  (1u << 3u) /*!< Wake up pin 4 flag. */
#define PWR_STATUS_WAKEUP_PIN_5  (1u << 4u) /*!< Wake up pin 5 flag. */
#define PWR_STATUS_WAKEUP_PIN_6  (1u << 5u) /*!< Wake up pin 6 flag. */

/*!
 * @}
 */

/*!
 * @brief PWR standby wake up delay type.
 */
typedef enum
{
    PWR_StandbyWakeUpDelay_9 = 0u, /*!< Delay 9 LSI period to wakeup stanby. */
    PWR_StandbyWakeUpDelay_7 = 1u, /*!< Delay 7 LSI period to wakeup stanby. */
    PWR_StandbyWakeUpDelay_5 = 2u, /*!< Delay 5 LSI period to wakeup stanby. */
    PWR_StandbyWakeUpDelay_2 = 3u, /*!< Delay 2 LSI period to wakeup stanby. */
} PWR_StandbyWakeUpDelay_Type;

/*!
 * @brief PWR wake up pin trigger input type.
 */
typedef enum
{
    PWR_WakeUpPinTriggerIn_RisingEdge  = 0u, /*!< Enable the wake up pin rising edge trigger. */
    PWR_WakeUpPinTriggerIn_FallingEdge = 1u, /*!< Enable the wake up pin falling edge trigger. */
} PWR_WakeUpPinTriggerIn_Type;

/*!
 * @brief This type of structure instance is used to keep setting when calling.
 * Only standby mode and shutdown mode wake up pin.
 */
typedef struct
{
    uint32_t Pins; /*!< Specify wake up pins. See to @ref PWR_WAKEUP_PIN. */
    PWR_WakeUpPinTriggerIn_Type TrgIn; /*!< @ref Specify wake up pin trigger input type. See to @ref PWR_WakeUpPinTriggerIn_Type. */
} PWR_WakeUpPinConf_Type;

/*!
 * @brief Enter stop mode.
 *
 * @param PWRx PWR instance.
 * @param deep_stop 'true' to enable the deep stop mode, 'false' to disable the deep stop mode.
 * @return None.
 */
void PWR_EnterStopMode(PWR_Type * PWRx, bool deep_stop);

/*!
 * @brief Enable wake up pin.
 *
 * @param PWRx PWR instance.
 * @param init Pointer to the initialization structure. See to @ref PWR_WakeUpPinConf_Type.
 * @return None.
 */
void PWR_EnableWakeUpPin(PWR_Type * PWRx, PWR_WakeUpPinConf_Type * conf);

/*!
 * @brief Enter standby mode.
 *
 * @param PWRx PWR instance.
 * @param Delay Specify standby mode wake up delay value. See to @ref PWR_StandbyWakeUpDelay_Type.
 * @return None.
 */
void PWR_EnterStandbyMode(PWR_Type * PWRx, PWR_StandbyWakeUpDelay_Type delay);

/*!
 * @brief Get the current status flags of PWR module.
 *
 * @param PWRx PWR instance.
 * @return PWR status flags. See to @ref PWR_STATUS.
 */
uint32_t PWR_GetStatus(PWR_Type * PWRx);

/*!
 * @brief Clear PWR status flags.
 *
 * @param PWRx PWR instance.
 * @param flags PWR status flags. See to @ref PWR_STATUS.
 * @return None.
 */
void PWR_ClearStatus(PWR_Type * PWRx, uint32_t flags);

/*!
 *@}
 */

#endif /* __HAL_PWR_H__ */
