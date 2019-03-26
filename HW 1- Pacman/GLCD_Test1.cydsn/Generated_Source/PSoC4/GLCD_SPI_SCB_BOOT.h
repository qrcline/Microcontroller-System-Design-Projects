/***************************************************************************//**
* \file GLCD_SPI_SCB_BOOT.h
* \version 3.20
*
* \brief
*  This file provides constants and parameter values of the bootloader
*  communication APIs for the SCB Component.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2014-2016, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_BOOT_GLCD_SPI_SCB_H)
#define CY_SCB_BOOT_GLCD_SPI_SCB_H

#include "GLCD_SPI_SCB_PVT.h"

#if (GLCD_SPI_SCB_SCB_MODE_I2C_INC)
    #include "GLCD_SPI_SCB_I2C.h"
#endif /* (GLCD_SPI_SCB_SCB_MODE_I2C_INC) */

#if (GLCD_SPI_SCB_SCB_MODE_EZI2C_INC)
    #include "GLCD_SPI_SCB_EZI2C.h"
#endif /* (GLCD_SPI_SCB_SCB_MODE_EZI2C_INC) */

#if (GLCD_SPI_SCB_SCB_MODE_SPI_INC || GLCD_SPI_SCB_SCB_MODE_UART_INC)
    #include "GLCD_SPI_SCB_SPI_UART.h"
#endif /* (GLCD_SPI_SCB_SCB_MODE_SPI_INC || GLCD_SPI_SCB_SCB_MODE_UART_INC) */


/***************************************
*  Conditional Compilation Parameters
****************************************/

/* Bootloader communication interface enable */
#define GLCD_SPI_SCB_BTLDR_COMM_ENABLED ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_GLCD_SPI_SCB) || \
                                             (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

/* Enable I2C bootloader communication */
#if (GLCD_SPI_SCB_SCB_MODE_I2C_INC)
    #define GLCD_SPI_SCB_I2C_BTLDR_COMM_ENABLED     (GLCD_SPI_SCB_BTLDR_COMM_ENABLED && \
                                                            (GLCD_SPI_SCB_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             GLCD_SPI_SCB_I2C_SLAVE_CONST))
#else
     #define GLCD_SPI_SCB_I2C_BTLDR_COMM_ENABLED    (0u)
#endif /* (GLCD_SPI_SCB_SCB_MODE_I2C_INC) */

/* EZI2C does not support bootloader communication. Provide empty APIs */
#if (GLCD_SPI_SCB_SCB_MODE_EZI2C_INC)
    #define GLCD_SPI_SCB_EZI2C_BTLDR_COMM_ENABLED   (GLCD_SPI_SCB_BTLDR_COMM_ENABLED && \
                                                         GLCD_SPI_SCB_SCB_MODE_UNCONFIG_CONST_CFG)
#else
    #define GLCD_SPI_SCB_EZI2C_BTLDR_COMM_ENABLED   (0u)
#endif /* (GLCD_SPI_SCB_EZI2C_BTLDR_COMM_ENABLED) */

/* Enable SPI bootloader communication */
#if (GLCD_SPI_SCB_SCB_MODE_SPI_INC)
    #define GLCD_SPI_SCB_SPI_BTLDR_COMM_ENABLED     (GLCD_SPI_SCB_BTLDR_COMM_ENABLED && \
                                                            (GLCD_SPI_SCB_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             GLCD_SPI_SCB_SPI_SLAVE_CONST))
#else
        #define GLCD_SPI_SCB_SPI_BTLDR_COMM_ENABLED (0u)
#endif /* (GLCD_SPI_SCB_SPI_BTLDR_COMM_ENABLED) */

/* Enable UART bootloader communication */
#if (GLCD_SPI_SCB_SCB_MODE_UART_INC)
       #define GLCD_SPI_SCB_UART_BTLDR_COMM_ENABLED    (GLCD_SPI_SCB_BTLDR_COMM_ENABLED && \
                                                            (GLCD_SPI_SCB_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             (GLCD_SPI_SCB_UART_RX_DIRECTION && \
                                                              GLCD_SPI_SCB_UART_TX_DIRECTION)))
#else
     #define GLCD_SPI_SCB_UART_BTLDR_COMM_ENABLED   (0u)
#endif /* (GLCD_SPI_SCB_UART_BTLDR_COMM_ENABLED) */

/* Enable bootloader communication */
#define GLCD_SPI_SCB_BTLDR_COMM_MODE_ENABLED    (GLCD_SPI_SCB_I2C_BTLDR_COMM_ENABLED   || \
                                                     GLCD_SPI_SCB_SPI_BTLDR_COMM_ENABLED   || \
                                                     GLCD_SPI_SCB_EZI2C_BTLDR_COMM_ENABLED || \
                                                     GLCD_SPI_SCB_UART_BTLDR_COMM_ENABLED)


