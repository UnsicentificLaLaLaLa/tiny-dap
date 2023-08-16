/*
 * Copyright 2022 MindMotion Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __HAL_HWDIV_H__
#define __HAL_HWDIV_H__

#include "hal_common.h"

/*!
 * @addtogroup HWDIV
 * @{
 */

/*!
 * @brief Initialize the HWDIV module.
 *
 * @param HWDIVx HWDIV instance.
 * @param enable 'true' to enable the USIGN, 'false' to disable the USIGN.
 * @return None.
 */
void HWDIV_EnableUsignBit(HWDIV_Type * HWDIVx, bool isUSIGN);

/*!
 * @brief Enable OVFE Bit.
 *
 * @param HWDIVx HWDIV instance.
 * @param enable 'true' to enable the OVFE, 'false' to disable the OVFE.
 * @return None.
 */
void HWDIV_EnableInterrupt(HWDIV_Type * HWDIVx, bool enable);

/*!
 * @brief Get OVF Bit.
 *
 * @param HWDIVx HWDIV instance.
 * @return 'false' is 0,'true' is 1.
 */
bool HWDIV_GetOVFBit(HWDIV_Type * HWDIVx);

/*!
 * @brief Clear OVF Bit.
 *
 * @param HWDIVx HWDIV instance.
 * @return None.
 */
void HWDIV_ClearOVFBit(HWDIV_Type * HWDIVx);

/*!
 * @brief Get USIGN Bit.
 *
 * @param HWDIVx HWDIV instance.
 * @return 'false' is a signed operation and 'true' is an unsigned operation.
 */
bool HWDIV_GetUsignBit(HWDIV_Type * HWDIVx);

/*!
 * @brief Signed number calculation.
 *
 * @param HWDIVx HWDIV instance.
 * @param dvdr dividend.
 * @param dvsr divisor.
 * @return The quotient of the calculated result.
 */
int32_t HWDIV_CalcSign(HWDIV_Type * HWDIVx,int32_t dvdr,int32_t dvsr);

/*!
 * @brief Get the signed  remainder.
 *
 * @param HWDIVx HWDIV instance.
 * @return RMDR.
 */
int32_t HWDIV_GetRMDRBitsSign(HWDIV_Type * HWDIVx);

/*!
 * @brief Unsigned number calculation.
 *
 * @param HWDIVx HWDIV instance.
 * @param dvdr dividend.
 * @param dvsr divisor.
 * @return The quotient of the calculated result.
 */
uint32_t HWDIV_CalcUsign(HWDIV_Type * HWDIVx,uint32_t dvdr,uint32_t dvsr);

/*!
 * @brief Get the unsigned  remainder.
 *
 * @param HWDIVx HWDIV instance.
 * @return RMDR.
 */
uint32_t HWDIV_GetRMDRBitsUsign(HWDIV_Type * HWDIVx);

#endif /*__HAL_HWDIV_H__*/
