/*
 * Copyright 2023 MindMotion Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __HAL_ADC_H__
#define __HAL_ADC_H__

#include "hal_common.h"

/*!
 * @addtogroup ADC
 * @{
 */

/*!
 * @brief ADC driver version number.
 */
#define ADC_DRIVER_VERSION 2u /*!< adc_2. */

/*!
 * @addtogroup ADC_STATUS
 * Define the status of ADC conversion.
 * @{
 */

#define ADC_STATUS_CONV_SLOT_DONE       (1u << 0u) /*!< Status flag when ADC slot conversion done. */
#define ADC_STATUS_CONV_SAMPLE_DONE     (1u << 1u) /*!< Status flag when ADC sample done. */
#define ADC_STATUS_CONV_SEQ_DONE        (1u << 2u) /*!< Status flag when ADC sequence conversion done. */
#define ADC_STATUS_CONV_COMPARE_DONE    (1u << 3u) /*!< Status flag when the ADC conversion result is compared with the set value. */
#define ADC_STATUS_JCONV_SLOT_DONE      (1u << 4u) /*!< Status flag when ADC inject slot conversion done. */
#define ADC_STATUS_JCONV_SAMPLE_DONE    (1u << 5u) /*!< Status flag when ADC inject sample done. */
#define ADC_STATUS_JCONV_SEQ_DONE       (1u << 6u) /*!< Status flag when ADC inject sequence conversion done. */

/*!
 * @}
 */

/*!
 * @addtogroup ADC_INT
 * ADC interrupt define.
 * @{
 */

#define ADC_INT_CONV_SLOT_DONE          (1u << 0u)  /*!< Interrupt when ADC slot conversion done. */
#define ADC_INT_CONV_SAMPLE_DONE        (1u << 1u)  /*!< Interrupt enable when ADC sample done. */
#define ADC_INT_CONV_SEQ_DONE           (1u << 2u)  /*!< Interrupt enable when ADC sequence conversion done. */
#define ADC_INT_CONV_COMPARE_DONE       (1u << 3u)  /*!< Interrupt enable when ADC the ADC conversion result is compared with the set value. */
#define ADC_INT_JCONV_SLOT_DONE         (1u << 4u)  /*!< Interrupt enable when the slot of ADC inject channel conversion done. */
#define ADC_INT_JCONV_SAMPLE_DONE       (1u << 5u)  /*!< Interrupt enable when ADC inject channel sample done. */
#define ADC_INT_JCONV_SEQ_DONE          (1u << 6u)  /*!< Interrupt enable when the sequence of ADC inject channel conversion done. */

/*!
 * @}
 */

/*!
 * @addtogroup ADC_RESULT_FLAGS
 * Define ADC Convert result flags.
 * @{
 */

#define ADC_CONV_RESULT_FLAG_OVERRUN (1u << 0u) /*!< Result flag when adc conversion result is overrun. */
#define ADC_CONV_RESULT_FLAG_VALID   (1u << 1u) /*!< Result flag when adc conversion result valid. */

/*!
 * @}
 */


/*!
 * @brief ADC Resolution type.
 *
 * Select ADC conversion data resolution.
 */
typedef enum
{
    ADC_Resolution_Alt0  = 0u,  /*!< source 0 as a resolution source for ADC. */
    ADC_Resolution_Alt1  = 1u,  /*!< source 1 as a resolution source for ADC. */
    ADC_Resolution_Alt2  = 2u,  /*!< source 2 as a resolution source for ADC. */
    ADC_Resolution_Alt3  = 3u,  /*!< source 3 as a resolution source for ADC. */
    ADC_Resolution_Alt4  = 4u,  /*!< source 4 as a resolution source for ADC. */
} ADC_Resolution_Type;

/*!
 * @brief ADC Prescaler type.
 *
 * Select the prescaler of the bus as the adc clock.
 */
