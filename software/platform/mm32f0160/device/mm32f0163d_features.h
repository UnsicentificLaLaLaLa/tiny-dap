/*
 * Copyright 2022 MindMotion Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#ifndef __MM32F0163D_FEATURES_H__
#define __MM32F0163D_FEATURES_H__

#include "mm32f0163d.h"

/*!
 * @addtogroup TIM_Peripheral_Access_Layer TIM Peripheral Access Layer
 *  @{
 */

/*******************************************************************************
 * TIM Type
 ******************************************************************************/
typedef struct {
    __IO uint32_t CR1;                                                            ///< Control register 1                           offset: 0x00
    __IO uint32_t CR2;                                                            ///< Control register 2                           offset: 0x04
    __IO uint32_t SMCR;                                                           ///< Slave mode control register                  offset: 0x08
    __IO uint32_t DIER;                                                           ///< DMA/interrupt enable register                offset: 0x0C
    __IO uint32_t SR;                                                             ///< Status register                              offset: 0x10
    __IO uint32_t EGR;                                                            ///< Event generation register                    offset: 0x14
    __IO uint32_t CCMR1;                                                          ///< Capture/compare mode register 1              offset: 0x18
    __IO uint32_t CCMR2;                                                          ///< Capture/compare enable register 2            offset: 0x1C
    __IO uint32_t CCER;                                                           ///< Capture/compare enable register              offset: 0x20
    __IO uint32_t CNT;                                                            ///< counter                                      offset: 0x24
    __IO uint32_t PSC;                                                            ///< Prescaler                                    offset: 0x28
    __IO uint32_t ARR;                                                            ///< Autoload register                            offset: 0x2C
    __IO uint32_t RCR;                                                            ///< Repeat count register                        offset: 0x30
    __IO uint32_t CCR[4];                                                         ///< Capture/compare register                     offset: 0x34
    __IO uint32_t BDTR;                                                           ///< Brake and dead zone registers                offset: 0x44
    __IO uint32_t DCR;                                                            ///< DMA control register                         offset: 0x48
    __IO uint32_t DMAR;                                                           ///< DMA address in continuous mode               offset: 0x4C
    __IO uint32_t Reserved0[1];                                                   ///< Reserved
    __IO uint32_t CCMR3;                                                          ///< Capture/compare mode register 3              offset: 0x54
    __IO uint32_t CCR5;                                                           ///< Capture/compare register 5                   offset: 0x58
    __IO uint32_t PDER;                                                           ///< PWM phase shift/DMA repeat update request enable registeroffset: 0x5C
    __IO uint32_t CCRFALL[5];                                                     ///< PWM phase shift down counting capture/compare registeroffset: 0x60
    __IO uint32_t BKINF;                                                          ///< brake input filter register                  offset: 0x74
} TIM_Type;

/*******************************************************************************
 * TIM Type
 ******************************************************************************/

/*!
 * @addtogroup TIM_Register_Masks Register Masks
 * @{
 */

/*!
 * @brief TIM_CR1 Register Bit Definition
 */

#define TIM_CR1_CKD_SHIFT                      (8)
#define TIM_CR1_CKD_MASK                       (0x3U << TIM_CR1_CKD_SHIFT)
#define TIM_CR1_CKD(x)                         (((uint32_t)(((uint32_t)(x)) << TIM_CR1_CKD_SHIFT)) & TIM_CR1_CKD_MASK)

#define TIM_CR1_ARPE_SHIFT                     (7)
#define TIM_CR1_ARPE_MASK                      (0x01U << TIM_CR1_ARPE_SHIFT)
#define TIM_CR1_ARPE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_CR1_ARPE_SHIFT)) & TIM_CR1_ARPE_MASK)

#define TIM_CR1_CMS_SHIFT                      (5)
#define TIM_CR1_CMS_MASK                       (0x3U << TIM_CR1_CMS_SHIFT)
#define TIM_CR1_CMS(x)                         (((uint32_t)(((uint32_t)(x)) << TIM_CR1_CMS_SHIFT)) & TIM_CR1_CMS_MASK)

#define TIM_CR1_DIR_SHIFT                      (4)
#define TIM_CR1_DIR_MASK                       (0x01U << TIM_CR1_DIR_SHIFT)
#define TIM_CR1_DIR(x)                         (((uint32_t)(((uint32_t)(x)) << TIM_CR1_DIR_SHIFT)) & TIM_CR1_DIR_MASK)

#define TIM_CR1_OPM_SHIFT                      (3)
#define TIM_CR1_OPM_MASK                       (0x01U << TIM_CR1_OPM_SHIFT)
#define TIM_CR1_OPM(x)                         (((uint32_t)(((uint32_t)(x)) << TIM_CR1_OPM_SHIFT)) & TIM_CR1_OPM_MASK)

#define TIM_CR1_URS_SHIFT                      (2)
#define TIM_CR1_URS_MASK                       (0x01U << TIM_CR1_URS_SHIFT)
#define TIM_CR1_URS(x)                         (((uint32_t)(((uint32_t)(x)) << TIM_CR1_URS_SHIFT)) & TIM_CR1_URS_MASK)

#define TIM_CR1_UDIS_SHIFT                     (1)
#define TIM_CR1_UDIS_MASK                      (0x01U << TIM_CR1_UDIS_SHIFT)
#define TIM_CR1_UDIS(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_CR1_UDIS_SHIFT)) & TIM_CR1_UDIS_MASK)

#define TIM_CR1_CEN_SHIFT                      (0)
#define TIM_CR1_CEN_MASK                       (0x01U << TIM_CR1_CEN_SHIFT)
#define TIM_CR1_CEN(x)                         (((uint32_t)(((uint32_t)(x)) << TIM_CR1_CEN_SHIFT)) & TIM_CR1_CEN_MASK)

/*!
 * @brief TIM_CR2 Register Bit Definition
 */

#define TIM_CR2_OIS4_SHIFT                     (14)
#define TIM_CR2_OIS4_MASK                      (0x01U << TIM_CR2_OIS4_SHIFT)
#define TIM_CR2_OIS4(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_CR2_OIS4_SHIFT)) & TIM_CR2_OIS4_MASK)

#define TIM_CR2_OIS3N_SHIFT                    (13)
#define TIM_CR2_OIS3N_MASK                     (0x01U << TIM_CR2_OIS3N_SHIFT)
#define TIM_CR2_OIS3N(x)                       (((uint32_t)(((uint32_t)(x)) << TIM_CR2_OIS3N_SHIFT)) & TIM_CR2_OIS3N_MASK)

#define TIM_CR2_OIS3_SHIFT                     (12)
#define TIM_CR2_OIS3_MASK                      (0x01U << TIM_CR2_OIS3_SHIFT)
#define TIM_CR2_OIS3(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_CR2_OIS3_SHIFT)) & TIM_CR2_OIS3_MASK)

#define TIM_CR2_OIS2N_SHIFT                    (11)
#define TIM_CR2_OIS2N_MASK                     (0x01U << TIM_CR2_OIS2N_SHIFT)
#define TIM_CR2_OIS2N(x)                       (((uint32_t)(((uint32_t)(x)) << TIM_CR2_OIS2N_SHIFT)) & TIM_CR2_OIS2N_MASK)

#define TIM_CR2_OIS2_SHIFT                     (10)
#define TIM_CR2_OIS2_MASK                      (0x01U << TIM_CR2_OIS2_SHIFT)
#define TIM_CR2_OIS2(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_CR2_OIS2_SHIFT)) & TIM_CR2_OIS2_MASK)

