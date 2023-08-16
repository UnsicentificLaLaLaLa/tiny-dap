/*
 * Copyright 2021 MindMotion Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#ifndef __HAL_RCC_H__
#define __HAL_RCC_H__

#include "hal_common.h"

/*!
 * @addtogroup RCC
 * @{
 */

/*!
 * @addtogroup RCC_AHB1_PERIPH
 * @{
 */

#define RCC_AHB1_PERIPH_DMA1   (1u << 0u)  /*!< AHB1 peripheral DMA1 clock 0 bit. */
#define RCC_AHB1_PERIPH_SRAM   (1u << 2u)  /*!< AHB1 peripheral SRAM clock 2 bit. */
#define RCC_AHB1_PERIPH_FLASH  (1u << 4u)  /*!< AHB1 peripheral FLASH clock 4 bit. */
#define RCC_AHB1_PERIPH_CRC    (1u << 6u)  /*!< AHB1 peripheral CRC clock 6 bit. */
#define RCC_AHB1_PERIPH_GPIOA  (1u << 17u) /*!< AHB1 peripheral GPIOA clock 17 bit. */
#define RCC_AHB1_PERIPH_GPIOB  (1u << 18u) /*!< AHB1 peripheral GPIOB clock 18 bit. */
#define RCC_AHB1_PERIPH_GPIOC  (1u << 19u) /*!< AHB1 peripheral GPIOC clock 19 bit. */
#define RCC_AHB1_PERIPH_GPIOD  (1u << 20u) /*!< AHB1 peripheral GPIOD clock 20 bit. */
#define RCC_AHB1_PERIPH_USB    (1u << 24u) /*!< AHB1 peripheral USB clock 24 bit. */
#define RCC_AHB1_PERIPH_HWDIV  (1u << 26u) /*!< AHB1 peripheral DIV clock 26 bit. */
/*!
 * @}
 */

/*!
 * @addtogroup RCC_APB1_PERIPH
 * @{
 */
#define RCC_APB1_PERIPH_TIM2    (1u << 0u) /*!< APB1 peripheral TIM2 clock 0 bit. */
#define RCC_APB1_PERIPH_TIM3    (1u << 1u) /*!< APB1 peripheral TIM3 clock 1 bit. */
#define RCC_APB1_PERIPH_I3C     (1u << 6u) /*!< APB1 peripheral I3C clock 6 bit. */
#define RCC_APB1_PERIPH_WWDG    (1u << 11u) /*!< APB1 peripheral WWDG clock 11 bit. */
#define RCC_APB1_PERIPH_SPI2    (1u << 14u) /*!< APB1 peripheral SPI2 clock 14 bit. */
#define RCC_APB1_PERIPH_UART2   (1u << 17u) /*!< APB1 peripheral UART2 clock 17 bit. */
#define RCC_APB1_PERIPH_UART3   (1u << 18u) /*!< APB1 peripheral UART3 clock 18 bit. */
#define RCC_APB1_PERIPH_UART4   (1u << 19u) /*!< APB1 peripheral UART4 clock 19 bit. */
#define RCC_APB1_PERIPH_I2C1    (1u << 21u) /*!< APB1 peripheral I2C1 clock 21 bit. */
#define RCC_APB1_PERIPH_BKP     (1u << 24u) /*!< APB1 peripheral BKP clock 24 bit. */
#define RCC_APB1_PERIPH_FLEXCAN (1u << 25u)/*!< APB1 peripheral CAN clock 25 bit. */
#define RCC_APB1_PERIPH_CRS     (1u << 27u) /*!< APB1 peripheral CRS clock 27 bit. */
#define RCC_APB1_PERIPH_PWR     (1u << 28u) /*!< APB1 peripheral PWR clock 28 bit. */
#define RCC_APB1_PERIPH_IWDG    (1u << 30u) /*!< APB1 peripheral UART7 clock 30 bit. */
#define RCC_APB1_PERIPH_RTC     (1u << 31u) /*!< APB1 peripheral RTC clock 31 bit. */