typedef enum
{
    ADC_ClockDiv_2  = 0u,   /*!< ADC clock divided by 2.  */
    ADC_ClockDiv_3  = 1u,   /*!< ADC clock divided by 3.  */
    ADC_ClockDiv_4  = 2u,   /*!< ADC clock divided by 4.  */
    ADC_ClockDiv_5  = 3u,   /*!< ADC clock divided by 5.  */
    ADC_ClockDiv_6  = 4u,   /*!< ADC clock divided by 6.  */
    ADC_ClockDiv_7  = 5u,   /*!< ADC clock divided by 7.  */
    ADC_ClockDiv_8  = 6u,   /*!< ADC clock divided by 8.  */
    ADC_ClockDiv_9  = 7u,   /*!< ADC clock divided by 9.  */
    ADC_ClockDiv_10 = 8u,   /*!< ADC clock divided by 10. */
    ADC_ClockDiv_11 = 9u,   /*!< ADC clock divided by 11. */
    ADC_ClockDiv_12 = 10u,  /*!< ADC clock divided by 12. */
    ADC_ClockDiv_13 = 11u,  /*!< ADC clock divided by 13. */
    ADC_ClockDiv_14 = 12u,  /*!< ADC clock divided by 14. */
    ADC_ClockDiv_15 = 13u,  /*!< ADC clock divided by 15. */
    ADC_ClockDiv_16 = 14u,  /*!< ADC clock divided by 16. */
    ADC_ClockDiv_17 = 15u,  /*!< ADC clock divided by 17. */
} ADC_ClockDiv_Type;

/*!
 * @brief ADC HwTriggerEdge type.
 *
 * Use hardware trigger in ADC.
 */
typedef enum
{
    ADC_HwTriggerEdge_Both     = 0u,   /*!< Both edge trigger.        */
    ADC_HwTriggerEdge_Falling  = 1u,   /*!< Falling edge trigger.     */
    ADC_HwTriggerEdge_Rising   = 2u,   /*!< Rising edge trigger.      */
    ADC_HwTriggerEdge_Disabled = 3u,   /*!< Edge trigger is disabled. */
} ADC_HwTriggerEdge_Type;

/*!
 * @brief ADC HwTriggerDelayCycle type.
 *
 * After the hardware trigger signal is generated, delay N PCLK2 clock cycles before starting the first sample.
 */
typedef enum
{
    ADC_HwTriggerDelayCycle_0   = 0u,    /*!< Delay 0 cycle.    */
    ADC_HwTriggerDelayCycle_4   = 1u,    /*!< Delay 4  cycle.   */
    ADC_HwTriggerDelayCycle_16  = 2u,    /*!< Delay 16 cycle.   */
    ADC_HwTriggerDelayCycle_32  = 3u,    /*!< Delay 32 cycle.   */
    ADC_HwTriggerDelayCycle_64  = 4u,    /*!< Delay 64 cycle.   */
    ADC_HwTriggerDelayCycle_128 = 5u,    /*!< Delay 128 cycle.  */
    ADC_HwTriggerDelayCycle_256 = 6u,    /*!< Delay 256 cycle.  */
    ADC_HwTriggerDelayCycle_512 = 7u,    /*!< Delay 512 cycle.  */
} ADC_HwTriggerDelayCycle_Type;

/*!
 * @brief ADC Align type.
 *
 * Choose to store the converted data as left-aligned or right-aligned.
 */
typedef enum
{
    ADC_Align_Right = 0u,     /*!< Data right align. */
    ADC_Align_Left  = 1u,     /*!< Data left align.  */
} ADC_Align_Type;

/*!
 * @brief ADC SeqFixedDirection type.
 *
 * In single-cycle scan or continuous scan mode, set the order of scan channels.
 */
typedef enum
{
    ADC_SeqFixedDirection_LowFirst  = 0u,   /*!< ADC scan direction from low channel to high channel. */
    ADC_SeqFixedDirection_HighFirst = 1u,   /*!< ADC scan direction from high channel to low channel. */
} ADC_SeqFixedDirection_Type;

/*!
 * @brief ADC ConvMode type.
 *
 * Select the adc channel or sequence convert mode.
 */
typedef enum
{
    ADC_ConvMode_SingleSlot = 0u,    /*!< Run the conversion by channel.  */
    ADC_ConvMode_SeqOneTime = 1u,    /*!< Run the conversion by sequence once. */
    ADC_ConvMode_SeqContinues = 2u,  /*!< Run the conversion by sequence again and again. */
} ADC_ConvMode_Type;

