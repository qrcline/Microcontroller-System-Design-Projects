/*******************************************************************************
* File Name: servoOut.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_servoOut_H) /* Pins servoOut_H */
#define CY_PINS_servoOut_H

#include "cytypes.h"
#include "cyfitter.h"
#include "servoOut_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} servoOut_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   servoOut_Read(void);
void    servoOut_Write(uint8 value);
uint8   servoOut_ReadDataReg(void);
#if defined(servoOut__PC) || (CY_PSOC4_4200L) 
    void    servoOut_SetDriveMode(uint8 mode);
#endif
void    servoOut_SetInterruptMode(uint16 position, uint16 mode);
uint8   servoOut_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void servoOut_Sleep(void); 
void servoOut_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(servoOut__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define servoOut_DRIVE_MODE_BITS        (3)
    #define servoOut_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - servoOut_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the servoOut_SetDriveMode() function.
         *  @{
         */
        #define servoOut_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define servoOut_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define servoOut_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define servoOut_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define servoOut_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define servoOut_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define servoOut_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define servoOut_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define servoOut_MASK               servoOut__MASK
#define servoOut_SHIFT              servoOut__SHIFT
#define servoOut_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in servoOut_SetInterruptMode() function.
     *  @{
     */
        #define servoOut_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define servoOut_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define servoOut_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define servoOut_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(servoOut__SIO)
    #define servoOut_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(servoOut__PC) && (CY_PSOC4_4200L)
    #define servoOut_USBIO_ENABLE               ((uint32)0x80000000u)
    #define servoOut_USBIO_DISABLE              ((uint32)(~servoOut_USBIO_ENABLE))
    #define servoOut_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define servoOut_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define servoOut_USBIO_ENTER_SLEEP          ((uint32)((1u << servoOut_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << servoOut_USBIO_SUSPEND_DEL_SHIFT)))
    #define servoOut_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << servoOut_USBIO_SUSPEND_SHIFT)))
    #define servoOut_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << servoOut_USBIO_SUSPEND_DEL_SHIFT)))
    #define servoOut_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(servoOut__PC)
    /* Port Configuration */
    #define servoOut_PC                 (* (reg32 *) servoOut__PC)
#endif
/* Pin State */
#define servoOut_PS                     (* (reg32 *) servoOut__PS)
/* Data Register */
#define servoOut_DR                     (* (reg32 *) servoOut__DR)
/* Input Buffer Disable Override */
#define servoOut_INP_DIS                (* (reg32 *) servoOut__PC2)

/* Interrupt configuration Registers */
#define servoOut_INTCFG                 (* (reg32 *) servoOut__INTCFG)
#define servoOut_INTSTAT                (* (reg32 *) servoOut__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define servoOut_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(servoOut__SIO)
    #define servoOut_SIO_REG            (* (reg32 *) servoOut__SIO)
#endif /* (servoOut__SIO_CFG) */

/* USBIO registers */
#if !defined(servoOut__PC) && (CY_PSOC4_4200L)
    #define servoOut_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define servoOut_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define servoOut_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define servoOut_DRIVE_MODE_SHIFT       (0x00u)
#define servoOut_DRIVE_MODE_MASK        (0x07u << servoOut_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins servoOut_H */


/* [] END OF FILE */
