/*******************************************************************************
* File Name: Joy_Center.h  
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

#if !defined(CY_PINS_Joy_Center_H) /* Pins Joy_Center_H */
#define CY_PINS_Joy_Center_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Joy_Center_aliases.h"


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
} Joy_Center_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Joy_Center_Read(void);
void    Joy_Center_Write(uint8 value);
uint8   Joy_Center_ReadDataReg(void);
#if defined(Joy_Center__PC) || (CY_PSOC4_4200L) 
    void    Joy_Center_SetDriveMode(uint8 mode);
#endif
void    Joy_Center_SetInterruptMode(uint16 position, uint16 mode);
uint8   Joy_Center_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Joy_Center_Sleep(void); 
void Joy_Center_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Joy_Center__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Joy_Center_DRIVE_MODE_BITS        (3)
    #define Joy_Center_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Joy_Center_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Joy_Center_SetDriveMode() function.
         *  @{
         */
        #define Joy_Center_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Joy_Center_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Joy_Center_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Joy_Center_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Joy_Center_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Joy_Center_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Joy_Center_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Joy_Center_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Joy_Center_MASK               Joy_Center__MASK
#define Joy_Center_SHIFT              Joy_Center__SHIFT
#define Joy_Center_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Joy_Center_SetInterruptMode() function.
     *  @{
     */
        #define Joy_Center_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Joy_Center_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Joy_Center_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Joy_Center_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Joy_Center__SIO)
    #define Joy_Center_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Joy_Center__PC) && (CY_PSOC4_4200L)
    #define Joy_Center_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Joy_Center_USBIO_DISABLE              ((uint32)(~Joy_Center_USBIO_ENABLE))
    #define Joy_Center_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Joy_Center_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Joy_Center_USBIO_ENTER_SLEEP          ((uint32)((1u << Joy_Center_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Joy_Center_USBIO_SUSPEND_DEL_SHIFT)))
    #define Joy_Center_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Joy_Center_USBIO_SUSPEND_SHIFT)))
    #define Joy_Center_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Joy_Center_USBIO_SUSPEND_DEL_SHIFT)))
    #define Joy_Center_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Joy_Center__PC)
    /* Port Configuration */
    #define Joy_Center_PC                 (* (reg32 *) Joy_Center__PC)
#endif
/* Pin State */
#define Joy_Center_PS                     (* (reg32 *) Joy_Center__PS)
/* Data Register */
#define Joy_Center_DR                     (* (reg32 *) Joy_Center__DR)
/* Input Buffer Disable Override */
#define Joy_Center_INP_DIS                (* (reg32 *) Joy_Center__PC2)

/* Interrupt configuration Registers */
#define Joy_Center_INTCFG                 (* (reg32 *) Joy_Center__INTCFG)
#define Joy_Center_INTSTAT                (* (reg32 *) Joy_Center__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Joy_Center_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Joy_Center__SIO)
    #define Joy_Center_SIO_REG            (* (reg32 *) Joy_Center__SIO)
#endif /* (Joy_Center__SIO_CFG) */

/* USBIO registers */
#if !defined(Joy_Center__PC) && (CY_PSOC4_4200L)
    #define Joy_Center_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Joy_Center_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Joy_Center_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Joy_Center_DRIVE_MODE_SHIFT       (0x00u)
#define Joy_Center_DRIVE_MODE_MASK        (0x07u << Joy_Center_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Joy_Center_H */


/* [] END OF FILE */
