/*
 * Copyright 2022 MindMotion Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/* hal_dma_request.h */
#ifndef __HAL_DMA_REQUESET_H__
#define __HAL_DMA_REQUESET_H__

/* DMA1 Requests Remap. */
/* ADC1. */
#define DMA_REQ_DMA1_ADC1_1      0u
#define DMA_REQ_DMA1_ADC1_2      1u


/* SPI1. */
#define DMA_REQ_DMA1_SPI1_RX     1u
#define DMA_REQ_DMA1_SPI1_TX     2u


/* SPI2. */
#define DMA_REQ_DMA1_SPI2_RX_1   3u
#define DMA_REQ_DMA1_SPI2_TX_1   4u
#define DMA_REQ_DMA1_SPI2_RX_2   5u
#define DMA_REQ_DMA1_SPI2_TX_2   6u


/* UART1. */
#define DMA_REQ_DMA1_UART1_TX_1  1u
#define DMA_REQ_DMA1_UART1_RX_1  2u
#define DMA_REQ_DMA1_UART1_TX_2  3u
#define DMA_REQ_DMA1_UART1_RX_2  4u


/* UART2. */
#define DMA_REQ_DMA1_UART2_TX_1  3u
#define DMA_REQ_DMA1_UART2_RX_1  4u
#define DMA_REQ_DMA1_UART2_RX_2  5u
#define DMA_REQ_DMA1_UART2_TX_2  6u


/* UART3. */
#define DMA_REQ_DMA1_UART3_TX_1  1u
#define DMA_REQ_DMA1_UART3_RX_1  2u
#define DMA_REQ_DMA1_UART3_RX_2  5u
#define DMA_REQ_DMA1_UART3_TX_2  6u


/* UART4. */
#define DMA_REQ_DMA1_UART4_RX    5u
#define DMA_REQ_DMA1_UART4_TX    6u


/* LPUART. */
#define DMA_REQ_DMA1_LPUART_TX   0u
#define DMA_REQ_DMA1_LPUART_RX   1u


/* I2C1. */
#define DMA_REQ_DMA1_I2C1_TX_1   1u
#define DMA_REQ_DMA1_I2C1_RX_1   2u
#define DMA_REQ_DMA1_I2C1_TX_2   5u
#define DMA_REQ_DMA1_I2C1_RX_2   6u


/* I3C. */
#define DMA_REQ_DMA1_I3C_TX      3u
#define DMA_REQ_DMA1_I3C_RX      4u


/* TIM1. */
#define DMA_REQ_DMA1_TIM1_CH1_1  1u
#define DMA_REQ_DMA1_TIM1_CH2_1  2u
#define DMA_REQ_DMA1_TIM1_CH4    3u
#define DMA_REQ_DMA1_TIM1_CH3_1  4u
#define DMA_REQ_DMA1_TIM1_CH1_2  5u
#define DMA_REQ_DMA1_TIM1_TRIG_2 6u


#define DMA_REQ_DMA1_TIM1_TRIG   3u
#define DMA_REQ_DMA1_TIM1_UP     4u
#define DMA_REQ_DMA1_TIM1_CH2_2  5u


#define DMA_REQ_DMA1_TIM1_COM    3u
#define DMA_REQ_DMA1_TIM1_CH5    4u
#define DMA_REQ_DMA1_TIM1_CH3_2  5u


/* TIM2. */
#define DMA_REQ_DMA1_TIM2_CH3    0u
#define DMA_REQ_DMA1_TIM2_UP     1u
#define DMA_REQ_DMA1_TIM2_CH2_1  2u
#define DMA_REQ_DMA1_TIM2_CH4_1  3u
#define DMA_REQ_DMA1_TIM2_CH1    4u
#define DMA_REQ_DMA1_TIM2_CH2_2  6u


/* TIM3. */
#define DMA_REQ_DMA1_TIM3_CH3    1u
#define DMA_REQ_DMA1_TIM3_CH4    2u
#define DMA_REQ_DMA1_TIM3_CH1_1  3u
#define DMA_REQ_DMA1_TIM3_CH1_2  5u


#define DMA_REQ_DMA1_TIM3_UP     2u
#define DMA_REQ_DMA1_TIM3_TRIG_1 3u
#define DMA_REQ_DMA1_TIM3_TRIG_2 5u


/* TIM16. */
#define DMA_REQ_DMA1_TIM16_CH1_1 2u
#define DMA_REQ_DMA1_TIM16_CH1_2 3u


#define DMA_REQ_DMA1_TIM16_UP_1  2u
#define DMA_REQ_DMA1_TIM16_UP_2  3u


/* TIM17. */
#define DMA_REQ_DMA1_TIM17_CH1_1 0u
#define DMA_REQ_DMA1_TIM17_CH1_2 1u


#define DMA_REQ_DMA1_TIM17_UP_1  0u
#define DMA_REQ_DMA1_TIM17_UP_2  1u


/* FLEXCAN1. */
#define DMA_REQ_DMA1_FLEXCAN1    0u


#endif /* __HAL_DMA_REQUESET_H__ */
