/*
 * Copyright 2021 MindMotion Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#ifndef __HAL_SYSCFG_H__
#define __HAL_SYSCFG_H__

#include "hal_common.h"

/*!
 * @addtogroup SYSCFG
 * @{
 */

/*!
 * @brief Boot memory mapping mode.
 */
typedef enum
{
    SYSCFG_BootMemMode_Flash = 0u, /*!< SYSCFG Boot Memory Flash mode. */
    SYSCFG_BootMemMode_ROM   = 1u, /*!< SYSCFG Boot Memory ROM mode. */
    SYSCFG_BootMemMode_SRAM  = 3u, /*!< SYSCFG Boot Memory SRAM mode. */
} SYSCFG_BootMemMode_Type;

/*!
 * @brief External interrupt port.
 */
typedef enum
{
    SYSCFG_EXTIPort_GPIOA = (0x00U), /*!< SYSCFG External Interrupt GPIOA. */
    SYSCFG_EXTIPort_GPIOB = (0x01U), /*!< SYSCFG External Interrupt GPIOB. */
    SYSCFG_EXTIPort_GPIOC = (0x02U), /*!< SYSCFG External Interrupt GPIOC. */
    SYSCFG_EXTIPort_GPIOD = (0x03U), /*!< SYSCFG External Interrupt GPIOD. */
} SYSCFG_EXTIPort_Type;

/*!
 * @brief External interrupt line.
 */
typedef enum
{
    SYSCFG_EXTILine_0  =  (0x00U),  /*!< Pin 0 selected.    */
    SYSCFG_EXTILine_1  =  (0x01U),  /*!< Pin 1 selected.    */
    SYSCFG_EXTILine_2  =  (0x02U),  /*!< Pin 2 selected.    */
    SYSCFG_EXTILine_3  =  (0x03U),  /*!< Pin 3 selected.    */
    SYSCFG_EXTILine_4  =  (0x04U),  /*!< Pin 4 selected.    */
    SYSCFG_EXTILine_5  =  (0x05U),  /*!< Pin 5 selected.    */
    SYSCFG_EXTILine_6  =  (0x06U),  /*!< Pin 6 selected.    */
    SYSCFG_EXTILine_7  =  (0x07U),  /*!< Pin 7 selected.    */
    SYSCFG_EXTILine_8  =  (0x08U),  /*!< Pin 8 selected.    */
    SYSCFG_EXTILine_9  =  (0x09U),  /*!< Pin 9 selected.    */
    SYSCFG_EXTILine_10 =  (0x0AU),  /*!< Pin 10 selected.   */
    SYSCFG_EXTILine_11 =  (0x0BU),  /*!< Pin 11 selected.   */
    SYSCFG_EXTILine_12 =  (0x0CU),  /*!< Pin 12 selected.   */
    SYSCFG_EXTILine_13 =  (0x0DU),  /*!< Pin 13 selected.   */
    SYSCFG_EXTILine_14 =  (0x0EU),  /*!< Pin 14 selected.   */
    SYSCFG_EXTILine_15 =  (0x0FU),  /*!< Pin 15 selected.   */
} SYSCFG_EXTILine_Type;

/*!
 * @brief I2C port mode.
 */
typedef enum
{
    SYSCFG_I2CPortMode_OpenDrain = 0u, /*!< I2C output open-drain mode. */
    SYSCFG_I2CPortMode_PushPull = 1u, /*!< I2C output push-pull mode. */
} SYSCFG_I2CPortMode_Type;

/*!
 * @brief Set boot memory mode.
 *
 * @param mode The memory mode. See to @ref SYSCFG_BootMemMode_Type.
 * @return None.
 */
void SYSCFG_SetBootMemMode(SYSCFG_BootMemMode_Type mode);

/*!
 * @brief Set the external interrupt mux.
 *
 * @param port external interrupt port. See to @ref SYSCFG_EXTIPort_Type.
 * @param line external interrupt line. See to @ref SYSCFG_EXTILine_Type.
 * @return None.
 */
void SYSCFG_SetExtIntMux(SYSCFG_EXTIPort_Type port, SYSCFG_EXTILine_Type line);

/*!
 * @brief Set the I2C port 0 mode.
 *
 * @param mode The I2C output state to be set. See to @ref SYSCFG_I2CPortMode_Type.
 * @return None.
 */
void SYSCFG_SetI2C0PortMode(SYSCFG_I2CPortMode_Type mode);

/*!
 * @}
 */

#endif /* __HAL_SYSCFG_H__ */
