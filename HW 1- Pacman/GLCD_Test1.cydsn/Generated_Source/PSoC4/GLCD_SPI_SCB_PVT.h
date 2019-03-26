/***************************************************************************//**
* \file .h
* \version 3.20
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component.
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

#if !defined(CY_SCB_PVT_GLCD_SPI_SCB_H)
#define CY_SCB_PVT_GLCD_SPI_SCB_H

#include "GLCD_SPI_SCB.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define GLCD_SPI_SCB_SetI2CExtClkInterruptMode(interruptMask) GLCD_SPI_SCB_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define GLCD_SPI_SCB_ClearI2CExtClkInterruptSource(interruptMask) GLCD_SPI_SCB_CLEAR_INTR_I2C_EC(interruptMask)
#define GLCD_SPI_SCB_GetI2CExtClkInterruptSource()                (GLCD_SPI_SCB_INTR_I2C_EC_REG)
#define GLCD_SPI_SCB_GetI2CExtClkInterruptMode()                  (GLCD_SPI_SCB_INTR_I2C_EC_MASK_REG)
#define GLCD_SPI_SCB_GetI2CExtClkInterruptSourceMasked()          (GLCD_SPI_SCB_INTR_I2C_EC_MASKED_REG)

#if (!GLCD_SPI_SCB_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define GLCD_SPI_SCB_SetSpiExtClkInterruptMode(interruptMask) \
                                                                GLCD_SPI_SCB_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define GLCD_SPI_SCB_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                GLCD_SPI_SCB_CLEAR_INTR_SPI_EC(interruptMask)
    #define GLCD_SPI_SCB_GetExtSpiClkInterruptSource()                 (GLCD_SPI_SCB_INTR_SPI_EC_REG)
    #define GLCD_SPI_SCB_GetExtSpiClkInterruptMode()                   (GLCD_SPI_SCB_INTR_SPI_EC_MASK_REG)
    #define GLCD_SPI_SCB_GetExtSpiClkInterruptSourceMasked()           (GLCD_SPI_SCB_INTR_SPI_EC_MASKED_REG)
#endif /* (!GLCD_SPI_SCB_CY_SCBIP_V1) */

#if(GLCD_SPI_SCB_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void GLCD_SPI_SCB_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (GLCD_SPI_SCB_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if (GLCD_SPI_SCB_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_GLCD_SPI_SCB_CUSTOM_INTR_HANDLER)
    extern cyisraddress GLCD_SPI_SCB_customIntrHandler;
#endif /* !defined (CY_REMOVE_GLCD_SPI_SCB_CUSTOM_INTR_HANDLER) */
#endif /* (GLCD_SPI_SCB_SCB_IRQ_INTERNAL) */

extern GLCD_SPI_SCB_BACKUP_STRUCT GLCD_SPI_SCB_backup;

#if(GLCD_SPI_SCB_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 GLCD_SPI_SCB_scbMode;
    extern uint8 GLCD_SPI_SCB_scbEnableWake;
    extern uint8 GLCD_SPI_SCB_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 GLCD_SPI_SCB_mode;
    extern uint8 GLCD_SPI_SCB_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * GLCD_SPI_SCB_rxBuffer;
    extern uint8   GLCD_SPI_SCB_rxDataBits;
    extern uint32  GLCD_SPI_SCB_rxBufferSize;

    extern volatile uint8 * GLCD_SPI_SCB_txBuffer;
    extern uint8   GLCD_SPI_SCB_txDataBits;
    extern uint32  GLCD_SPI_SCB_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 GLCD_SPI_SCB_numberOfAddr;
    extern uint8 GLCD_SPI_SCB_subAddrSize;
#endif /* (GLCD_SPI_SCB_SCB_MODE_UNCONFIG_CONST_CFG) */

#if (! (GLCD_SPI_SCB_SCB_MODE_I2C_CONST_CFG || \
        GLCD_SPI_SCB_SCB_MODE_EZI2C_CONST_CFG))
    extern uint16 GLCD_SPI_SCB_IntrTxMask;
#endif /* (! (GLCD_SPI_SCB_SCB_MODE_I2C_CONST_CFG || \
              GLCD_SPI_SCB_SCB_MODE_EZI2C_CONST_CFG)) */


/***************************************
*        Conditional Macro
****************************************/

#if(GLCD_SPI_SCB_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define GLCD_SPI_SCB_SCB_MODE_I2C_RUNTM_CFG     (GLCD_SPI_SCB_SCB_MODE_I2C      == GLCD_SPI_SCB_scbMode)
    #define GLCD_SPI_SCB_SCB_MODE_SPI_RUNTM_CFG     (GLCD_SPI_SCB_SCB_MODE_SPI      == GLCD_SPI_SCB_scbMode)
    #define GLCD_SPI_SCB_SCB_MODE_UART_RUNTM_CFG    (GLCD_SPI_SCB_SCB_MODE_UART     == GLCD_SPI_SCB_scbMode)
    #define GLCD_SPI_SCB_SCB_MODE_EZI2C_RUNTM_CFG   (GLCD_SPI_SCB_SCB_MODE_EZI2C    == GLCD_SPI_SCB_scbMode)
    #define GLCD_SPI_SCB_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (GLCD_SPI_SCB_SCB_MODE_UNCONFIG == GLCD_SPI_SCB_scbMode)

    /* Defines wakeup enable */
    #define GLCD_SPI_SCB_SCB_WAKE_ENABLE_CHECK       (0u != GLCD_SPI_SCB_scbEnableWake)
#endif /* (GLCD_SPI_SCB_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!GLCD_SPI_SCB_CY_SCBIP_V1)
    #define GLCD_SPI_SCB_SCB_PINS_NUMBER    (7u)
#else
    #define GLCD_SPI_SCB_SCB_PINS_NUMBER    (2u)
#endif /* (!GLCD_SPI_SCB_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_GLCD_SPI_SCB_H) */


/* [] END OF FILE */