/*!
 * @}
 */

/*!
 * @addtogroup RCC_APB2_PERIPH
 * @{
 */
#define RCC_APB2_PERIPH_SYSCFG (1u << 0u)  /*!< APB2 peripheral SYSCFG clock 0 bit. */
#define RCC_APB2_PERIPH_ADC1   (1u << 9u)  /*!< APB2 peripheral ADC1 clock 9 bit. */
#define RCC_APB2_PERIPH_TIM1   (1u << 11u) /*!< APB2 peripheral TIM1 clock 11 bit. */
#define RCC_APB2_PERIPH_SPI1   (1u << 12u) /*!< APB2 peripheral SPI1 clock 12 bit. */
#define RCC_APB2_PERIPH_UART1  (1u << 14u) /*!< APB2 peripheral UART1 clock 14 bit. */
#define RCC_APB2_PERIPH_COMP   (1u << 15u) /*!< APB2 peripheral COMP clock 15 bit. */
#define RCC_APB2_PERIPH_TIM14  (1u << 16u) /*!< APB2 peripheral TIM14 clock 16 bit. */
#define RCC_APB2_PERIPH_TIM16  (1u << 17u) /*!< APB2 peripheral TIM16 clock 17 bit. */
#define RCC_APB2_PERIPH_TIM17  (1u << 18u) /*!< APB2 peripheral TIM17 clock 18 bit. */
#define RCC_APB2_PERIPH_DBG    (1u << 22u) /*!< APB2 peripheral DBG clock 22 bit. */
#define RCC_APB2_PERIPH_EXTI   (1u << 29u) /*!< APB2 peripheral EXTI clock 29 bit. */
#define RCC_APB2_PERIPH_LPTIM  (1u << 30u) /*!< APB2 peripheral LPTIM clock 30 bit. */
#define RCC_APB2_PERIPH_LPUART (1u << 31u) /*!< APB2 peripheral LPUART clock 31 bit. */
/*!
 * @}
 */

/*!
 * @brief Define the clock source for MCO output.
 */
typedef enum
{
    RCC_MCO_NoClock     = 0u, /*!< MCO NoClock 0 bits. */
    RCC_MCO_LSI         = 2u, /*!< MCO LSI 2 bits. */
    RCC_MCO_LSE         = 3u, /*! MCO LSE 3 bits. */
    RCC_MCO_SYSCLK      = 4u, /*!< MCO SYSCLK 4 bits. */
    RCC_MCO_HSI         = 5u, /*!< MCO HSI 5 bits. */
    RCC_MCO_HSE         = 6u, /*!< MCO HSE 6 bits. */
    RCC_MCO_PLLCLK_Div2 = 7u, /*!< MCO PLLCLK divided by 2 7 bits. */
} RCC_MCO_Type;

/*!
 * @brief Define the register reset status.
 */
typedef enum
{
    RCC_ResetStatus_LPWR       = 31u, /*!< Low Power Reset Flag. */
    RCC_ResetStatus_WWDG       = 30u, /*!< Window Watchdog Reset Flag. */
    RCC_ResetStatus_IWDG       = 29u, /*!< Independent Watchdog Reset Flag. */
    RCC_ResetStatus_SW         = 28u, /*!< Software Reset Flag. */
    RCC_ResetStatus_POR        = 27u, /*!< POR/PDR Reset Flag. */
    RCC_ResetStatus_PIN        = 26u, /*!< PIN Reset Flag. */
    RCC_ResetStatus_CPULOCKUP  = 23u, /*!< CPU Lockup Reset Flag. */
    RCC_ResetStatus_PVD        = 22u, /*!< PVD Reset Flag. */
    RCC_ResetStatus_LSIREADY   = 1u, /*!< LSI Ready. */
}ResetStatus_Type;