/*!
 * @brief ADC SampleTime type.
 *
 * Sampling time of ADC channel conversion.
 */
typedef enum
{
    ADC_SampleTime_Alt0 = 0u,    /*!< Channel sample time mode  0 . */
    ADC_SampleTime_Alt1 = 1u,    /*!< Channel sample time mode  1 . */
    ADC_SampleTime_Alt2 = 2u,    /*!< Channel sample time mode  2 . */
    ADC_SampleTime_Alt3 = 3u,    /*!< Channel sample time mode  3 . */
    ADC_SampleTime_Alt4 = 4u,    /*!< Channel sample time mode  4 . */
    ADC_SampleTime_Alt5 = 5u,    /*!< Channel sample time mode  5 . */
    ADC_SampleTime_Alt6 = 6u,    /*!< Channel sample time mode  6 . */
    ADC_SampleTime_Alt7 = 7u,    /*!< Channel sample time mode  7 . */
    ADC_SampleTime_Alt8 = 8u,    /*!< Channel sample time mode  8 . */
    ADC_SampleTime_Alt9 = 9u,    /*!< Channel sample time mode  9 . */
    ADC_SampleTime_Alt10 = 10u,  /*!< Channel sample time mode  10. */
    ADC_SampleTime_Alt11 = 11u,  /*!< Channel sample time mode  11. */
    ADC_SampleTime_Alt12 = 12u,  /*!< Channel sample time mode  12. */
    ADC_SampleTime_Alt13 = 13u,  /*!< Channel sample time mode  13. */
    ADC_SampleTime_Alt14 = 14u,  /*!< Channel sample time mode  14. */
    ADC_SampleTime_Alt15 = 15u,  /*!< Channel sample time mode  15. */
} ADC_SampleTime_Type;

/*!
 * @brief This type of structure instance is used to keep the settings
 *  when calling the @ref ADC_Init() to initialize the ADC module.
 */
typedef struct
{
    ADC_Resolution_Type Resolution;             /*!< Specify the available bits for the conversion result data. */
    ADC_ClockDiv_Type ClockDiv;                 /*!< Specify the adc clock predivison. */
    ADC_Align_Type Align;                       /*!< Specify the data alignment. */
    ADC_ConvMode_Type ConvMode;                 /*!< Specify the adc conversion mode. */
} ADC_Init_Type;

/*!
 * @brief This type of structure instance is used to keep the settings
 *  when calling the @ref ADC_EnableHwTrigger() to initialize the ADC hardware trigger module.
 */
typedef struct
{
    ADC_HwTriggerEdge_Type       Edge;        /*!< Select the trigger edge. */
    ADC_HwTriggerDelayCycle_Type DelayCycle;  /*!< Select the hardware trigger shift sample. */
} ADC_HwTriggerConf_Type;

/*!
 * @brief This type of structure instance is used to keep the settings
 * when calling the @ref ADC_EnableHwComp() to enable the ADC windows compare mode.
 */
typedef struct
{
    uint32_t ChnNum;        /*!< Select the channel number binding to the compare. */
    uint32_t HighLimit;     /*!< The comparator high limit. */
    uint32_t LowLimit;      /*!< The comparator low limit. */
} ADC_HwCompConf_Type;

/*!
 * @brief Initialize the ADC module.
 *
 * @param ADCx ADC instance.
 * @param init  Pointer to the initialization structure. See to @ref ADC_Init_Type.
 * @return None.
 */
void       ADC_Init(ADC_Type * ADCx, ADC_Init_Type * init);

/*!
 * @brief Enable the ADC module.
 *
 * The ADC module should be enabled before conversion data.
 *
 * @param ADCx ADC instance.
 * @param enable 'true' to enable the module, 'false' to disable the module.
 * @return None.
 */
void       ADC_Enable(ADC_Type * ADCx, bool enable);

/*!
 * @brief Enable Temperature sensor from the ADC module.
 *
 * The module should be enabled when Using the built-in temperature sensor to
 * detect temperature changes inside the device.
 *
 * @param ADCx ADC instance.
 * @param enable 'true' to enable the module, 'false' to disable the module.
 * @return None.
 */
