/*
 * Copyright 2023 MindMotion Microelectronics Co., Ltd.
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __HAL_I3C_H__
#define __HAL_I3C_H__

#include "hal_common.h"

/*!
 * @addtogroup I3C
 * @{
 */

/*!
 * @brief I3C driver version number.
 */
#define I3C_DRIVER_VERSION 0u /*!< i3c_0. */

/*!
 * @addtogroup I3C_STATUS
 * @{
 */
#define I3C_STATUS_BUS_START    I3C_STATUS_START_MASK       /*!< Status flag when I3C or I2C bus have a start or restart signal. */
#define I3C_STATUS_ADDR_MATCHED I3C_STATUS_MATED_MASK       /*!< Status flag when incoming header matched this device's I3C dynamic or I2C static address. */
#define I3C_STATUS_BUS_STOP     I3C_STATUS_STOP_MASK        /*!< Status flag when I3C or I2C bus have a stop signal. */
#define I3C_STATUS_RX_NOT_EMPTY I3C_STATUS_RXPEND_MASK      /*!< Status flag when Rx FIFO not empty. */
#define I3C_STATUS_TX_NOT_FULL  I3C_STATUS_TXNF_MASK        /*!< Status flag when Tx FIFO not empty. */
/*!
 * @}
 */

/*!
 * @addtogroup I3C_INT
 * @{
 */
#define I3C_INT_BUS_START       I3C_INTSET_STIE_MASK        /*!< Interrupt flag when I3C or I2C bus have a start or restart signal. */
#define I3C_INT_ADDR_MATCHED    I3C_INTSET_MATEDIE_MASK     /*!< Interrupt flag when incoming header matched this device's I3C dynamic or I2C static address. */
#define I3C_INT_XFER_STOP       I3C_INTSET_SPIE_MASK        /*!< Interrupt flag when I3C or I2C bus have a stop signal. */
#define I3C_INT_RX_NOT_EMPTY    I3C_INTSET_RXPIE_MASK       /*!< Interrupt flag when when Rx FIFO not empty. */
#define I3C_INT_TX_NOT_FULL     I3C_INTSET_TXSIE_MASK       /*!< Interrupt flag when Tx FIFO not empty. */
/*!
 * @}
 */

/*!
 * @brief This type of structure instance is used to keep the settings when calling the @ref I3C_InitSlave() to initialize the I3C module.
 */
typedef struct
{
    uint32_t ClockFreqHz;   /*!< Bus Clock Freq. */
    uint32_t StaticAddr;    /*!< I2C Static Address. */
} I3C_Slave_Init_Type;

/*!
 * @brief Initialize the I3C module.
 *
 * @param I3Cx I3C instance.
 * @param init Pointer to the initialization structure. See to @ref I3C_Init_Type.
 * @return None.
 */
void I3C_InitSlave(I3C_Type * I3Cx, I3C_Slave_Init_Type * init);

/*!
 * @brief Enable the I3C module.
 *
 * @param I3Cx I3C instance.
 * @param enable 'true' to enable the module, 'false' to disable the module.
 * @return None.
 */
void I3C_Enable(I3C_Type * I3Cx, bool enable);

/*!
 * @brief Get the current status flags of the I3C module.
 *
 * @param I3Cx I3C instance.
 * @return Status flags. See to @ref I3C_STATUS.
 */
uint32_t I3C_GetStatus(I3C_Type * I3Cx);

/*!
 * @brief Clear the status flags of the I3C module.
 *
 * @param I3Cx I3C instance.
 * @param status status flags. See to @ref I3C_STATUS.
 * @return None.
 */
void I3C_ClearStatus(I3C_Type * I3Cx, uint32_t status);

/*!
 * @brief Put the data into transmiter FIFO of the I3C module.
 *
 * @param UARTx I3C instance.
 * @param value Data value to be send through the transmiter.
 * @param is_last 'true' to send nak after send this data, mean this data is last data on this xfer process, 'false' to send ack after send this data.
 * @return None.
 */
void I3C_PutData(I3C_Type * I3Cx, uint8_t value, bool is_last);

/*!
 * @brief Get the data from receiver FIFO of the I3C module.
 *
 * @param I3Cx I3C instance.
 * @return The data value received from the receiver.
 */
uint8_t I3C_GetData(I3C_Type * I3Cx);

/*!
 * @brief Reset the Tx FIFO.
 *
 * The all Tx data will delete after reset Tx FIFO.
 *
 * @param I3Cx I3C instance.
 * @return None.
 */
void I3C_ResetTxFIFO(I3C_Type * I3Cx);

/*!
 * @brief Reset the Rx FIFO.
 *
 * The all Rx data will delete after reset Rx FIFO.
 *
 * @param I3Cx I3C instance.
 * @return None.
 */
void I3C_ResetRxFIFO(I3C_Type * I3Cx);

/*!
 * @brief Enable interrupts of the I3C module.
 *
 * @param I3Cx I3C instance.
 * @param interrupts Interrupt code masks. See to @ref I3C_INT.
 * @param enable 'true' to enable the indicated interrupts, 'false' to disable the indicated interrupts.
 * @return None.
 */
void I3C_EnableInterrupts(I3C_Type * I3Cx, uint32_t interrupts, bool enable);

/*!
 * @brief Read the current enabled interrupts the I3C module.
 *
 * @param I3Cx I3C instance.
 * @return The mask codes enabled interrupts. See to @ref I3C_INT
 */
uint32_t I3C_GetEnabledInterrupts(I3C_Type * I3Cx);

/*!
 * @brief Enable the Tx DMA trigger from the I3C module.
 *
 * The DMA trigger events are the same as the intertupts.
 *
 * @param I3Cx I3C instance.
 * @param enable 'true' to enable the DMA trigger, 'false' to disable the DMA trigger.
 * @return None.
 */
void I3C_EnableTxDMA(I3C_Type * I3Cx, bool enable);

/*!
 * @brief Enable the Rx DMA trigger from the I3C module.
 *
 * The DMA trigger events are the same as the intertupts.
 *
 * @param I3Cx I3C instance.
 * @param enable 'true' to enable the DMA trigger, 'false' to disable the DMA trigger.
 * @return None.
 */
void I3C_EnableRxDMA(I3C_Type * I3Cx, bool enable);

/*!
 * @brief Get the hardware Rx FIFO's address the I3C module.
 *
 * The return value of the address is most used with DMA module.
 *
 * @param I3Cx I3C instance.
 * @return The value of the address for I3C module's hardware Rx FIFO.
 */
uint32_t I3C_GetRxDataRegAddr(I3C_Type * I3Cx);

/*!
 * @brief Get the hardware Tx FIFO's address the I3C module.
 *
 * The return value of the address is most used with DMA module.
 *
 * @param I3Cx I3C instance.
 * @return The value of the address for I3C module's hardware Tx FIFO.
 */
uint32_t I3C_GetTxDataRegAddr(I3C_Type * I3Cx);

/*!
 *@}
 */

#endif /* __HAL_I3C_H__ */
