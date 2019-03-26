/***************************************************************************//**
* \file GLCD_SPIM_SCB_SPI_UART_PVT.h
* \version 3.20
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component in SPI and UART modes.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_SPI_UART_PVT_GLCD_SPIM_SCB_H)
#define CY_SCB_SPI_UART_PVT_GLCD_SPIM_SCB_H

#include "GLCD_SPIM_SCB_SPI_UART.h"


/***************************************
*     Internal Global Vars
***************************************/

#if (GLCD_SPIM_SCB_INTERNAL_RX_SW_BUFFER_CONST)
    extern volatile uint32  GLCD_SPIM_SCB_rxBufferHead;
    extern volatile uint32  GLCD_SPIM_SCB_rxBufferTail;
    
    /**
    * \addtogroup group_globals
    * @{
    */
    
    /** Sets when internal software receive buffer overflow
     *  was occurred.
    */  
    extern volatile uint8   GLCD_SPIM_SCB_rxBufferOverflow;
    /** @} globals */
#endif /* (GLCD_SPIM_SCB_INTERNAL_RX_SW_BUFFER_CONST) */

#if (GLCD_SPIM_SCB_INTERNAL_TX_SW_BUFFER_CONST)
    extern volatile uint32  GLCD_SPIM_SCB_txBufferHead;
    extern volatile uint32  GLCD_SPIM_SCB_txBufferTail;
#endif /* (GLCD_SPIM_SCB_INTERNAL_TX_SW_BUFFER_CONST) */

#if (GLCD_SPIM_SCB_INTERNAL_RX_SW_BUFFER)
    extern volatile uint8 GLCD_SPIM_SCB_rxBufferInternal[GLCD_SPIM_SCB_INTERNAL_RX_BUFFER_SIZE];
#endif /* (GLCD_SPIM_SCB_INTERNAL_RX_SW_BUFFER) */

#if (GLCD_SPIM_SCB_INTERNAL_TX_SW_BUFFER)
    extern volatile uint8 GLCD_SPIM_SCB_txBufferInternal[GLCD_SPIM_SCB_TX_BUFFER_SIZE];
#endif /* (GLCD_SPIM_SCB_INTERNAL_TX_SW_BUFFER) */


/***************************************
*     Private Function Prototypes
***************************************/

void GLCD_SPIM_SCB_SpiPostEnable(void);
void GLCD_SPIM_SCB_SpiStop(void);

#if (GLCD_SPIM_SCB_SCB_MODE_SPI_CONST_CFG)
    void GLCD_SPIM_SCB_SpiInit(void);
#endif /* (GLCD_SPIM_SCB_SCB_MODE_SPI_CONST_CFG) */

#if (GLCD_SPIM_SCB_SPI_WAKE_ENABLE_CONST)
    void GLCD_SPIM_SCB_SpiSaveConfig(void);
    void GLCD_SPIM_SCB_SpiRestoreConfig(void);
#endif /* (GLCD_SPIM_SCB_SPI_WAKE_ENABLE_CONST) */

void GLCD_SPIM_SCB_UartPostEnable(void);
void GLCD_SPIM_SCB_UartStop(void);

#if (GLCD_SPIM_SCB_SCB_MODE_UART_CONST_CFG)
    void GLCD_SPIM_SCB_UartInit(void);
#endif /* (GLCD_SPIM_SCB_SCB_MODE_UART_CONST_CFG) */

#if (GLCD_SPIM_SCB_UART_WAKE_ENABLE_CONST)
    void GLCD_SPIM_SCB_UartSaveConfig(void);
    void GLCD_SPIM_SCB_UartRestoreConfig(void);
#endif /* (GLCD_SPIM_SCB_UART_WAKE_ENABLE_CONST) */


/***************************************
*         UART API Constants
***************************************/

/* UART RX and TX position to be used in GLCD_SPIM_SCB_SetPins() */
#define GLCD_SPIM_SCB_UART_RX_PIN_ENABLE    (GLCD_SPIM_SCB_UART_RX)
#define GLCD_SPIM_SCB_UART_TX_PIN_ENABLE    (GLCD_SPIM_SCB_UART_TX)

/* UART RTS and CTS position to be used in  GLCD_SPIM_SCB_SetPins() */
#define GLCD_SPIM_SCB_UART_RTS_PIN_ENABLE    (0x10u)
#define GLCD_SPIM_SCB_UART_CTS_PIN_ENABLE    (0x20u)


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Interrupt processing */
#define GLCD_SPIM_SCB_SpiUartEnableIntRx(intSourceMask)  GLCD_SPIM_SCB_SetRxInterruptMode(intSourceMask)
#define GLCD_SPIM_SCB_SpiUartEnableIntTx(intSourceMask)  GLCD_SPIM_SCB_SetTxInterruptMode(intSourceMask)
uint32  GLCD_SPIM_SCB_SpiUartDisableIntRx(void);
uint32  GLCD_SPIM_SCB_SpiUartDisableIntTx(void);


#endif /* (CY_SCB_SPI_UART_PVT_GLCD_SPIM_SCB_H) */


/* [] END OF FILE */