#define TIM_CR2_OIS1N_SHIFT                    (9)
#define TIM_CR2_OIS1N_MASK                     (0x01U << TIM_CR2_OIS1N_SHIFT)
#define TIM_CR2_OIS1N(x)                       (((uint32_t)(((uint32_t)(x)) << TIM_CR2_OIS1N_SHIFT)) & TIM_CR2_OIS1N_MASK)

#define TIM_CR2_OIS1_SHIFT                     (8)
#define TIM_CR2_OIS1_MASK                      (0x01U << TIM_CR2_OIS1_SHIFT)
#define TIM_CR2_OIS1(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_CR2_OIS1_SHIFT)) & TIM_CR2_OIS1_MASK)

#define TIM_CR2_TI1S_SHIFT                     (7)
#define TIM_CR2_TI1S_MASK                      (0x01U << TIM_CR2_TI1S_SHIFT)
#define TIM_CR2_TI1S(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_CR2_TI1S_SHIFT)) & TIM_CR2_TI1S_MASK)

#define TIM_CR2_MMS_SHIFT                      (4)
#define TIM_CR2_MMS_MASK                       (0x7U << TIM_CR2_MMS_SHIFT)
#define TIM_CR2_MMS(x)                         (((uint32_t)(((uint32_t)(x)) << TIM_CR2_MMS_SHIFT)) & TIM_CR2_MMS_MASK)

#define TIM_CR2_CCDS_SHIFT                     (3)
#define TIM_CR2_CCDS_MASK                      (0x01U << TIM_CR2_CCDS_SHIFT)
#define TIM_CR2_CCDS(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_CR2_CCDS_SHIFT)) & TIM_CR2_CCDS_MASK)

#define TIM_CR2_CCUS_SHIFT                     (2)
#define TIM_CR2_CCUS_MASK                      (0x01U << TIM_CR2_CCUS_SHIFT)
#define TIM_CR2_CCUS(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_CR2_CCUS_SHIFT)) & TIM_CR2_CCUS_MASK)

#define TIM_CR2_CCPC_SHIFT                     (0)
#define TIM_CR2_CCPC_MASK                      (0x01U << TIM_CR2_CCPC_SHIFT)
#define TIM_CR2_CCPC(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_CR2_CCPC_SHIFT)) & TIM_CR2_CCPC_MASK)

/*!
 * @brief TIM_SMCR Register Bit Definition
 */

#define TIM_SMCR_ETP_SHIFT                     (15)
#define TIM_SMCR_ETP_MASK                      (0x01U << TIM_SMCR_ETP_SHIFT)
#define TIM_SMCR_ETP(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_SMCR_ETP_SHIFT)) & TIM_SMCR_ETP_MASK)

#define TIM_SMCR_ECE_SHIFT                     (14)
#define TIM_SMCR_ECE_MASK                      (0x01U << TIM_SMCR_ECE_SHIFT)
#define TIM_SMCR_ECE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_SMCR_ECE_SHIFT)) & TIM_SMCR_ECE_MASK)

#define TIM_SMCR_ETPS_SHIFT                    (12)
#define TIM_SMCR_ETPS_MASK                     (0x3U << TIM_SMCR_ETPS_SHIFT)
#define TIM_SMCR_ETPS(x)                       (((uint32_t)(((uint32_t)(x)) << TIM_SMCR_ETPS_SHIFT)) & TIM_SMCR_ETPS_MASK)

#define TIM_SMCR_ETF_SHIFT                     (8)
#define TIM_SMCR_ETF_MASK                      (0xFU << TIM_SMCR_ETF_SHIFT)
#define TIM_SMCR_ETF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_SMCR_ETF_SHIFT)) & TIM_SMCR_ETF_MASK)

#define TIM_SMCR_MSM_SHIFT                     (7)
#define TIM_SMCR_MSM_MASK                      (0x01U << TIM_SMCR_MSM_SHIFT)
#define TIM_SMCR_MSM(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_SMCR_MSM_SHIFT)) & TIM_SMCR_MSM_MASK)

#define TIM_SMCR_TS_SHIFT                      (4)
#define TIM_SMCR_TS_MASK                       (0x7U << TIM_SMCR_TS_SHIFT)
#define TIM_SMCR_TS(x)                         (((uint32_t)(((uint32_t)(x)) << TIM_SMCR_TS_SHIFT)) & TIM_SMCR_TS_MASK)

#define TIM_SMCR_OCCS_SHIFT                    (3)
#define TIM_SMCR_OCCS_MASK                     (0x01U << TIM_SMCR_OCCS_SHIFT)
#define TIM_SMCR_OCCS(x)                       (((uint32_t)(((uint32_t)(x)) << TIM_SMCR_OCCS_SHIFT)) & TIM_SMCR_OCCS_MASK)

#define TIM_SMCR_SMS_SHIFT                     (0)
#define TIM_SMCR_SMS_MASK                      (0x7U << TIM_SMCR_SMS_SHIFT)
#define TIM_SMCR_SMS(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_SMCR_SMS_SHIFT)) & TIM_SMCR_SMS_MASK)

/*!
 * @brief TIM_DIER Register Bit Definition
 */

#define TIM_DIER_CC5DE_SHIFT                   (17)
#define TIM_DIER_CC5DE_MASK                    (0x01U << TIM_DIER_CC5DE_SHIFT)
#define TIM_DIER_CC5DE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_DIER_CC5DE_SHIFT)) & TIM_DIER_CC5DE_MASK)

#define TIM_DIER_CC5IE_SHIFT                   (16)
#define TIM_DIER_CC5IE_MASK                    (0x01U << TIM_DIER_CC5IE_SHIFT)
#define TIM_DIER_CC5IE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_DIER_CC5IE_SHIFT)) & TIM_DIER_CC5IE_MASK)

#define TIM_DIER_TDE_SHIFT                     (14)
#define TIM_DIER_TDE_MASK                      (0x01U << TIM_DIER_TDE_SHIFT)
#define TIM_DIER_TDE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_DIER_TDE_SHIFT)) & TIM_DIER_TDE_MASK)

#define TIM_DIER_COMDE_SHIFT                   (13)
#define TIM_DIER_COMDE_MASK                    (0x01U << TIM_DIER_COMDE_SHIFT)
#define TIM_DIER_COMDE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_DIER_COMDE_SHIFT)) & TIM_DIER_COMDE_MASK)

#define TIM_DIER_CC4DE_SHIFT                   (12)
#define TIM_DIER_CC4DE_MASK                    (0x01U << TIM_DIER_CC4DE_SHIFT)
#define TIM_DIER_CC4DE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_DIER_CC4DE_SHIFT)) & TIM_DIER_CC4DE_MASK)

#define TIM_DIER_CC3DE_SHIFT                   (11)
#define TIM_DIER_CC3DE_MASK                    (0x01U << TIM_DIER_CC3DE_SHIFT)
#define TIM_DIER_CC3DE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_DIER_CC3DE_SHIFT)) & TIM_DIER_CC3DE_MASK)

#define TIM_DIER_CC2DE_SHIFT                   (10)
#define TIM_DIER_CC2DE_MASK                    (0x01U << TIM_DIER_CC2DE_SHIFT)
#define TIM_DIER_CC2DE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_DIER_CC2DE_SHIFT)) & TIM_DIER_CC2DE_MASK)