void       ADC_EnableTempSensor(ADC_Type * ADCx, bool enable);

/*!
 * @brief Enable Voltage sensor from the ADC module.
 *
 * The module should be enabled when using internal reference voltage.
 *
 * @param ADCx ADC instance.
 * @param enable 'true' to enable the module, 'false' to disable the module.
 * @return None.
 */
void       ADC_EnableVoltSensor(ADC_Type * ADCx, bool enable);

/*!
 * @brief Enable the DMA from the ADC module.
 *
 * @param ADCx ADC instance.
 * @param enable 'true' to enable the DMA, 'false' to disable the DMA.
 * @return None.
 */
void       ADC_EnableDMA(ADC_Type * ADCx, bool enable);

/*!
 * @brief Enable interrupts of the ADC module.
 *
 * @param ADCx ADC instance.
 * @param interrupts Interrupt code masks.
 * @param enable 'true' to enable the indicated interrupts, 'false' to disable the indicated interrupts.
 * @return None.
 */
void       ADC_EnableInterrupts(ADC_Type * ADCx, uint32_t interrupts, bool enable);

/*!
 * @brief Get the current status flags of the ADC module.
 *
 * @param ADCx ADC instance.
 * @return Status flags.
 */
uint32_t   ADC_GetStatus(ADC_Type * ADCx);

/*!
 * @brief Clear the status flags of the ADC module.
 *
 * @param ADCx ADC instance.
 * @param flags  The mask codes of the indicated interrupt flags to be cleared.
 * @return None.
 */
void       ADC_ClearStatus(ADC_Type * ADCx, uint32_t flags);

/*!
 * @brief Get the channel convert data from the ADC module.
 *
 * @param ADCx ADC instance.
 * @param channel Conversion channel pointer, the channel currently being converted .
 * @param flags The ADC convert result flags. See to @ref ADC_RESULT_FLAGS.
 * @return The data value.
 */
uint32_t   ADC_GetConvResult(ADC_Type * ADCx, uint32_t * channel, uint32_t * flags);

/*!
 * @brief Get the indication slot conversion data from the ADC module.
 *
 * @param ADCx ADC instance.
 * @param slot the adc conversion slot.
 * @param flags The ADC convert result flags. See to @ref ADC_RESULT_FLAGS.
 * @return The data value.
 */
uint32_t   ADC_GetSlotConvResult(ADC_Type * ADCx, uint32_t slot, uint32_t * flags);

/*!
 * @brief Get the previous conversion result of the current conversion channel.
 *
 * @param ADCx ADC instance.
 * @param channel Conversion channel pointer,the channel currently being converted .
 * @param flags The ADC convert result flags. See to @ref ADC_RESULT_FLAGS.
 * @return The data value.
 */
uint32_t   ADC_GetLastConvResult(ADC_Type * ADCx, uint32_t * channel, uint32_t * flags);

/*!
 * @brief Get the inject channel convert data from the ADC module.
 *
 * @param ADCx ADC instance.
 * @param channel The convert channel,the channel currently being converted.
 * @param flags The ADC convert result flags. See to @ref ADC_RESULT_FLAGS.
 * @return The data value.
 */
uint32_t   ADC_GetExtConvResult(ADC_Type * ADCx, uint32_t * channel, uint32_t * flags);

/*!
 * @brief Get the indication external slot convert data from the ADC module.
 *
 * @param ADCx ADC instance.
 * @param slot the adc external slot.
 * @param flags The ADC convert result flags. See to @ref ADC_RESULT_FLAGS.
 * @return The data value.
 */
uint32_t   ADC_GetExtSlotConvResult(ADC_Type * ADCx, uint32_t slot, uint32_t * flags);

/*!
 * @brief Configuration channel sample time of the ADC module.
 *
 * @param ADCx ADC instance.
 * @param channel the adc convert channel.
 * @param sampletime  the adc channel sample time
 * @return None.
 */
void       ADC_SetChnSampleTime(ADC_Type * ADCx, uint32_t channel, ADC_SampleTime_Type sample_time);

