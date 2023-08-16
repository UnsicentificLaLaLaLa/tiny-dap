/*
 * Copyright 2022 MindMotion Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __HAL_BKP_H__
#define __HAL_BKP_H__

#include "hal_common.h"

/*!
 * @addtogroup BKP
 * @{
 */

/*!
 * @addtogroup BKP_STATUS
 * @{
 */
#define BKP_STATUS_TAMP  BKP_CSR_TEF_MASK   /*!< An intrusion event occurred. */
/*!
 * @}
 */

/*!
 * @addtogroup BKP_INT
 * @{
 */
#define BKP_INT_TAMP     BKP_CSR_TPIE_MASK  /*!< An interrupt intrusion event occurred. */
/*!
 * @}
 */

/*!
 * @brief BKP tamper active level type.
 */
typedef enum
{
    BKP_TamperActLevel_High = 0u,  /*!< Detecting the high level on the tamp pin will clear all data in the backup register. */
    BKP_TamperActLevel_Low = 1u,   /*!< Detecting the low level on the tamp pin will clear all data in the backup register. */
} BKP_TamperActLevel_Type;

/*!
 * @brief This type of structure instance is used to keep the settings when calling the @ref BKP_EnableTamperConf() to config BKP tamper.
 */
typedef struct
{
    BKP_TamperActLevel_Type   TamperLevel;  /*!< Specify BKP tamper pin active level. */
} BKP_Tamper_Type;

/*!
 * @brief Get the data from backup register.
 *
 * @param BKPx BKP instance.
 * @param idx The index number of backup register area.
 * @return The data of backup register.
 */
uint32_t BKP_GetData(BKP_Type * BKPx, uint8_t idx);

/*!
 * @brief Set the data into backup register.
 *
 * @param BKPx BKP instance.
 * @param idx The index number of backup register.
 * @param val Data value to be put in backup register.
 * @return None.
 */
void BKP_SetData(BKP_Type * BKPx, uint8_t idx, uint32_t val);

/*!
 * @brief Configurate BKP tamper.
 *
 * @param BKPx BKP instance.
 * @param conf Pointer to the tamper config structure.
 * @return None.
 */
void BKP_EnableTamperConf(BKP_Type * BKPx, BKP_Tamper_Type * conf);

/*!
 * @brief Enable interrupts of the BKP.
 *
 * @param BKPx BKP instance.
 * @param interrupts Interrupt code masks. See to @ref BKP_INT.
 * @param enable 'true' to enable the indicated interrupts, 'false' to disable the indicated interrupts.
 * @return None.
 */
void BKP_EnableInterrupts(BKP_Type * BKPx, uint32_t interrupts, bool enable);

/*!
 * @brief Get the current status flags of the BKP module.
 *
 * @param BKPx BKP instance.
 * @return Status flags. See to @ref BKP_STATUS.
 */
uint32_t BKP_GetStatus(BKP_Type * BKPx);

/*!
 * @brief Clear the status flags of the BKP module.
 *
 * @param BKPx BKP instance.
 * @param status The mask codes of the indicated status flags to be cleared.
 * @return None.
 */
void BKP_ClearStatus(BKP_Type * BKPx, uint32_t status);

/*!
 *@}
 */

#endif /*__HAL_BKP_H__. */

