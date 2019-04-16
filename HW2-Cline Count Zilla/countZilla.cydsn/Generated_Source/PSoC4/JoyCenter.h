/*******************************************************************************
* File Name: JoyCenter.h  
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

#if !defined(CY_PINS_JoyCenter_H) /* Pins JoyCenter_H */
#define CY_PINS_JoyCenter_H

#include "cytypes.h"
#include "cyfitter.h"
#include "JoyCenter_aliases.h"


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
} JoyCenter_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   JoyCenter_Read(void);
void    JoyCenter_Write(uint8 value);
uint8   JoyCenter_ReadDataReg(void);
#if defined(JoyCenter__PC) || (CY_PSOC4_4200L) 
    void    JoyCenter_SetDriveMode(uint8 mode);
#endif
void    JoyCenter_SetInterruptMode(uint16 position, uint16 mode);
uint8   JoyCenter_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void JoyCenter_Sleep(void); 
void JoyCenter_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(JoyCenter__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define JoyCenter_DRIVE_MODE_BITS        (3)
    #define JoyCenter_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - JoyCenter_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the JoyCenter_SetDriveMode() function.
         *  @{
         */
        #define JoyCenter_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define JoyCenter_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define JoyCenter_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define JoyCenter_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define JoyCenter_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define JoyCenter_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define JoyCenter_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define JoyCenter_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define JoyCenter_MASK               JoyCenter__MASK
#define JoyCenter_SHIFT              JoyCenter__SHIFT
#define JoyCenter_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in JoyCenter_SetInterruptMode() function.
     *  @{
     */
        #define JoyCenter_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define JoyCenter_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define JoyCenter_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define JoyCenter_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(JoyCenter__SIO)
    #define JoyCenter_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(JoyCenter__PC) && (CY_PSOC4_4200L)
    #define JoyCenter_USBIO_ENABLE               ((uint32)0x80000000u)
    #define JoyCenter_USBIO_DISABLE              ((uint32)(~JoyCenter_USBIO_ENABLE))
    #define JoyCenter_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define JoyCenter_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define JoyCenter_USBIO_ENTER_SLEEP          ((uint32)((1u << JoyCenter_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << JoyCenter_USBIO_SUSPEND_DEL_SHIFT)))
    #define JoyCenter_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << JoyCenter_USBIO_SUSPEND_SHIFT)))
    #define JoyCenter_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << JoyCenter_USBIO_SUSPEND_DEL_SHIFT)))
    #define JoyCenter_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(JoyCenter__PC)
    /* Port Configuration */
    #define JoyCenter_PC                 (* (reg32 *) JoyCenter__PC)
#endif
/* Pin State */
#define JoyCenter_PS                     (* (reg32 *) JoyCenter__PS)
/* Data Register */
#define JoyCenter_DR                     (* (reg32 *) JoyCenter__DR)
/* Input Buffer Disable Override */
#define JoyCenter_INP_DIS                (* (reg32 *) JoyCenter__PC2)

/* Interrupt configuration Registers */
#define JoyCenter_INTCFG                 (* (reg32 *) JoyCenter__INTCFG)
#define JoyCenter_INTSTAT                (* (reg32 *) JoyCenter__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define JoyCenter_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(JoyCenter__SIO)
    #define JoyCenter_SIO_REG            (* (reg32 *) JoyCenter__SIO)
#endif /* (JoyCenter__SIO_CFG) */

/* USBIO registers */
#if !defined(JoyCenter__PC) && (CY_PSOC4_4200L)
    #define JoyCenter_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define JoyCenter_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define JoyCenter_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define JoyCenter_DRIVE_MODE_SHIFT       (0x00u)
#define JoyCenter_DRIVE_MODE_MASK        (0x07u << JoyCenter_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins JoyCenter_H */


/* [] END OF FILE */
