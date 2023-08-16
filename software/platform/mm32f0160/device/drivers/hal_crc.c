/*
 * Copyright 2022 MindMotion Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "hal_crc.h"

/* CRC initialization. */
void CRC_Init(CRC_Type * CRCx, CRC_Init_Type * init)
{
    CRCx->CR = CRC_CR_OES(init->OutEndian) | CRC_CR_IES(init->InEndian) | CRC_CR_ISIZE(init->Width) | CRC_CR_AS(init->Algorithm);
    CRCx->CR |= CRC_CR_RST_MASK;
}

/* Put data into CRC. */
void CRC_SetData(CRC_Type * CRCx, uint32_t val)
{
    CRCx->DR = val;
}

/* Get the result of CRC. */
uint32_t CRC_GetResult(CRC_Type * CRCx)
{
    return CRCx->DR;
}

/* Reset CRC data register and middle data register. */
void CRC_Reset(CRC_Type * CRCx)
{
    CRCx->CR |= CRC_CR_RST_MASK;
}

/* Put the data in the previous calculation back and continue the original CRC calculation. */
void CRC_SetMIR(CRC_Type * CRCx, uint32_t val)
{
    CRCx->MIR = val;
}

/* Get the middle data when a new array needs CRC calculation immediately. */
uint32_t CRC_GetMIR(CRC_Type * CRCx)
{
    return CRCx->MIR;
}

/* Temporarily store 1 byte of data. */
void CRC_SetIDR(CRC_Type * CRCx, uint32_t val)
{
    CRCx->IDR = (uint8_t)val;
}

/* Get 1 byte of stored data. */
uint32_t CRC_GetIDR(CRC_Type * CRCx)
{
    return CRCx->IDR;
}

/* EOF. */
