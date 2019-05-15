/*******************************************************************************
* File Name: sclkOut.h  
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

#if !defined(CY_PINS_sclkOut_H) /* Pins sclkOut_H */
#define CY_PINS_sclkOut_H

#include "cytypes.h"
#include "cyfitter.h"
#include "sclkOut_aliases.h"


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
} sclkOut_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   sclkOut_Read(void);
void    sclkOut_Write(uint8 value);
uint8   sclkOut_ReadDataReg(void);
#if defined(sclkOut__PC) || (CY_PSOC4_4200L) 
    void    sclkOut_SetDriveMode(uint8 mode);
#endif
void    sclkOut_SetInterruptMode(uint16 position, uint16 mode);
uint8   sclkOut_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void sclkOut_Sleep(void); 
void sclkOut_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(sclkOut__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define sclkOut_DRIVE_MODE_BITS        (3)
    #define sclkOut_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - sclkOut_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the sclkOut_SetDriveMode() function.
         *  @{
         */
        #define sclkOut_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define sclkOut_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define sclkOut_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define sclkOut_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define sclkOut_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define sclkOut_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define sclkOut_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define sclkOut_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define sclkOut_MASK               sclkOut__MASK
#define sclkOut_SHIFT              sclkOut__SHIFT
#define sclkOut_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in sclkOut_SetInterruptMode() function.
     *  @{
     */
        #define sclkOut_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define sclkOut_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define sclkOut_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define sclkOut_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(sclkOut__SIO)
    #define sclkOut_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(sclkOut__PC) && (CY_PSOC4_4200L)
    #define sclkOut_USBIO_ENABLE               ((uint32)0x80000000u)
    #define sclkOut_USBIO_DISABLE              ((uint32)(~sclkOut_USBIO_ENABLE))
    #define sclkOut_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define sclkOut_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define sclkOut_USBIO_ENTER_SLEEP          ((uint32)((1u << sclkOut_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << sclkOut_USBIO_SUSPEND_DEL_SHIFT)))
    #define sclkOut_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << sclkOut_USBIO_SUSPEND_SHIFT)))
    #define sclkOut_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << sclkOut_USBIO_SUSPEND_DEL_SHIFT)))
    #define sclkOut_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(sclkOut__PC)
    /* Port Configuration */
    #define sclkOut_PC                 (* (reg32 *) sclkOut__PC)
#endif
/* Pin State */
#define sclkOut_PS                     (* (reg32 *) sclkOut__PS)
/* Data Register */
#define sclkOut_DR                     (* (reg32 *) sclkOut__DR)
/* Input Buffer Disable Override */
#define sclkOut_INP_DIS                (* (reg32 *) sclkOut__PC2)

/* Interrupt configuration Registers */
#define sclkOut_INTCFG                 (* (reg32 *) sclkOut__INTCFG)
#define sclkOut_INTSTAT                (* (reg32 *) sclkOut__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define sclkOut_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(sclkOut__SIO)
    #define sclkOut_SIO_REG            (* (reg32 *) sclkOut__SIO)
#endif /* (sclkOut__SIO_CFG) */

/* USBIO registers */
#if !defined(sclkOut__PC) && (CY_PSOC4_4200L)
    #define sclkOut_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define sclkOut_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define sclkOut_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define sclkOut_DRIVE_MODE_SHIFT       (0x00u)
#define sclkOut_DRIVE_MODE_MASK        (0x07u << sclkOut_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins sclkOut_H */


/* [] END OF FILE */