#define TIM_DIER_CC1DE_SHIFT                   (9)
#define TIM_DIER_CC1DE_MASK                    (0x01U << TIM_DIER_CC1DE_SHIFT)
#define TIM_DIER_CC1DE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_DIER_CC1DE_SHIFT)) & TIM_DIER_CC1DE_MASK)

#define TIM_DIER_UDE_SHIFT                     (8)
#define TIM_DIER_UDE_MASK                      (0x01U << TIM_DIER_UDE_SHIFT)
#define TIM_DIER_UDE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_DIER_UDE_SHIFT)) & TIM_DIER_UDE_MASK)

#define TIM_DIER_BIE_SHIFT                     (7)
#define TIM_DIER_BIE_MASK                      (0x01U << TIM_DIER_BIE_SHIFT)
#define TIM_DIER_BIE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_DIER_BIE_SHIFT)) & TIM_DIER_BIE_MASK)

#define TIM_DIER_TIE_SHIFT                     (6)
#define TIM_DIER_TIE_MASK                      (0x01U << TIM_DIER_TIE_SHIFT)
#define TIM_DIER_TIE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_DIER_TIE_SHIFT)) & TIM_DIER_TIE_MASK)

#define TIM_DIER_COMIE_SHIFT                   (5)
#define TIM_DIER_COMIE_MASK                    (0x01U << TIM_DIER_COMIE_SHIFT)
#define TIM_DIER_COMIE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_DIER_COMIE_SHIFT)) & TIM_DIER_COMIE_MASK)

#define TIM_DIER_CC4IE_SHIFT                   (4)
#define TIM_DIER_CC4IE_MASK                    (0x01U << TIM_DIER_CC4IE_SHIFT)
#define TIM_DIER_CC4IE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_DIER_CC4IE_SHIFT)) & TIM_DIER_CC4IE_MASK)

#define TIM_DIER_CC3IE_SHIFT                   (3)
#define TIM_DIER_CC3IE_MASK                    (0x01U << TIM_DIER_CC3IE_SHIFT)
#define TIM_DIER_CC3IE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_DIER_CC3IE_SHIFT)) & TIM_DIER_CC3IE_MASK)

#define TIM_DIER_CC2IE_SHIFT                   (2)
#define TIM_DIER_CC2IE_MASK                    (0x01U << TIM_DIER_CC2IE_SHIFT)
#define TIM_DIER_CC2IE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_DIER_CC2IE_SHIFT)) & TIM_DIER_CC2IE_MASK)

#define TIM_DIER_CC1IE_SHIFT                   (1)
#define TIM_DIER_CC1IE_MASK                    (0x01U << TIM_DIER_CC1IE_SHIFT)
#define TIM_DIER_CC1IE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_DIER_CC1IE_SHIFT)) & TIM_DIER_CC1IE_MASK)

#define TIM_DIER_UIE_SHIFT                     (0)
#define TIM_DIER_UIE_MASK                      (0x01U << TIM_DIER_UIE_SHIFT)
#define TIM_DIER_UIE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_DIER_UIE_SHIFT)) & TIM_DIER_UIE_MASK)

/*!
 * @brief TIM_SR Register Bit Definition
 */

#define TIM_SR_CC5IF_SHIFT                     (16)
#define TIM_SR_CC5IF_MASK                      (0x01U << TIM_SR_CC5IF_SHIFT)
#define TIM_SR_CC5IF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_SR_CC5IF_SHIFT)) & TIM_SR_CC5IF_MASK)

#define TIM_SR_CC4OF_SHIFT                     (12)
#define TIM_SR_CC4OF_MASK                      (0x01U << TIM_SR_CC4OF_SHIFT)
#define TIM_SR_CC4OF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_SR_CC4OF_SHIFT)) & TIM_SR_CC4OF_MASK)

#define TIM_SR_CC3OF_SHIFT                     (11)
#define TIM_SR_CC3OF_MASK                      (0x01U << TIM_SR_CC3OF_SHIFT)
#define TIM_SR_CC3OF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_SR_CC3OF_SHIFT)) & TIM_SR_CC3OF_MASK)

#define TIM_SR_CC2OF_SHIFT                     (10)
#define TIM_SR_CC2OF_MASK                      (0x01U << TIM_SR_CC2OF_SHIFT)
#define TIM_SR_CC2OF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_SR_CC2OF_SHIFT)) & TIM_SR_CC2OF_MASK)

#define TIM_SR_CC1OF_SHIFT                     (9)
#define TIM_SR_CC1OF_MASK                      (0x01U << TIM_SR_CC1OF_SHIFT)
#define TIM_SR_CC1OF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_SR_CC1OF_SHIFT)) & TIM_SR_CC1OF_MASK)

#define TIM_SR_BIF_SHIFT                       (7)
#define TIM_SR_BIF_MASK                        (0x01U << TIM_SR_BIF_SHIFT)
#define TIM_SR_BIF(x)                          (((uint32_t)(((uint32_t)(x)) << TIM_SR_BIF_SHIFT)) & TIM_SR_BIF_MASK)

#define TIM_SR_TIF_SHIFT                       (6)
#define TIM_SR_TIF_MASK                        (0x01U << TIM_SR_TIF_SHIFT)
#define TIM_SR_TIF(x)                          (((uint32_t)(((uint32_t)(x)) << TIM_SR_TIF_SHIFT)) & TIM_SR_TIF_MASK)

#define TIM_SR_COMIF_SHIFT                     (5)
#define TIM_SR_COMIF_MASK                      (0x01U << TIM_SR_COMIF_SHIFT)
#define TIM_SR_COMIF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_SR_COMIF_SHIFT)) & TIM_SR_COMIF_MASK)

#define TIM_SR_CC4IF_SHIFT                     (4)
#define TIM_SR_CC4IF_MASK                      (0x01U << TIM_SR_CC4IF_SHIFT)
#define TIM_SR_CC4IF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_SR_CC4IF_SHIFT)) & TIM_SR_CC4IF_MASK)

#define TIM_SR_CC3IF_SHIFT                     (3)
#define TIM_SR_CC3IF_MASK                      (0x01U << TIM_SR_CC3IF_SHIFT)
#define TIM_SR_CC3IF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_SR_CC3IF_SHIFT)) & TIM_SR_CC3IF_MASK)

#define TIM_SR_CC2IF_SHIFT                     (2)
#define TIM_SR_CC2IF_MASK                      (0x01U << TIM_SR_CC2IF_SHIFT)
#define TIM_SR_CC2IF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_SR_CC2IF_SHIFT)) & TIM_SR_CC2IF_MASK)

#define TIM_SR_CC1IF_SHIFT                     (1)
#define TIM_SR_CC1IF_MASK                      (0x01U << TIM_SR_CC1IF_SHIFT)
#define TIM_SR_CC1IF(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_SR_CC1IF_SHIFT)) & TIM_SR_CC1IF_MASK)

#define TIM_SR_UIF_SHIFT                       (0)
#define TIM_SR_UIF_MASK                        (0x01U << TIM_SR_UIF_SHIFT)
#define TIM_SR_UIF(x)                          (((uint32_t)(((uint32_t)(x)) << TIM_SR_UIF_SHIFT)) & TIM_SR_UIF_MASK)

/*!
 * @brief TIM_EGR Register Bit Definition
 */

#define TIM_EGR_CC5G_SHIFT                     (16)
#define TIM_EGR_CC5G_MASK                      (0x01U << TIM_EGR_CC5G_SHIFT)
#define TIM_EGR_CC5G(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_EGR_CC5G_SHIFT)) & TIM_EGR_CC5G_MASK)

