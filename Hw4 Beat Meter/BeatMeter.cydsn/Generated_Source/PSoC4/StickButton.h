/*******************************************************************************
* File Name: StickButton.h  
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

#if !defined(CY_PINS_StickButton_H) /* Pins StickButton_H */
#define CY_PINS_StickButton_H

#include "cytypes.h"
#include "cyfitter.h"
#include "StickButton_aliases.h"


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
} StickButton_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   StickButton_Read(void);
void    StickButton_Write(uint8 value);
uint8   StickButton_ReadDataReg(void);
#if defined(StickButton__PC) || (CY_PSOC4_4200L) 
    void    StickButton_SetDriveMode(uint8 mode);
#endif
void    StickButton_SetInterruptMode(uint16 position, uint16 mode);
uint8   StickButton_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void StickButton_Sleep(void); 
void StickButton_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(StickButton__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define StickButton_DRIVE_MODE_BITS        (3)
    #define StickButton_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - StickButton_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the StickButton_SetDriveMode() function.
         *  @{
         */
        #define StickButton_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define StickButton_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define StickButton_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define StickButton_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define StickButton_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define StickButton_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define StickButton_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define StickButton_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define StickButton_MASK               StickButton__MASK
#define StickButton_SHIFT              StickButton__SHIFT
#define StickButton_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in StickButton_SetInterruptMode() function.
     *  @{
     */
        #define StickButton_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define StickButton_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define StickButton_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define StickButton_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(StickButton__SIO)
    #define StickButton_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(StickButton__PC) && (CY_PSOC4_4200L)
    #define StickButton_USBIO_ENABLE               ((uint32)0x80000000u)
    #define StickButton_USBIO_DISABLE              ((uint32)(~StickButton_USBIO_ENABLE))
    #define StickButton_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define StickButton_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define StickButton_USBIO_ENTER_SLEEP          ((uint32)((1u << StickButton_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << StickButton_USBIO_SUSPEND_DEL_SHIFT)))
    #define StickButton_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << StickButton_USBIO_SUSPEND_SHIFT)))
    #define StickButton_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << StickButton_USBIO_SUSPEND_DEL_SHIFT)))
    #define StickButton_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(StickButton__PC)
    /* Port Configuration */
    #define StickButton_PC                 (* (reg32 *) StickButton__PC)
#endif
/* Pin State */
#define StickButton_PS                     (* (reg32 *) StickButton__PS)
/* Data Register */
#define StickButton_DR                     (* (reg32 *) StickButton__DR)
/* Input Buffer Disable Override */
#define StickButton_INP_DIS                (* (reg32 *) StickButton__PC2)

/* Interrupt configuration Registers */
#define StickButton_INTCFG                 (* (reg32 *) StickButton__INTCFG)
#define StickButton_INTSTAT                (* (reg32 *) StickButton__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define StickButton_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(StickButton__SIO)
    #define StickButton_SIO_REG            (* (reg32 *) StickButton__SIO)
#endif /* (StickButton__SIO_CFG) */

/* USBIO registers */
#if !defined(StickButton__PC) && (CY_PSOC4_4200L)
    #define StickButton_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define StickButton_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define StickButton_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define StickButton_DRIVE_MODE_SHIFT       (0x00u)
#define StickButton_DRIVE_MODE_MASK        (0x07u << StickButton_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins StickButton_H */


/* [] END OF FILE */