/*!
 * @brief Enable hardware trigger from the ADC module.
 *
 * The ADC module should be enabled before using hardware trrigger function.
 * it also have interrupt.
 *
 * @param ADCx ADC instance.
 * @param conf Select the hardware trigger source. See to @ref ADC_HwTriggerConf_Type.
 * @return None.
 */
void       ADC_EnableHwTrigger(ADC_Type * ADCx, ADC_HwTriggerConf_Type * conf);

/*!
 * @brief Enable fixed slot sequence conversion from the ADC module.
 *
 * The ADC module should be enabled before regular sequence function.
 * it also have interrupt.
 *
 * @param ADCx ADC instance.
 * @param seq_slot the fixed channel, it can be ascending or descending.
 * @param seq_direction the sequence fixed scan direction.
 * @return None.
 */
void      ADC_EnableSeqSlotFixed(ADC_Type * ADCx, uint32_t seq_slot, ADC_SeqFixedDirection_Type dir);


/*!
 * @brief Enable sequence conversion from the ADC module.
 *
 * The ADC module should be enabled before Any sequence function.
 * it also have interrupt.
 *
 * @param ADCx ADC instance.
 * @param slot_idx the sequence slot index.
 * @param channel the conversion channel, it will be placed in each slot.
 * @return None.
 */
void       ADC_EnableSeqSlot(ADC_Type * ADCx, uint32_t slot_idx, uint32_t channel);

/*!
 * @brief Enable external sequence conversion from the ADC module.
 *
 * The ADC module should be enabled before sequence conversion function.
 * it also have interrupt.
 *
 * @param ADCx ADC instance.
 * @param slot_idx the sequence slot index.
 * @param channel the conversion channel, it will be placed in each slot.
 * @return None.
 */
void       ADC_EnableExtSeqSlot(ADC_Type * ADCx, uint32_t slot_idx, uint32_t channel);

/*!
 * @brief Enable Inject sequence auto conversion from the ADC module.
 * the sequence conversion done, the inject sequence start conversion.
 *
 * @param ADCx ADC instance.
 * @param enable 'true' to enable the ADC start inject sequence convert, 'false' to disable.
 * @return None.
 */
void       ADC_EnableAutoExtSeqSlot(ADC_Type * ADCx, bool enable);

/*!
 * @brief Do external chanenel sequence conversion software trigger.
 * the software triggers the injection channel sequence to begin the transformation.
 *
 * @param ADCx ADC instance.
 * @param enable 'true' to enable the ADC start inject channel convert, 'false' to disable.
 * @return None.
 */
void       ADC_DoExtSeqSlotSwTrigger(ADC_Type * ADCx, bool enable);

/*!
 * @brief Set inject chanenel data offset compensation.
 * the conversion results are calibrated by setting the error offset.
 *
 * @param ADCx ADC instance.
 * @param value difference between actual input value and converted value.
 * @param slot the inject slot.
 * @return None.
 */
void       ADC_SetExtSlotCalibParam(ADC_Type * ADCx, uint32_t slot, uint32_t value);

/*!
 * @brief Enable window comparison from the ADC module.
 *
 * The ADC module should be enabled before using analog watchdog function.
 * it also have interrupt.
 *
 * @param ADCx ADC instance.
 * @param conf Pointer to the initialization structure. See to @ref ADC_HwCompConf_Type.
 * @return None.
 */
void       ADC_EnableHwComp(ADC_Type * ADCx, ADC_HwCompConf_Type * conf);

/*!
 * @brief Do soft trigger.
 * In single mode or single cycle mode, ADST automatically clears the hardware after conversion.
 * In continuous scan mode, ADST is cleared by software or system reset, otherwise A/D conversion will continue.
 *
 * @param ADCx ADC instance.
 * @param enable 'true' to enable the ADC start convert, 'false' to disable.
 * @return None.
 */
void       ADC_DoSwTrigger(ADC_Type * ADCx, bool enable);

/*!
 * @brief Reset all the slot conversion and reset the channel configuration.
 *
 * @param ADCx ADC instance.
 * @return None.
 */

void       ADC_ResetAllSlot(ADC_Type * ADCx);

/*!
 *@}
 */

#endif /*__HAL_ADC_H__. */