#define TIM_EGR_BG_SHIFT                       (7)
#define TIM_EGR_BG_MASK                        (0x01U << TIM_EGR_BG_SHIFT)
#define TIM_EGR_BG(x)                          (((uint32_t)(((uint32_t)(x)) << TIM_EGR_BG_SHIFT)) & TIM_EGR_BG_MASK)

#define TIM_EGR_TG_SHIFT                       (6)
#define TIM_EGR_TG_MASK                        (0x01U << TIM_EGR_TG_SHIFT)
#define TIM_EGR_TG(x)                          (((uint32_t)(((uint32_t)(x)) << TIM_EGR_TG_SHIFT)) & TIM_EGR_TG_MASK)

#define TIM_EGR_COMG_SHIFT                     (5)
#define TIM_EGR_COMG_MASK                      (0x01U << TIM_EGR_COMG_SHIFT)
#define TIM_EGR_COMG(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_EGR_COMG_SHIFT)) & TIM_EGR_COMG_MASK)

#define TIM_EGR_CC4G_SHIFT                     (4)
#define TIM_EGR_CC4G_MASK                      (0x01U << TIM_EGR_CC4G_SHIFT)
#define TIM_EGR_CC4G(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_EGR_CC4G_SHIFT)) & TIM_EGR_CC4G_MASK)

#define TIM_EGR_CC3G_SHIFT                     (3)
#define TIM_EGR_CC3G_MASK                      (0x01U << TIM_EGR_CC3G_SHIFT)
#define TIM_EGR_CC3G(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_EGR_CC3G_SHIFT)) & TIM_EGR_CC3G_MASK)

#define TIM_EGR_CC2G_SHIFT                     (2)
#define TIM_EGR_CC2G_MASK                      (0x01U << TIM_EGR_CC2G_SHIFT)
#define TIM_EGR_CC2G(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_EGR_CC2G_SHIFT)) & TIM_EGR_CC2G_MASK)

#define TIM_EGR_CC1G_SHIFT                     (1)
#define TIM_EGR_CC1G_MASK                      (0x01U << TIM_EGR_CC1G_SHIFT)
#define TIM_EGR_CC1G(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_EGR_CC1G_SHIFT)) & TIM_EGR_CC1G_MASK)

#define TIM_EGR_UG_SHIFT                       (0)
#define TIM_EGR_UG_MASK                        (0x01U << TIM_EGR_UG_SHIFT)
#define TIM_EGR_UG(x)                          (((uint32_t)(((uint32_t)(x)) << TIM_EGR_UG_SHIFT)) & TIM_EGR_UG_MASK)

/*!
 * @brief TIM_CCMR1 Register Bit Definition
 */

#define TIM_CCMR1_OC2CE_SHIFT                  (15)
#define TIM_CCMR1_OC2CE_MASK                   (0x01U << TIM_CCMR1_OC2CE_SHIFT)
#define TIM_CCMR1_OC2CE(x)                     (((uint32_t)(((uint32_t)(x)) << TIM_CCMR1_OC2CE_SHIFT)) & TIM_CCMR1_OC2CE_MASK)

#define TIM_CCMR1_OC2M_SHIFT                   (12)
#define TIM_CCMR1_OC2M_MASK                    (0x7U << TIM_CCMR1_OC2M_SHIFT)
#define TIM_CCMR1_OC2M(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCMR1_OC2M_SHIFT)) & TIM_CCMR1_OC2M_MASK)

#define TIM_CCMR1_OC2PE_SHIFT                  (11)
#define TIM_CCMR1_OC2PE_MASK                   (0x01U << TIM_CCMR1_OC2PE_SHIFT)
#define TIM_CCMR1_OC2PE(x)                     (((uint32_t)(((uint32_t)(x)) << TIM_CCMR1_OC2PE_SHIFT)) & TIM_CCMR1_OC2PE_MASK)

#define TIM_CCMR1_OC2FE_SHIFT                  (10)
#define TIM_CCMR1_OC2FE_MASK                   (0x01U << TIM_CCMR1_OC2FE_SHIFT)
#define TIM_CCMR1_OC2FE(x)                     (((uint32_t)(((uint32_t)(x)) << TIM_CCMR1_OC2FE_SHIFT)) & TIM_CCMR1_OC2FE_MASK)

#define TIM_CCMR1_CC2S_SHIFT                   (8)
#define TIM_CCMR1_CC2S_MASK                    (0x3U << TIM_CCMR1_CC2S_SHIFT)
#define TIM_CCMR1_CC2S(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCMR1_CC2S_SHIFT)) & TIM_CCMR1_CC2S_MASK)

#define TIM_CCMR1_OC1CE_SHIFT                  (7)
#define TIM_CCMR1_OC1CE_MASK                   (0x01U << TIM_CCMR1_OC1CE_SHIFT)
#define TIM_CCMR1_OC1CE(x)                     (((uint32_t)(((uint32_t)(x)) << TIM_CCMR1_OC1CE_SHIFT)) & TIM_CCMR1_OC1CE_MASK)

#define TIM_CCMR1_OC1M_SHIFT                   (4)
#define TIM_CCMR1_OC1M_MASK                    (0x7U << TIM_CCMR1_OC1M_SHIFT)
#define TIM_CCMR1_OC1M(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCMR1_OC1M_SHIFT)) & TIM_CCMR1_OC1M_MASK)

#define TIM_CCMR1_OC1PE_SHIFT                  (3)
#define TIM_CCMR1_OC1PE_MASK                   (0x01U << TIM_CCMR1_OC1PE_SHIFT)
#define TIM_CCMR1_OC1PE(x)                     (((uint32_t)(((uint32_t)(x)) << TIM_CCMR1_OC1PE_SHIFT)) & TIM_CCMR1_OC1PE_MASK)

#define TIM_CCMR1_OC1FE_SHIFT                  (2)
#define TIM_CCMR1_OC1FE_MASK                   (0x01U << TIM_CCMR1_OC1FE_SHIFT)
#define TIM_CCMR1_OC1FE(x)                     (((uint32_t)(((uint32_t)(x)) << TIM_CCMR1_OC1FE_SHIFT)) & TIM_CCMR1_OC1FE_MASK)

#define TIM_CCMR1_CC1S_SHIFT                   (0)
#define TIM_CCMR1_CC1S_MASK                    (0x3U << TIM_CCMR1_CC1S_SHIFT)
#define TIM_CCMR1_CC1S(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCMR1_CC1S_SHIFT)) & TIM_CCMR1_CC1S_MASK)

/*!
 * @brief TIM_CCMR1 Register Bit Definition
 */

#define TIM_CCMR1_IC2F_SHIFT                   (12)
#define TIM_CCMR1_IC2F_MASK                    (0xFU << TIM_CCMR1_IC2F_SHIFT)
#define TIM_CCMR1_IC2F(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCMR1_IC2F_SHIFT)) & TIM_CCMR1_IC2F_MASK)

#define TIM_CCMR1_IC2PSC_SHIFT                 (10)
#define TIM_CCMR1_IC2PSC_MASK                  (0x3U << TIM_CCMR1_IC2PSC_SHIFT)
#define TIM_CCMR1_IC2PSC(x)                    (((uint32_t)(((uint32_t)(x)) << TIM_CCMR1_IC2PSC_SHIFT)) & TIM_CCMR1_IC2PSC_MASK)