/***************************************
*        Function Prototypes
***************************************/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (GLCD_SPI_SCB_I2C_BTLDR_COMM_ENABLED)
    /* I2C Bootloader physical layer functions */
    void GLCD_SPI_SCB_I2CCyBtldrCommStart(void);
    void GLCD_SPI_SCB_I2CCyBtldrCommStop (void);
    void GLCD_SPI_SCB_I2CCyBtldrCommReset(void);
    cystatus GLCD_SPI_SCB_I2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus GLCD_SPI_SCB_I2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map I2C specific bootloader communication APIs to SCB specific APIs */
    #if (GLCD_SPI_SCB_SCB_MODE_I2C_CONST_CFG)
        #define GLCD_SPI_SCB_CyBtldrCommStart   GLCD_SPI_SCB_I2CCyBtldrCommStart
        #define GLCD_SPI_SCB_CyBtldrCommStop    GLCD_SPI_SCB_I2CCyBtldrCommStop
        #define GLCD_SPI_SCB_CyBtldrCommReset   GLCD_SPI_SCB_I2CCyBtldrCommReset
        #define GLCD_SPI_SCB_CyBtldrCommRead    GLCD_SPI_SCB_I2CCyBtldrCommRead
        #define GLCD_SPI_SCB_CyBtldrCommWrite   GLCD_SPI_SCB_I2CCyBtldrCommWrite
    #endif /* (GLCD_SPI_SCB_SCB_MODE_I2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (GLCD_SPI_SCB_I2C_BTLDR_COMM_ENABLED) */


#if defined(CYDEV_BOOTLOADER_IO_COMP) && (GLCD_SPI_SCB_EZI2C_BTLDR_COMM_ENABLED)
    /* Bootloader physical layer functions */
    void GLCD_SPI_SCB_EzI2CCyBtldrCommStart(void);
    void GLCD_SPI_SCB_EzI2CCyBtldrCommStop (void);
    void GLCD_SPI_SCB_EzI2CCyBtldrCommReset(void);
    cystatus GLCD_SPI_SCB_EzI2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus GLCD_SPI_SCB_EzI2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map EZI2C specific bootloader communication APIs to SCB specific APIs */
    #if (GLCD_SPI_SCB_SCB_MODE_EZI2C_CONST_CFG)
        #define GLCD_SPI_SCB_CyBtldrCommStart   GLCD_SPI_SCB_EzI2CCyBtldrCommStart
        #define GLCD_SPI_SCB_CyBtldrCommStop    GLCD_SPI_SCB_EzI2CCyBtldrCommStop
        #define GLCD_SPI_SCB_CyBtldrCommReset   GLCD_SPI_SCB_EzI2CCyBtldrCommReset
        #define GLCD_SPI_SCB_CyBtldrCommRead    GLCD_SPI_SCB_EzI2CCyBtldrCommRead
        #define GLCD_SPI_SCB_CyBtldrCommWrite   GLCD_SPI_SCB_EzI2CCyBtldrCommWrite
    #endif /* (GLCD_SPI_SCB_SCB_MODE_EZI2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (GLCD_SPI_SCB_EZI2C_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (GLCD_SPI_SCB_SPI_BTLDR_COMM_ENABLED)
    /* SPI Bootloader physical layer functions */
    void GLCD_SPI_SCB_SpiCyBtldrCommStart(void);
    void GLCD_SPI_SCB_SpiCyBtldrCommStop (void);
    void GLCD_SPI_SCB_SpiCyBtldrCommReset(void);
    cystatus GLCD_SPI_SCB_SpiCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus GLCD_SPI_SCB_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map SPI specific bootloader communication APIs to SCB specific APIs */
    #if (GLCD_SPI_SCB_SCB_MODE_SPI_CONST_CFG)
        #define GLCD_SPI_SCB_CyBtldrCommStart   GLCD_SPI_SCB_SpiCyBtldrCommStart
        #define GLCD_SPI_SCB_CyBtldrCommStop    GLCD_SPI_SCB_SpiCyBtldrCommStop
        #define GLCD_SPI_SCB_CyBtldrCommReset   GLCD_SPI_SCB_SpiCyBtldrCommReset
        #define GLCD_SPI_SCB_CyBtldrCommRead    GLCD_SPI_SCB_SpiCyBtldrCommRead
        #define GLCD_SPI_SCB_CyBtldrCommWrite   GLCD_SPI_SCB_SpiCyBtldrCommWrite
    #endif /* (GLCD_SPI_SCB_SCB_MODE_SPI_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (GLCD_SPI_SCB_SPI_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (GLCD_SPI_SCB_UART_BTLDR_COMM_ENABLED)
    /* UART Bootloader physical layer functions */
    void GLCD_SPI_SCB_UartCyBtldrCommStart(void);
    void GLCD_SPI_SCB_UartCyBtldrCommStop (void);
    void GLCD_SPI_SCB_UartCyBtldrCommReset(void);
    cystatus GLCD_SPI_SCB_UartCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus GLCD_SPI_SCB_UartCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map UART specific bootloader communication APIs to SCB specific APIs */
    #if (GLCD_SPI_SCB_SCB_MODE_UART_CONST_CFG)
        #define GLCD_SPI_SCB_CyBtldrCommStart   GLCD_SPI_SCB_UartCyBtldrCommStart
        #define GLCD_SPI_SCB_CyBtldrCommStop    GLCD_SPI_SCB_UartCyBtldrCommStop
        #define GLCD_SPI_SCB_CyBtldrCommReset   GLCD_SPI_SCB_UartCyBtldrCommReset
        #define GLCD_SPI_SCB_CyBtldrCommRead    GLCD_SPI_SCB_UartCyBtldrCommRead
        #define GLCD_SPI_SCB_CyBtldrCommWrite   GLCD_SPI_SCB_UartCyBtldrCommWrite
    #endif /* (GLCD_SPI_SCB_SCB_MODE_UART_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (GLCD_SPI_SCB_UART_BTLDR_COMM_ENABLED) */

