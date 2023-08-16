/*
 * Copyright 2021 MindMotion Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#include "hal_device_registers.h"

void SystemInit(void)
{
    /* Switch to HSI. */
    RCC->CR |= RCC_CR_HSION_MASK; /* Make sure the HSI is enabled. */
    while ( RCC_CR_HSIRDY_MASK != (RCC->CR & RCC_CR_HSIRDY_MASK) )
    {
    }
    RCC->CFGR = RCC_CFGR_SW(0u); /* Reset other clock sources and switch to HSI/6. */
    while ( RCC_CFGR_SWS(0u) != (RCC->CFGR & RCC_CFGR_SWS_MASK) ) /* Wait while the SYSCLK is switch to the HSI. */
    {
    }

    /* Reset all other clock sources. */
    RCC->CR = RCC_CR_HSION_MASK;

    /* Disable all interrupts and clear pending bits. */
    RCC->CIR = RCC->CIR; /* clear flags. */
    RCC->CIR = 0u; /* disable interrupts. */

    RCC->APB1ENR |= (1u << 28u); /* enable PWR/DBG. */

    /* PLL */
    RCC->PLL1CFGR = RCC_PLL1CFGR_PLL1SRC(0) /* (pllsrc == 1) ? HSE : HSI. */
                 | RCC_PLL1CFGR_PLL1XTPRE(0) /* HSE 0 div*/
                 | RCC_PLL1CFGR_PLL1MUL(23) /* (8 * (23 + 1)) /2 = 96. */
                 | RCC_PLL1CFGR_PLL1DIV(1)
                 | RCC_PLL1CFGR_PLL1LDS(7)
                 | RCC_PLL1CFGR_PLL1ICTRL(3)
                 ;
    RCC->PLL2CFGR = RCC_PLL2CFGR_PLL2SRC(0) /* (pllsrc == 1) ? HSE : HSI. */
                 | RCC_PLL2CFGR_PLL2XTPRE(0) /* HSE 0 div*/
                 | RCC_PLL2CFGR_PLL2MUL(11) /* (8 * (11 + 1)) /2 = 48. */
                 | RCC_PLL2CFGR_PLL2DIV(1)
                 | RCC_PLL2CFGR_PLL2LDS(7)
                 | RCC_PLL2CFGR_PLL2ICTRL(3)
                 ;

    /* Enable PLL. */
    RCC->CR |= RCC_CR_PLL1ON_MASK;
    while((RCC->CR & RCC_CR_PLL1RDY_MASK) == 0)
    {
    }

    RCC->CR |= RCC_CR_PLL2ON_MASK;
    while((RCC->CR & RCC_CR_PLL2RDY_MASK) == 0)
    {
    }

    FLASH->ACR = FLASH_ACR_LATENCY(3u) /* setup divider. */
               | FLASH_ACR_PRFTBE_MASK /* enable flash prefetch. */
               ;

    /* Setup the dividers for each bus. */
    RCC->CFGR = RCC_CFGR_HPRE(0)        /* div=1 for AHB freq. */
              | RCC_CFGR_PPRE1(0x4)     /* div=2 for APB1 freq. */
              | RCC_CFGR_PPRE2(0x4)     /* div=2 for APB2 freq. */
              | RCC_CFGR_MCO(7)         /* use PLL1 as output. */
              | RCC_CFGR_USBPRE(0)      /* div = 1 for USB freq. */
              | RCC_CFGR_USBCLKSEL(1)   /* PLL2 for USB. */
              ;

    /* Switch the system clock source to PLL. */
    RCC->CFGR = (RCC->CFGR & ~RCC_CFGR_SW_MASK) | RCC_CFGR_SW(2); /* use PLL as SYSCLK */

    /* Wait till PLL is used as system clock source. */
    while ( (RCC->CFGR & RCC_CFGR_SWS_MASK) != RCC_CFGR_SWS(2) )
    {
    }
}

/* EOF. */