/*!
 * @brief Enable the RCC AHB1 periphs clock module.
 *
 * @param ahb1_periphs AHB1 Peripheral instance.
 * @param enable 'true' to enable the AHB1Periphs, 'false' to disable the AHB1Periphs.
 * @return None.
 */
void RCC_EnableAHB1Periphs(uint32_t ahb1_periphs, bool enable);

/*!
 * @brief Reset the RCC AHB1 periphs clock module.
 *
 * @param ahb1_periphs AHB1 Peripheral instance.
 * @return None.
 */
void RCC_ResetAHB1Periphs(uint32_t ahb1_periphs);

/*!
 * @brief Enable the RCC APB1 periphs clock module.
 *
 * @param apb1_periphs APB1 Peripheral instance.
 * @param enable 'true' to enable the APB1Periphs, 'false' to disable the APB1Periphs.
 * @return None.
 */
void RCC_EnableAPB1Periphs(uint32_t apb1_periphs, bool enable);

/*!
 * @brief Reset the RCC APB1 periphs clock module.
 *
 * @param apb1_periphs APB1 Peripheral instance.
 * @return None.
 */
void RCC_ResetAPB1Periphs(uint32_t apb1_periphs);

/*!
 * @brief Enable the RCC APB2 periphs clock module.
 *
 * @param apb2_periphs APB1 Peripheral instance.
 * @param enable 'true' to enable the APB2Periphs, 'false' to disable the APB2Periphs.
 * @return None.
 */
void RCC_EnableAPB2Periphs(uint32_t apb2_periphs, bool enable);

/*!
 * @brief Reset the RCC APB2 periphs clock module.
 *
 * @param apb2_periphs APB2 Peripheral instance.
 * @return None.
 */
void RCC_ResetAPB2Periphs(uint32_t apb2_periphs);

/*!
 * @brief MCO  Configuration clock source.
 *
 * @param source The clock source for MCO Configuration.
 * @return None.
 */
void RCC_MCOConf(RCC_MCO_Type source);

/*!
 * @brief Enable BKP write Protect.
 *
 * @param enable 'true' to can not allow writting BKP & RTC ,'false' to allow writting BKP & RTC .
 * @return None.
 */
void RCC_EnableBKPWriteProtect(bool enable);

/*!
 * @brief Enable BKP reset.
 *
 * @param enable 'true' to reset BKP ,'false' to not reset.
 * @return None.
 */
void RCC_EnableBKPReset(bool enable);

/*!
 * @brief Enable RTC clock.
 *
 * @param enable 'true' to enable RTC cloxk ,'false' to disable.
 * @return None.
 */
void RCC_EnableRTCClock(bool enable);

/*!
 * @brief Set RTC clock source.
 *
 * @param source the RTC clock source.
 * @return None.
 */
void RCC_SetRTCClockSource(uint32_t source);

/*!
 * @brief Enable LSE Bypass Mode.
 *
 * @param enable 'true' to enable LSE Bypass Mode ,'false' to disable.
 * @return None.
 */
void RCC_EnableLSEBypassMode(bool enable);

/*!
 * @brief Get LSE Oscillator Ready.
 *
 * @param None.
 * @return Ready Status.
 */
uint32_t GetLSEReadyStatus(void);

/*!
 * @brief Enable LSE oscillator clock.
 *
 * @param enable 'true' to enable LSE oscillator clock ,'false' to disable.
 * @return None.
 */
void RCC_EnableLSEClock(bool enable);

/*!
 * @brief Get Reset Status.
 *
 * @param status the reset status ,see to @ref ResetStatus_Type.
 * @return the reset status.
 */
uint32_t GetResetStatus(ResetStatus_Type status );

/*!
 * @brief Clear all Reset Status.
 *
 * @param None.
 * @return None.
 */
void ClearResetStatus(void);

/*!
 *@}
 */

#endif /* __HAL_RCC_H__ */