#define TIM_CCMR1_CC2S_SHIFT                   (8)
#define TIM_CCMR1_CC2S_MASK                    (0x3U << TIM_CCMR1_CC2S_SHIFT)
#define TIM_CCMR1_CC2S(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCMR1_CC2S_SHIFT)) & TIM_CCMR1_CC2S_MASK)

#define TIM_CCMR1_IC1F_SHIFT                   (4)
#define TIM_CCMR1_IC1F_MASK                    (0xFU << TIM_CCMR1_IC1F_SHIFT)
#define TIM_CCMR1_IC1F(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCMR1_IC1F_SHIFT)) & TIM_CCMR1_IC1F_MASK)

#define TIM_CCMR1_IC1PSC_SHIFT                 (2)
#define TIM_CCMR1_IC1PSC_MASK                  (0x3U << TIM_CCMR1_IC1PSC_SHIFT)
#define TIM_CCMR1_IC1PSC(x)                    (((uint32_t)(((uint32_t)(x)) << TIM_CCMR1_IC1PSC_SHIFT)) & TIM_CCMR1_IC1PSC_MASK)

#define TIM_CCMR1_CC1S_SHIFT                   (0)
#define TIM_CCMR1_CC1S_MASK                    (0x3U << TIM_CCMR1_CC1S_SHIFT)
#define TIM_CCMR1_CC1S(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCMR1_CC1S_SHIFT)) & TIM_CCMR1_CC1S_MASK)

/*!
 * @brief TIM_CCMR2 Register Bit Definition
 */

#define TIM_CCMR2_OC4CE_SHIFT                  (15)
#define TIM_CCMR2_OC4CE_MASK                   (0x01U << TIM_CCMR2_OC4CE_SHIFT)
#define TIM_CCMR2_OC4CE(x)                     (((uint32_t)(((uint32_t)(x)) << TIM_CCMR2_OC4CE_SHIFT)) & TIM_CCMR2_OC4CE_MASK)

#define TIM_CCMR2_OC4M_SHIFT                   (12)
#define TIM_CCMR2_OC4M_MASK                    (0x7U << TIM_CCMR2_OC4M_SHIFT)
#define TIM_CCMR2_OC4M(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCMR2_OC4M_SHIFT)) & TIM_CCMR2_OC4M_MASK)

#define TIM_CCMR2_OC4PE_SHIFT                  (11)
#define TIM_CCMR2_OC4PE_MASK                   (0x01U << TIM_CCMR2_OC4PE_SHIFT)
#define TIM_CCMR2_OC4PE(x)                     (((uint32_t)(((uint32_t)(x)) << TIM_CCMR2_OC4PE_SHIFT)) & TIM_CCMR2_OC4PE_MASK)

#define TIM_CCMR2_OC4FE_SHIFT                  (10)
#define TIM_CCMR2_OC4FE_MASK                   (0x01U << TIM_CCMR2_OC4FE_SHIFT)
#define TIM_CCMR2_OC4FE(x)                     (((uint32_t)(((uint32_t)(x)) << TIM_CCMR2_OC4FE_SHIFT)) & TIM_CCMR2_OC4FE_MASK)

#define TIM_CCMR2_CC4S_SHIFT                   (8)
#define TIM_CCMR2_CC4S_MASK                    (0x3U << TIM_CCMR2_CC4S_SHIFT)
#define TIM_CCMR2_CC4S(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCMR2_CC4S_SHIFT)) & TIM_CCMR2_CC4S_MASK)

#define TIM_CCMR2_OC3CE_SHIFT                  (7)
#define TIM_CCMR2_OC3CE_MASK                   (0x01U << TIM_CCMR2_OC3CE_SHIFT)
#define TIM_CCMR2_OC3CE(x)                     (((uint32_t)(((uint32_t)(x)) << TIM_CCMR2_OC3CE_SHIFT)) & TIM_CCMR2_OC3CE_MASK)

#define TIM_CCMR2_OC3M_SHIFT                   (4)
#define TIM_CCMR2_OC3M_MASK                    (0x7U << TIM_CCMR2_OC3M_SHIFT)
#define TIM_CCMR2_OC3M(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCMR2_OC3M_SHIFT)) & TIM_CCMR2_OC3M_MASK)

#define TIM_CCMR2_OC3PE_SHIFT                  (3)
#define TIM_CCMR2_OC3PE_MASK                   (0x01U << TIM_CCMR2_OC3PE_SHIFT)
#define TIM_CCMR2_OC3PE(x)                     (((uint32_t)(((uint32_t)(x)) << TIM_CCMR2_OC3PE_SHIFT)) & TIM_CCMR2_OC3PE_MASK)

#define TIM_CCMR2_OC3FE_SHIFT                  (2)
#define TIM_CCMR2_OC3FE_MASK                   (0x01U << TIM_CCMR2_OC3FE_SHIFT)
#define TIM_CCMR2_OC3FE(x)                     (((uint32_t)(((uint32_t)(x)) << TIM_CCMR2_OC3FE_SHIFT)) & TIM_CCMR2_OC3FE_MASK)

#define TIM_CCMR2_CC3S_SHIFT                   (0)
#define TIM_CCMR2_CC3S_MASK                    (0x3U << TIM_CCMR2_CC3S_SHIFT)
#define TIM_CCMR2_CC3S(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCMR2_CC3S_SHIFT)) & TIM_CCMR2_CC3S_MASK)

/*!
 * @brief TIM_CCMR2 Register Bit Definition
 */

#define TIM_CCMR2_IC4F_SHIFT                   (12)
#define TIM_CCMR2_IC4F_MASK                    (0xFU << TIM_CCMR2_IC4F_SHIFT)
#define TIM_CCMR2_IC4F(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCMR2_IC4F_SHIFT)) & TIM_CCMR2_IC4F_MASK)

#define TIM_CCMR2_IC4PSC_SHIFT                 (10)
#define TIM_CCMR2_IC4PSC_MASK                  (0x3U << TIM_CCMR2_IC4PSC_SHIFT)
#define TIM_CCMR2_IC4PSC(x)                    (((uint32_t)(((uint32_t)(x)) << TIM_CCMR2_IC4PSC_SHIFT)) & TIM_CCMR2_IC4PSC_MASK)

#define TIM_CCMR2_CC4S_SHIFT                   (8)
#define TIM_CCMR2_CC4S_MASK                    (0x3U << TIM_CCMR2_CC4S_SHIFT)
#define TIM_CCMR2_CC4S(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCMR2_CC4S_SHIFT)) & TIM_CCMR2_CC4S_MASK)

#define TIM_CCMR2_IC3F_SHIFT                   (4)
#define TIM_CCMR2_IC3F_MASK                    (0xFU << TIM_CCMR2_IC3F_SHIFT)
#define TIM_CCMR2_IC3F(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCMR2_IC3F_SHIFT)) & TIM_CCMR2_IC3F_MASK)

#define TIM_CCMR2_IC3PSC_SHIFT                 (2)
#define TIM_CCMR2_IC3PSC_MASK                  (0x3U << TIM_CCMR2_IC3PSC_SHIFT)
#define TIM_CCMR2_IC3PSC(x)                    (((uint32_t)(((uint32_t)(x)) << TIM_CCMR2_IC3PSC_SHIFT)) & TIM_CCMR2_IC3PSC_MASK)

