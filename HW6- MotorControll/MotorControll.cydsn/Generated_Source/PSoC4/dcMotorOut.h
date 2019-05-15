/*******************************************************************************
* File Name: dcMotorOut.h  
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

#if !defined(CY_PINS_dcMotorOut_H) /* Pins dcMotorOut_H */
#define CY_PINS_dcMotorOut_H

#include "cytypes.h"
#include "cyfitter.h"
#include "dcMotorOut_aliases.h"


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
} dcMotorOut_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   dcMotorOut_Read(void);
void    dcMotorOut_Write(uint8 value);
uint8   dcMotorOut_ReadDataReg(void);
#if defined(dcMotorOut__PC) || (CY_PSOC4_4200L) 
    void    dcMotorOut_SetDriveMode(uint8 mode);
#endif
void    dcMotorOut_SetInterruptMode(uint16 position, uint16 mode);
uint8   dcMotorOut_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void dcMotorOut_Sleep(void); 
void dcMotorOut_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(dcMotorOut__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define dcMotorOut_DRIVE_MODE_BITS        (3)
    #define dcMotorOut_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - dcMotorOut_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the dcMotorOut_SetDriveMode() function.
         *  @{
         */
        #define dcMotorOut_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define dcMotorOut_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define dcMotorOut_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define dcMotorOut_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define dcMotorOut_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define dcMotorOut_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define dcMotorOut_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define dcMotorOut_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define dcMotorOut_MASK               dcMotorOut__MASK
#define dcMotorOut_SHIFT              dcMotorOut__SHIFT
#define dcMotorOut_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in dcMotorOut_SetInterruptMode() function.
     *  @{
     */
        #define dcMotorOut_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define dcMotorOut_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define dcMotorOut_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define dcMotorOut_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(dcMotorOut__SIO)
    #define dcMotorOut_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(dcMotorOut__PC) && (CY_PSOC4_4200L)
    #define dcMotorOut_USBIO_ENABLE               ((uint32)0x80000000u)
    #define dcMotorOut_USBIO_DISABLE              ((uint32)(~dcMotorOut_USBIO_ENABLE))
    #define dcMotorOut_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define dcMotorOut_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define dcMotorOut_USBIO_ENTER_SLEEP          ((uint32)((1u << dcMotorOut_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << dcMotorOut_USBIO_SUSPEND_DEL_SHIFT)))
    #define dcMotorOut_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << dcMotorOut_USBIO_SUSPEND_SHIFT)))
    #define dcMotorOut_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << dcMotorOut_USBIO_SUSPEND_DEL_SHIFT)))
    #define dcMotorOut_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(dcMotorOut__PC)
    /* Port Configuration */
    #define dcMotorOut_PC                 (* (reg32 *) dcMotorOut__PC)
#endif
/* Pin State */
#define dcMotorOut_PS                     (* (reg32 *) dcMotorOut__PS)
/* Data Register */
#define dcMotorOut_DR                     (* (reg32 *) dcMotorOut__DR)
/* Input Buffer Disable Override */
#define dcMotorOut_INP_DIS                (* (reg32 *) dcMotorOut__PC2)

/* Interrupt configuration Registers */
#define dcMotorOut_INTCFG                 (* (reg32 *) dcMotorOut__INTCFG)
#define dcMotorOut_INTSTAT                (* (reg32 *) dcMotorOut__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define dcMotorOut_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(dcMotorOut__SIO)
    #define dcMotorOut_SIO_REG            (* (reg32 *) dcMotorOut__SIO)
#endif /* (dcMotorOut__SIO_CFG) */

/* USBIO registers */
#if !defined(dcMotorOut__PC) && (CY_PSOC4_4200L)
    #define dcMotorOut_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define dcMotorOut_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define dcMotorOut_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define dcMotorOut_DRIVE_MODE_SHIFT       (0x00u)
#define dcMotorOut_DRIVE_MODE_MASK        (0x07u << dcMotorOut_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins dcMotorOut_H */


/* [] END OF FILE */
