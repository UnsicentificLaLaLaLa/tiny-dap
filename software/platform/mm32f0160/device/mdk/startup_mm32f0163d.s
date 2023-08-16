;/* ------------------------------------------------------------------------- */
;/*  @file:    startup_mm32f0160.s                                            */
;/*  @purpose: CMSIS Cortex-M0 Core Device Startup File                       */
;/*                                                                           */
;/*  @version: 1.0                                                            */
;/*  @date:    2022-12-20                                                     */
;/*  @build:   b221220                                                        */
;/* ------------------------------------------------------------------------- */
;/*                                                                           */
;/* Copyright 2022 MindMotion                                                 */
;/* All rights reserved.                                                      */
;/*                                                                           */
;/* SPDX-License-Identifier: BSD-3-Clause                                     */
;/*****************************************************************************/
;/* Version: MDK for ARM Embedded Processors                                  */
;/*****************************************************************************/
                PRESERVE8
                THUMB

; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size
                IMPORT  |Image$$ARM_LIB_STACK$$ZI$$Limit|

__Vectors       DCD     |Image$$ARM_LIB_STACK$$ZI$$Limit|                       ;         Top of Stack
                DCD     Reset_Handler                                           ;         Reset Handler
                DCD     NMI_Handler                                             ; -14     NMI Handler
                DCD     HardFault_Handler                                       ; -13     Hard Fault Handler
                DCD     0                                                       ; -12     Reserved
                DCD     0                                                       ; -11     Reserved
                DCD     0                                                       ; -10     Reserved

                DCD     0                                                       ; -9      Reserved
                DCD     0                                                       ; -8      Reserved
                DCD     0                                                       ; -7      Reserved
                DCD     0                                                       ; -6      Reserved
                DCD     SVCall_Handler                                             ; -5      SVCall Handler
                DCD     0                                                       ; -4      Reserved
                DCD     0                                                       ; -3      Reserved
                DCD     PendSV_Handler                                          ; -2      PendSV Handler
                DCD     SysTick_Handler                                         ; -1      SysTick Handler  ; External Interrupts

                DCD     WWDG_IWDG_IRQHandler                                    ; 0   Window Watchdog and and Independce Watchdog
                DCD     PVD_IRQHandler                                          ; 1   PVD through EXTI Line detect
                DCD     RTC_BKP_IRQHandler                                      ; 2   RTC & BKP
                DCD     FLASH_IRQHandler                                        ; 3   Flash
                DCD     RCC_IRQHandler                                          ; 4   RCC & CRS
                DCD     EXTI0_1_IRQHandler                                      ; 5   EXTI 0_1
                DCD     EXTI3_2_IRQHandler                                      ; 6   EXTI 2_3
                DCD     EXTI15_4_IRQHandler                                     ; 7   EXTI 4_15
                DCD     HWDIV_IRQHandler                                        ; 8   HWDIV
                DCD     DMA1_CH1_IRQHandler                                     ; 9   DMA ch1
                DCD     DMA1_CH3_CH2_IRQHandler                                 ; 10  DMA ch2_ch3
                DCD     DMA1_CH7_CH4_IRQHandler                                 ; 11  DMA ch4_ch5
                DCD     ADC_COMP_IRQHandler                                     ; 12  ADC & COMP
                DCD     TIM1_BRK_UP_TRG_COM_IRQHandler                          ; 13  TIM1_BRK_UP_TRG_COM
                DCD     TIM1_CC_IRQHandler                                      ; 14  TIM1 CC
                DCD     TIM2_IRQHandler                                         ; 15  TIM2
                DCD     TIM3_IRQHandler                                         ; 16  TIM3
                DCD     LPUART_IRQHandler                                       ; 17  LPUART
                DCD     LPTIM_IRQHandler                                        ; 18  LPTIM
                DCD     TIM14_IRQHandler                                        ; 19  TIM4
                DCD     0                                                       ; 20  Reserved
                DCD     TIM16_IRQHandler                                        ; 21  TIM16
                DCD     TIM17_IRQHandler                                        ; 22  TIM17
                DCD     I2C1_IRQHandler                                         ; 23  I2C1
                DCD     I3C1_IRQHandler                                         ; 24  I3C1
                DCD     SPI1_IRQHandler                                         ; 25  SPI1
                DCD     SPI2_IRQHandler                                         ; 26  SPI2
                DCD     UART1_IRQHandler                                        ; 27  UART1
                DCD     UART2_IRQHandler                                        ; 28  UART2
                DCD     UART3_4_IRQHandler                                      ; 29  UART3 & UART4
                DCD     FLEXCAN_IRQHandler                                      ; 30 FLEXCAN
                DCD     USB_IRQHandler                                          ; 31 USB

