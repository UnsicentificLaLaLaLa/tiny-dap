/*
 * Copyright 2021 MindMotion Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#include "hal_syscfg.h"

#define SYSCFG_EXTICR_MASK(x)   ( (0x0Fu) << ( ( (uint32_t)(x) & 0x3u ) << 2u ) ) /* mask bit for clear exti line. */
#define SYSCFG_EXTICR(x, y)     ( (uint32_t)( (uint32_t)(x) << ( ( (uint32_t)(y) & 0x3u ) << 2u ) ) ) /* set the data for indicated exti port and line. */

void SYSCFG_SetBootMemMode(SYSCFG_BootMemMode_Type mode)
{
    SYSCFG->CFGR = ( SYSCFG->CFGR & ~ SYSCFG_CFGR_MEMMODE_MASK )
                 | SYSCFG_CFGR_MEMMODE(mode);
}

void SYSCFG_SetExtIntMux(SYSCFG_EXTIPort_Type port, SYSCFG_EXTILine_Type line)
{
    if ( line < SYSCFG_EXTILine_4)
    {
        SYSCFG->EXTICR1 = ( SYSCFG->EXTICR1 & ~SYSCFG_EXTICR_MASK(line) )
                        | ( SYSCFG_EXTICR(port, line) );
    }
    else if ( line < SYSCFG_EXTILine_8 )
    {
        SYSCFG->EXTICR2 = ( SYSCFG->EXTICR1 & ~ SYSCFG_EXTICR_MASK(line) )
                        | ( SYSCFG_EXTICR(port, line) );
    }
    else if ( line < SYSCFG_EXTILine_12 )
    {
        SYSCFG->EXTICR3 = ( SYSCFG->EXTICR1 & ~ SYSCFG_EXTICR_MASK(line) )
                        | ( SYSCFG_EXTICR(port, line) );
    }
    else
    {
        SYSCFG->EXTICR4 = ( SYSCFG->EXTICR1 & ~ SYSCFG_EXTICR_MASK(line) )
                        | ( SYSCFG_EXTICR(port, line) );
    }
}

void SYSCFG_SetI2C0PortMode(SYSCFG_I2CPortMode_Type mode)
{
    SYSCFG->PADHYS = ( SYSCFG->PADHYS & ~ SYSCFG_PADHYS_I2C1MODESEL_MASK )
                  | SYSCFG_PADHYS_I2C1MODESEL(mode);
}

/* EOF. */