#define TIM_CCMR2_CC3S_SHIFT                   (0)
#define TIM_CCMR2_CC3S_MASK                    (0x3U << TIM_CCMR2_CC3S_SHIFT)
#define TIM_CCMR2_CC3S(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCMR2_CC3S_SHIFT)) & TIM_CCMR2_CC3S_MASK)

/*!
 * @brief TIM_CCER Register Bit Definition
 */

#define TIM_CCER_CC4NP_SHIFT                   (15)
#define TIM_CCER_CC4NP_MASK                    (0x01U << TIM_CCER_CC4NP_SHIFT)
#define TIM_CCER_CC4NP(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCER_CC4NP_SHIFT)) & TIM_CCER_CC4NP_MASK)

/* Reserved, TIM_CCER_CC4NE is invalid in F0144, just for adapting hal_tim. */
#define TIM_CCER_CC4NE_SHIFT                   (14)
#define TIM_CCER_CC4NE_MASK                    (0x01U << TIM_CCER_CC4NE_SHIFT)
#define TIM_CCER_CC4NE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCER_CC4NE_SHIFT)) & TIM_CCER_CC4NE_MASK)

#define TIM_CCER_CC4P_SHIFT                    (13)
#define TIM_CCER_CC4P_MASK                     (0x01U << TIM_CCER_CC4P_SHIFT)
#define TIM_CCER_CC4P(x)                       (((uint32_t)(((uint32_t)(x)) << TIM_CCER_CC4P_SHIFT)) & TIM_CCER_CC4P_MASK)

#define TIM_CCER_CC4E_SHIFT                    (12)
#define TIM_CCER_CC4E_MASK                     (0x01U << TIM_CCER_CC4E_SHIFT)
#define TIM_CCER_CC4E(x)                       (((uint32_t)(((uint32_t)(x)) << TIM_CCER_CC4E_SHIFT)) & TIM_CCER_CC4E_MASK)

#define TIM_CCER_CC3NP_SHIFT                   (11)
#define TIM_CCER_CC3NP_MASK                    (0x01U << TIM_CCER_CC3NP_SHIFT)
#define TIM_CCER_CC3NP(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCER_CC3NP_SHIFT)) & TIM_CCER_CC3NP_MASK)

#define TIM_CCER_CC3NE_SHIFT                   (10)
#define TIM_CCER_CC3NE_MASK                    (0x01U << TIM_CCER_CC3NE_SHIFT)
#define TIM_CCER_CC3NE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCER_CC3NE_SHIFT)) & TIM_CCER_CC3NE_MASK)

#define TIM_CCER_CC3P_SHIFT                    (9)
#define TIM_CCER_CC3P_MASK                     (0x01U << TIM_CCER_CC3P_SHIFT)
#define TIM_CCER_CC3P(x)                       (((uint32_t)(((uint32_t)(x)) << TIM_CCER_CC3P_SHIFT)) & TIM_CCER_CC3P_MASK)

#define TIM_CCER_CC3E_SHIFT                    (8)
#define TIM_CCER_CC3E_MASK                     (0x01U << TIM_CCER_CC3E_SHIFT)
#define TIM_CCER_CC3E(x)                       (((uint32_t)(((uint32_t)(x)) << TIM_CCER_CC3E_SHIFT)) & TIM_CCER_CC3E_MASK)

#define TIM_CCER_CC2NP_SHIFT                   (7)
#define TIM_CCER_CC2NP_MASK                    (0x01U << TIM_CCER_CC2NP_SHIFT)
#define TIM_CCER_CC2NP(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCER_CC2NP_SHIFT)) & TIM_CCER_CC2NP_MASK)

#define TIM_CCER_CC2NE_SHIFT                   (6)
#define TIM_CCER_CC2NE_MASK                    (0x01U << TIM_CCER_CC2NE_SHIFT)
#define TIM_CCER_CC2NE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCER_CC2NE_SHIFT)) & TIM_CCER_CC2NE_MASK)

#define TIM_CCER_CC2P_SHIFT                    (5)
#define TIM_CCER_CC2P_MASK                     (0x01U << TIM_CCER_CC2P_SHIFT)
#define TIM_CCER_CC2P(x)                       (((uint32_t)(((uint32_t)(x)) << TIM_CCER_CC2P_SHIFT)) & TIM_CCER_CC2P_MASK)

#define TIM_CCER_CC2E_SHIFT                    (4)
#define TIM_CCER_CC2E_MASK                     (0x01U << TIM_CCER_CC2E_SHIFT)
#define TIM_CCER_CC2E(x)                       (((uint32_t)(((uint32_t)(x)) << TIM_CCER_CC2E_SHIFT)) & TIM_CCER_CC2E_MASK)

#define TIM_CCER_CC1NP_SHIFT                   (3)
#define TIM_CCER_CC1NP_MASK                    (0x01U << TIM_CCER_CC1NP_SHIFT)
#define TIM_CCER_CC1NP(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCER_CC1NP_SHIFT)) & TIM_CCER_CC1NP_MASK)

#define TIM_CCER_CC1NE_SHIFT                   (2)
#define TIM_CCER_CC1NE_MASK                    (0x01U << TIM_CCER_CC1NE_SHIFT)
#define TIM_CCER_CC1NE(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCER_CC1NE_SHIFT)) & TIM_CCER_CC1NE_MASK)

#define TIM_CCER_CC1P_SHIFT                    (1)
#define TIM_CCER_CC1P_MASK                     (0x01U << TIM_CCER_CC1P_SHIFT)
#define TIM_CCER_CC1P(x)                       (((uint32_t)(((uint32_t)(x)) << TIM_CCER_CC1P_SHIFT)) & TIM_CCER_CC1P_MASK)

#define TIM_CCER_CC1E_SHIFT                    (0)
#define TIM_CCER_CC1E_MASK                     (0x01U << TIM_CCER_CC1E_SHIFT)
#define TIM_CCER_CC1E(x)                       (((uint32_t)(((uint32_t)(x)) << TIM_CCER_CC1E_SHIFT)) & TIM_CCER_CC1E_MASK)

/*!
 * @brief TIM_CNT Register Bit Definition
 */

#define TIM_CNT_CNT_SHIFT                      (0)
#define TIM_CNT_CNT_MASK                       (0xFFFFU << TIM_CNT_CNT_SHIFT)
#define TIM_CNT_CNT(x)                         (((uint32_t)(((uint32_t)(x)) << TIM_CNT_CNT_SHIFT)) & TIM_CNT_CNT_MASK)

/*!
 * @brief TIM_PSC Register Bit Definition
 */

#define TIM_PSC_PSC_SHIFT                      (0)
#define TIM_PSC_PSC_MASK                       (0xFFFFU << TIM_PSC_PSC_SHIFT)
#define TIM_PSC_PSC(x)                         (((uint32_t)(((uint32_t)(x)) << TIM_PSC_PSC_SHIFT)) & TIM_PSC_PSC_MASK)

/*!
 * @brief TIM_ARR Register Bit Definition
 */

#define TIM_ARR_ARR_SHIFT                      (0)
#define TIM_ARR_ARR_MASK                       (0xFFFFU << TIM_ARR_ARR_SHIFT)
#define TIM_ARR_ARR(x)                         (((uint32_t)(((uint32_t)(x)) << TIM_ARR_ARR_SHIFT)) & TIM_ARR_ARR_MASK)

/*!
 * @brief TIM_RCR Register Bit Definition
 */