__Vectors_End

__Vectors_Size  EQU     __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY

; Reset handler
Reset_Handler   PROC
                EXPORT  Reset_Handler              [WEAK]
                IMPORT  __main
                IMPORT  SystemInit
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP

; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler                [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler          [WEAK]
                B       .
                ENDP
SVCall_Handler     PROC
                EXPORT  SVCall_Handler                [WEAK]
                B       .
                ENDP

PendSV_Handler  PROC
                EXPORT  PendSV_Handler             [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler            [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  WWDG_IWDG_IRQHandler            [WEAK]
                EXPORT  PVD_IRQHandler                  [WEAK]
                EXPORT  RTC_BKP_IRQHandler              [WEAK]
                EXPORT  FLASH_IRQHandler                [WEAK]
                EXPORT  RCC_IRQHandler                  [WEAK]
                EXPORT  EXTI0_1_IRQHandler              [WEAK]
                EXPORT  EXTI3_2_IRQHandler              [WEAK]
                EXPORT  EXTI15_4_IRQHandler             [WEAK]
                EXPORT  HWDIV_IRQHandler                [WEAK]
                EXPORT  DMA1_CH1_IRQHandler             [WEAK]
                EXPORT  DMA1_CH3_CH2_IRQHandler         [WEAK]
                EXPORT  DMA1_CH7_CH4_IRQHandler         [WEAK]
                EXPORT  ADC_COMP_IRQHandler             [WEAK]
                EXPORT  TIM1_BRK_UP_TRG_COM_IRQHandler  [WEAK]
                EXPORT  TIM1_CC_IRQHandler              [WEAK]
                EXPORT  TIM2_IRQHandler                 [WEAK]
                EXPORT  TIM3_IRQHandler                 [WEAK]
                EXPORT  LPUART_IRQHandler               [WEAK]
                EXPORT  LPTIM_IRQHandler                [WEAK]
                EXPORT  TIM14_IRQHandler                [WEAK]
                EXPORT  TIM16_IRQHandler                [WEAK]
                EXPORT  TIM17_IRQHandler                [WEAK]
                EXPORT  I2C1_IRQHandler                 [WEAK]
                EXPORT  I3C1_IRQHandler                 [WEAK]
                EXPORT  SPI1_IRQHandler                 [WEAK]
                EXPORT  SPI2_IRQHandler                 [WEAK]
                EXPORT  UART1_IRQHandler                [WEAK]
                EXPORT  UART2_IRQHandler                [WEAK]
                EXPORT  UART3_4_IRQHandler              [WEAK]
                EXPORT  FLEXCAN_IRQHandler              [WEAK]
                EXPORT  USB_IRQHandler                  [WEAK]

WWDG_IWDG_IRQHandler
PVD_IRQHandler
RTC_BKP_IRQHandler
FLASH_IRQHandler
RCC_IRQHandler
EXTI0_1_IRQHandler
EXTI3_2_IRQHandler
EXTI15_4_IRQHandler
HWDIV_IRQHandler
DMA1_CH1_IRQHandler
DMA1_CH3_CH2_IRQHandler
DMA1_CH7_CH4_IRQHandler
ADC_COMP_IRQHandler
TIM1_BRK_UP_TRG_COM_IRQHandler
TIM1_CC_IRQHandler
TIM2_IRQHandler
TIM3_IRQHandler
LPUART_IRQHandler
LPTIM_IRQHandler
TIM14_IRQHandler
TIM16_IRQHandler
TIM17_IRQHandler
I2C1_IRQHandler
I3C1_IRQHandler
SPI1_IRQHandler
SPI2_IRQHandler
UART1_IRQHandler
UART2_IRQHandler
UART3_4_IRQHandler
FLEXCAN_IRQHandler
USB_IRQHandler

                B       .
                ENDP
                ALIGN
                END