/**
* \addtogroup group_bootloader
* @{
*/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (GLCD_SPI_SCB_BTLDR_COMM_ENABLED)
    #if (GLCD_SPI_SCB_SCB_MODE_UNCONFIG_CONST_CFG)
        /* Bootloader physical layer functions */
        void GLCD_SPI_SCB_CyBtldrCommStart(void);
        void GLCD_SPI_SCB_CyBtldrCommStop (void);
        void GLCD_SPI_SCB_CyBtldrCommReset(void);
        cystatus GLCD_SPI_SCB_CyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
        cystatus GLCD_SPI_SCB_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    #endif /* (GLCD_SPI_SCB_SCB_MODE_UNCONFIG_CONST_CFG) */

    /* Map SCB specific bootloader communication APIs to common APIs */
    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_GLCD_SPI_SCB)
        #define CyBtldrCommStart    GLCD_SPI_SCB_CyBtldrCommStart
        #define CyBtldrCommStop     GLCD_SPI_SCB_CyBtldrCommStop
        #define CyBtldrCommReset    GLCD_SPI_SCB_CyBtldrCommReset
        #define CyBtldrCommWrite    GLCD_SPI_SCB_CyBtldrCommWrite
        #define CyBtldrCommRead     GLCD_SPI_SCB_CyBtldrCommRead
    #endif /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_GLCD_SPI_SCB) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (GLCD_SPI_SCB_BTLDR_COMM_ENABLED) */

/** @} group_bootloader */

/***************************************
*           API Constants
***************************************/

/* Timeout unit in milliseconds */
#define GLCD_SPI_SCB_WAIT_1_MS  (1u)

/* Return number of bytes to copy into bootloader buffer */
#define GLCD_SPI_SCB_BYTES_TO_COPY(actBufSize, bufSize) \
                            ( ((uint32)(actBufSize) < (uint32)(bufSize)) ? \
                                ((uint32) (actBufSize)) : ((uint32) (bufSize)) )

/* Size of Read/Write buffers for I2C bootloader  */
#define GLCD_SPI_SCB_I2C_BTLDR_SIZEOF_READ_BUFFER   (64u)
#define GLCD_SPI_SCB_I2C_BTLDR_SIZEOF_WRITE_BUFFER  (64u)

/* Byte to byte time interval: calculated basing on current component
* data rate configuration, can be defined in project if required.
*/
#ifndef GLCD_SPI_SCB_SPI_BYTE_TO_BYTE
    #define GLCD_SPI_SCB_SPI_BYTE_TO_BYTE   (6u)
#endif

/* Byte to byte time interval: calculated basing on current component
* baud rate configuration, can be defined in the project if required.
*/
#ifndef GLCD_SPI_SCB_UART_BYTE_TO_BYTE
    #define GLCD_SPI_SCB_UART_BYTE_TO_BYTE  (2500u)
#endif /* GLCD_SPI_SCB_UART_BYTE_TO_BYTE */

#endif /* (CY_SCB_BOOT_GLCD_SPI_SCB_H) */


/* [] END OF FILE */
