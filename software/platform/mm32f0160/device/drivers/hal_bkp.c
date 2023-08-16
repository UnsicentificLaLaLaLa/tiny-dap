/*
 * Copyright 2022 MindMotion Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "hal_bkp.h"

/* Get the data from backup register. */
uint32_t BKP_GetData(BKP_Type * BKPx, uint8_t idx)
{
    return BKPx->DR[idx];
}

/* Set data to backup register. */
void BKP_SetData(BKP_Type * BKPx, uint8_t idx, uint32_t val)
{
    BKPx->DR[idx] = (uint16_t)val;
}

/* Configurate BKP tamper. */
void BKP_EnableTamperConf(BKP_Type * BKPx, BKP_Tamper_Type * conf)
{
    BKPx->CR &= ~BKP_CR_TPAL_MASK;
    if (conf == NULL)
    {
        /* Disable the tamper detection. */
        BKPx->CR &= ~BKP_CR_TPE_MASK;
        return;
    }
    else
    {
        /* Enable the tamper detection. */
        BKPx->CR |= (BKP_CR_TPE_MASK | BKP_CR_TPAL(conf->TamperLevel));
    }
}

/* Enable BKP interrupts. */
void BKP_EnableInterrupts(BKP_Type * BKPx, uint32_t interrupts, bool enable)
{
    if (true == enable)
    {
        BKPx->CSR |= interrupts;
    }
    else
    {
        BKPx->CSR &= ~interrupts;
    }
}

/* Get BKP status. */
uint32_t BKP_GetStatus(BKP_Type * BKPx)
{
    uint32_t temp = 0u;
    if (0u != (BKPx->CSR & BKP_CSR_TEF_MASK) )
    {
        temp |= BKP_STATUS_TAMP;
    }
    if (0u != (BKPx->CSR & BKP_CSR_TIF_MASK) )
    {
        temp |= BKP_INT_TAMP;
    }
    return temp;
}

/* Clear BKP flags. */
void BKP_ClearStatus(BKP_Type * BKPx, uint32_t status)
{
    if ( 0u != (status & BKP_STATUS_TAMP) )
    {
        BKPx->CSR |= BKP_CSR_CTE_MASK;
    }
    if ( 0u != (status & BKP_INT_TAMP) )
    {
        BKPx->CSR |= BKP_CSR_CTI_MASK;
    }
}

/* EOF. */