#define TIM_RCR_REPCNT_SHIFT                   (8)
#define TIM_RCR_REPCNT_MASK                    (0xFFU << TIM_RCR_REPCNT_SHIFT)
#define TIM_RCR_REPCNT(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_RCR_REPCNT_SHIFT)) & TIM_RCR_REPCNT_MASK)

#define TIM_RCR_REP_SHIFT                      (0)
#define TIM_RCR_REP_MASK                       (0xFFU << TIM_RCR_REP_SHIFT)
#define TIM_RCR_REP(x)                         (((uint32_t)(((uint32_t)(x)) << TIM_RCR_REP_SHIFT)) & TIM_RCR_REP_MASK)

/*!
 * @brief TIM_CCR1 Register Bit Definition
 */

#define TIM_CCR1_CCR1_SHIFT                    (0)
#define TIM_CCR1_CCR1_MASK                     (0xFFFFU << TIM_CCR1_CCR1_SHIFT)
#define TIM_CCR1_CCR1(x)                       (((uint32_t)(((uint32_t)(x)) << TIM_CCR1_CCR1_SHIFT)) & TIM_CCR1_CCR1_MASK)

/*!
 * @brief TIM_CCR2 Register Bit Definition
 */

#define TIM_CCR2_CCR2_SHIFT                    (0)
#define TIM_CCR2_CCR2_MASK                     (0xFFFFU << TIM_CCR2_CCR2_SHIFT)
#define TIM_CCR2_CCR2(x)                       (((uint32_t)(((uint32_t)(x)) << TIM_CCR2_CCR2_SHIFT)) & TIM_CCR2_CCR2_MASK)

/*!
 * @brief TIM_CCR3 Register Bit Definition
 */

#define TIM_CCR3_CCR3_SHIFT                    (0)
#define TIM_CCR3_CCR3_MASK                     (0xFFFFU << TIM_CCR3_CCR3_SHIFT)
#define TIM_CCR3_CCR3(x)                       (((uint32_t)(((uint32_t)(x)) << TIM_CCR3_CCR3_SHIFT)) & TIM_CCR3_CCR3_MASK)

/*!
 * @brief TIM_CCR4 Register Bit Definition
 */

#define TIM_CCR4_CCR4_SHIFT                    (0)
#define TIM_CCR4_CCR4_MASK                     (0xFFFFU << TIM_CCR4_CCR4_SHIFT)
#define TIM_CCR4_CCR4(x)                       (((uint32_t)(((uint32_t)(x)) << TIM_CCR4_CCR4_SHIFT)) & TIM_CCR4_CCR4_MASK)

/*!
 * @brief TIM_BDTR Register Bit Definition
 */

#define TIM_BDTR_DOE_SHIFT                     (16)
#define TIM_BDTR_DOE_MASK                      (0x01U << TIM_BDTR_DOE_SHIFT)
#define TIM_BDTR_DOE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_BDTR_DOE_SHIFT)) & TIM_BDTR_DOE_MASK)

#define TIM_BDTR_MOE_SHIFT                     (15)
#define TIM_BDTR_MOE_MASK                      (0x01U << TIM_BDTR_MOE_SHIFT)
#define TIM_BDTR_MOE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_BDTR_MOE_SHIFT)) & TIM_BDTR_MOE_MASK)

#define TIM_BDTR_AOE_SHIFT                     (14)
#define TIM_BDTR_AOE_MASK                      (0x01U << TIM_BDTR_AOE_SHIFT)
#define TIM_BDTR_AOE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_BDTR_AOE_SHIFT)) & TIM_BDTR_AOE_MASK)

#define TIM_BDTR_BKP_SHIFT                     (13)
#define TIM_BDTR_BKP_MASK                      (0x01U << TIM_BDTR_BKP_SHIFT)
#define TIM_BDTR_BKP(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_BDTR_BKP_SHIFT)) & TIM_BDTR_BKP_MASK)

#define TIM_BDTR_BKE_SHIFT                     (12)
#define TIM_BDTR_BKE_MASK                      (0x01U << TIM_BDTR_BKE_SHIFT)
#define TIM_BDTR_BKE(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_BDTR_BKE_SHIFT)) & TIM_BDTR_BKE_MASK)

#define TIM_BDTR_OSSR_SHIFT                    (11)
#define TIM_BDTR_OSSR_MASK                     (0x01U << TIM_BDTR_OSSR_SHIFT)
#define TIM_BDTR_OSSR(x)                       (((uint32_t)(((uint32_t)(x)) << TIM_BDTR_OSSR_SHIFT)) & TIM_BDTR_OSSR_MASK)

#define TIM_BDTR_OSSI_SHIFT                    (10)
#define TIM_BDTR_OSSI_MASK                     (0x01U << TIM_BDTR_OSSI_SHIFT)
#define TIM_BDTR_OSSI(x)                       (((uint32_t)(((uint32_t)(x)) << TIM_BDTR_OSSI_SHIFT)) & TIM_BDTR_OSSI_MASK)

#define TIM_BDTR_LOCK_SHIFT                    (8)
#define TIM_BDTR_LOCK_MASK                     (0x3U << TIM_BDTR_LOCK_SHIFT)
#define TIM_BDTR_LOCK(x)                       (((uint32_t)(((uint32_t)(x)) << TIM_BDTR_LOCK_SHIFT)) & TIM_BDTR_LOCK_MASK)

#define TIM_BDTR_DTG_SHIFT                     (0)
#define TIM_BDTR_DTG_MASK                      (0xFFU << TIM_BDTR_DTG_SHIFT)
#define TIM_BDTR_DTG(x)                        (((uint32_t)(((uint32_t)(x)) << TIM_BDTR_DTG_SHIFT)) & TIM_BDTR_DTG_MASK)

/*!
 * @brief TIM_DCR Register Bit Definition
 */

#define TIM_DCR_DBL_SHIFT                      (8)
#define TIM_DCR_DBL_MASK                       (0x1FU << TIM_DCR_DBL_SHIFT)
#define TIM_DCR_DBL(x)                         (((uint32_t)(((uint32_t)(x)) << TIM_DCR_DBL_SHIFT)) & TIM_DCR_DBL_MASK)

#define TIM_DCR_DBA_SHIFT                      (0)
#define TIM_DCR_DBA_MASK                       (0x1FU << TIM_DCR_DBA_SHIFT)
#define TIM_DCR_DBA(x)                         (((uint32_t)(((uint32_t)(x)) << TIM_DCR_DBA_SHIFT)) & TIM_DCR_DBA_MASK)

/*!
 * @brief TIM_DMAR Register Bit Definition
 */

#define TIM_DMAR_DMAB_SHIFT                    (0)
#define TIM_DMAR_DMAB_MASK                     (0xFFFFU << TIM_DMAR_DMAB_SHIFT)
#define TIM_DMAR_DMAB(x)                       (((uint32_t)(((uint32_t)(x)) << TIM_DMAR_DMAB_SHIFT)) & TIM_DMAR_DMAB_MASK)

/*!
 * @brief TIM_CCMR3 Register Bit Definition
 */

#define TIM_CCMR3_OC5CE_SHIFT                  (7)
#define TIM_CCMR3_OC5CE_MASK                   (0x01U << TIM_CCMR3_OC5CE_SHIFT)
#define TIM_CCMR3_OC5CE(x)                     (((uint32_t)(((uint32_t)(x)) << TIM_CCMR3_OC5CE_SHIFT)) & TIM_CCMR3_OC5CE_MASK)

