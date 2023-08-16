/*
 * Copyright 2022 MindMotion Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __HAL_CRC_H__
#define __HAL_CRC_H__

#include "hal_common.h"

/*!
 * @addtogroup CRC
 * @{
 */

/*!
 * @brief The data endian is little-endian or big-endian.
 */
typedef enum
{
    CRC_DataEndian_LittleEndian = 0u,  /*!< Specofy the data endian is little-endian. */
    CRC_DataEndian_BigEndian = 1u,     /*!< Specofy the data endian is big-endian. */
} CRC_DataEndian_Type;

/*!
 * @brief CRC data width type.
 */
typedef enum
{
    CRC_Width_32b = 0u,  /*!< Data size is 32 bits. */
    CRC_Width_16b = 1u,  /*!< Data size is 16 bits. */
    CRC_Width_8b = 2u,   /*!< Data size is 8 bits. */
} CRC_Width_Type;

/*!
 * @brief CRC algorithm type.
 */
typedef enum
{
    CRC_Algorithm_MPEG2 = 0u,   /*!< Select CRC algorithm: CRC-32. */
    CRC_Algorithm_CRC32 = 1u,   /*!< Select CRC algorithm: CRC-32/MPEG-2. */
} CRC_Algorithm_Type;

/*!
 * @brief This type of structure instance is used to keep the settings when calling the @ref CRC_Init() to initialize the CRC module.
 */
typedef struct
{
    CRC_DataEndian_Type       InEndian;         /*!< Specify input endian is little-endian or big-endian. */
    CRC_DataEndian_Type       OutEndian;        /*!< Specify output endian is little-endian or big-ndian. */
    CRC_Width_Type            Width;            /*!< Specify input data size. */
    CRC_Algorithm_Type        Algorithm;        /*!< Specify CRC algorithm. */
} CRC_Init_Type;

/*!
 * @brief Initialize the CRC module.
 *
 * @param CRCx CRC instance.
 * @param init Pointer to the initialization structure. See to @ref CRC_Init_Type.
 * @return None.
 */
void CRC_Init(CRC_Type * CRCx, CRC_Init_Type * init);

/*!
 * @brief Set data for CRC calculation.
 *
 * @param CRCx CRC instance.
 * @param val The value used for CRC calculation.
 * @return None.
 */
void CRC_SetData(CRC_Type * CRCx, uint32_t val);

/*!
 * @brief Get the most recent result of CRC calculation.
 *
 * @param CRCx CRC instance.
 * @return Return the most recent result of CRC calculation.
 */
uint32_t CRC_GetResult(CRC_Type * CRCx);

/*!
 * @brief Reset CRC data.
 *
 * @param CRCx CRC instance.
 * @return None.
 */
void CRC_Reset(CRC_Type * CRCx);

/*!
 * @brief Set middle data register.
 *
 * @param CRCx CRC instance.
 * @param val CRC middle calculation result.
 * @return None.
 */
void CRC_SetMIR(CRC_Type * CRCx, uint32_t val);

/*!
 * @brief Get middle data.
 *
 * @param CRCx CRC instance.
 * @return CRC middle calculation result.
 */
uint32_t CRC_GetMIR(CRC_Type * CRCx);

/*!
 * @brief Temporarily store 1 byte.
 *
 * @param CRCx CRC instance.
 * @param val Temporarily store 1 byte data.
 * @return None.
 */
void CRC_SetIDR(CRC_Type * CRCx, uint32_t val);

/*!
 * @brief Get Temporarily store 1 byte.
 *
 * @param CRCx CRC instance.
 * @return Temporarily store 1 byte data.
 */
uint32_t CRC_GetIDR(CRC_Type * CRCx);

/*!
 *@}
 */
 
#endif /*__HAL_CRC_H__. */