#define TIM_CCMR3_OC5M_SHIFT                   (4)
#define TIM_CCMR3_OC5M_MASK                    (0x7U << TIM_CCMR3_OC5M_SHIFT)
#define TIM_CCMR3_OC5M(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_CCMR3_OC5M_SHIFT)) & TIM_CCMR3_OC5M_MASK)

#define TIM_CCMR3_OC5PE_SHIFT                  (3)
#define TIM_CCMR3_OC5PE_MASK                   (0x01U << TIM_CCMR3_OC5PE_SHIFT)
#define TIM_CCMR3_OC5PE(x)                     (((uint32_t)(((uint32_t)(x)) << TIM_CCMR3_OC5PE_SHIFT)) & TIM_CCMR3_OC5PE_MASK)

#define TIM_CCMR3_OC5FE_SHIFT                  (2)
#define TIM_CCMR3_OC5FE_MASK                   (0x01U << TIM_CCMR3_OC5FE_SHIFT)
#define TIM_CCMR3_OC5FE(x)                     (((uint32_t)(((uint32_t)(x)) << TIM_CCMR3_OC5FE_SHIFT)) & TIM_CCMR3_OC5FE_MASK)

/*!
 * @brief TIM_CCR5 Register Bit Definition
 */

#define TIM_CCR5_CCR5_SHIFT                    (0)
#define TIM_CCR5_CCR5_MASK                     (0xFFFFU << TIM_CCR5_CCR5_SHIFT)
#define TIM_CCR5_CCR5(x)                       (((uint32_t)(((uint32_t)(x)) << TIM_CCR5_CCR5_SHIFT)) & TIM_CCR5_CCR5_MASK)

/*!
 * @brief TIM_PDER Register Bit Definition
 */

#define TIM_PDER_CCR5SHIFTEN_SHIFT             (5)
#define TIM_PDER_CCR5SHIFTEN_MASK              (0x01U << TIM_PDER_CCR5SHIFTEN_SHIFT)
#define TIM_PDER_CCR5SHIFTEN(x)                (((uint32_t)(((uint32_t)(x)) << TIM_PDER_CCR5SHIFTEN_SHIFT)) & TIM_PDER_CCR5SHIFTEN_MASK)

#define TIM_PDER_CCR4SHIFTEN_SHIFT             (4)
#define TIM_PDER_CCR4SHIFTEN_MASK              (0x01U << TIM_PDER_CCR4SHIFTEN_SHIFT)
#define TIM_PDER_CCR4SHIFTEN(x)                (((uint32_t)(((uint32_t)(x)) << TIM_PDER_CCR4SHIFTEN_SHIFT)) & TIM_PDER_CCR4SHIFTEN_MASK)

#define TIM_PDER_CCR3SHIFTEN_SHIFT             (3)
#define TIM_PDER_CCR3SHIFTEN_MASK              (0x01U << TIM_PDER_CCR3SHIFTEN_SHIFT)
#define TIM_PDER_CCR3SHIFTEN(x)                (((uint32_t)(((uint32_t)(x)) << TIM_PDER_CCR3SHIFTEN_SHIFT)) & TIM_PDER_CCR3SHIFTEN_MASK)

#define TIM_PDER_CCR2SHIFTEN_SHIFT             (2)
#define TIM_PDER_CCR2SHIFTEN_MASK              (0x01U << TIM_PDER_CCR2SHIFTEN_SHIFT)
#define TIM_PDER_CCR2SHIFTEN(x)                (((uint32_t)(((uint32_t)(x)) << TIM_PDER_CCR2SHIFTEN_SHIFT)) & TIM_PDER_CCR2SHIFTEN_MASK)

#define TIM_PDER_CCR1SHIFTEN_SHIFT             (1)
#define TIM_PDER_CCR1SHIFTEN_MASK              (0x01U << TIM_PDER_CCR1SHIFTEN_SHIFT)
#define TIM_PDER_CCR1SHIFTEN(x)                (((uint32_t)(((uint32_t)(x)) << TIM_PDER_CCR1SHIFTEN_SHIFT)) & TIM_PDER_CCR1SHIFTEN_MASK)

#define TIM_PDER_CCDREPE_SHIFT                 (0)
#define TIM_PDER_CCDREPE_MASK                  (0x01U << TIM_PDER_CCDREPE_SHIFT)
#define TIM_PDER_CCDREPE(x)                    (((uint32_t)(((uint32_t)(x)) << TIM_PDER_CCDREPE_SHIFT)) & TIM_PDER_CCDREPE_MASK)

/*!
 * @brief TIM_CCRFALL Register Bit Definition
 */

#define TIM_CCRFALL_CCRFALL_SHIFT              (0)
#define TIM_CCRFALL_CCRFALL_MASK               (0xFFFFU << TIM_CCRFALL_CCRFALL_SHIFT)
#define TIM_CCRFALL_CCRFALL(x)                 (((uint32_t)(((uint32_t)(x)) << TIM_CCRFALL_CCRFALL_SHIFT)) & TIM_CCRFALL_CCRFALL_MASK)

/*!
 * @brief TIM_BKINF Register Bit Definition
 */

#define TIM_BKINF_BKINSEL_SHIFT                 (5)
#define TIM_BKINF_BKINSEL_MASK                  (0XFFFU << TIM_BKINF_BKINSEL_SHIFT)
#define TIM_BKINF_BKINSEL(x)                    (((uint32_t)(((uint32_t)(x)) << TIM_BKINF_BKINSEL_SHIFT)) & TIM_BKINF_BKINSEL_MASK)

#define TIM_BKINF_BKINF_SHIFT                   (1)
#define TIM_BKINF_BKINF_MASK                    (0XFU << TIM_BKINF_BKINF_SHIFT)
#define TIM_BKINF_BKINF(x)                      (((uint32_t)(((uint32_t)(x)) << TIM_BKINF_BKINF_SHIFT)) & TIM_BKINF_BKINF_MASK)

#define TIM_BKINF_BKINFE_SHIFT                  (0)
#define TIM_BKINF_BKINFE_MASK                   (0X01U << TIM_BKINF_BKINFE_SHIFT)
#define TIM_BKINF_BKINFE(x)                     (((uint32_t)(((uint32_t)(x)) << TIM_BKINF_BKINFE_SHIFT)) & TIM_BKINF_BKINFE_MASK)

/*!
 * @}
 */ /* end of group TIM1_Register_Masks */

/*!
 * @brief SPI_I2S_I2SCFGR Register Bit Definition
 */

#define SPI_I2S_I2SCFGR_HFDSEL_SHIFT             (13)
#define SPI_I2S_I2SCFGR_HFDSEL_MASK              (0X00U << SPI_I2S_I2SCFGR_HFDSEL_SHIFT)
#define SPI_I2S_I2SCFGR_HFDSEL(x)                (((uint32_t)(((uint32_t)(x)) << SPI_I2S_I2SCFGR_HFDSEL_SHIFT)) & SPI_I2S_I2SCFGR_HFDSEL_MASK)

#define SPI_I2S_I2SCFGR_MCKSEL_SHIFT             (12)
#define SPI_I2S_I2SCFGR_MCKSEL_MASK              (0X0U << SPI_I2S_I2SCFGR_MCKSEL_SHIFT)
#define SPI_I2S_I2SCFGR_MCKSEL(x)                (((uint32_t)(((uint32_t)(x)) << SPI_I2S_I2SCFGR_MCKSEL_SHIFT)) & SPI_I2S_I2SCFGR_MCKSEL_MASK)

#endif  /* __MM32F0144C_FEATURES_H__ */
