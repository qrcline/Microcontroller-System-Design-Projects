/*******************************************************************************
* File Name: JoyX.h  
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

#if !defined(CY_PINS_JoyX_H) /* Pins JoyX_H */
#define CY_PINS_JoyX_H

#include "cytypes.h"
#include "cyfitter.h"
#include "JoyX_aliases.h"


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
} JoyX_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   JoyX_Read(void);
void    JoyX_Write(uint8 value);
uint8   JoyX_ReadDataReg(void);
#if defined(JoyX__PC) || (CY_PSOC4_4200L) 
    void    JoyX_SetDriveMode(uint8 mode);
#endif
void    JoyX_SetInterruptMode(uint16 position, uint16 mode);
uint8   JoyX_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void JoyX_Sleep(void); 
void JoyX_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(JoyX__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define JoyX_DRIVE_MODE_BITS        (3)
    #define JoyX_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - JoyX_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the JoyX_SetDriveMode() function.
         *  @{
         */
        #define JoyX_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define JoyX_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define JoyX_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define JoyX_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define JoyX_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define JoyX_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define JoyX_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define JoyX_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define JoyX_MASK               JoyX__MASK
#define JoyX_SHIFT              JoyX__SHIFT
#define JoyX_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in JoyX_SetInterruptMode() function.
     *  @{
     */
        #define JoyX_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define JoyX_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define JoyX_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define JoyX_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(JoyX__SIO)
    #define JoyX_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(JoyX__PC) && (CY_PSOC4_4200L)
    #define JoyX_USBIO_ENABLE               ((uint32)0x80000000u)
    #define JoyX_USBIO_DISABLE              ((uint32)(~JoyX_USBIO_ENABLE))
    #define JoyX_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define JoyX_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define JoyX_USBIO_ENTER_SLEEP          ((uint32)((1u << JoyX_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << JoyX_USBIO_SUSPEND_DEL_SHIFT)))
    #define JoyX_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << JoyX_USBIO_SUSPEND_SHIFT)))
    #define JoyX_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << JoyX_USBIO_SUSPEND_DEL_SHIFT)))
    #define JoyX_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(JoyX__PC)
    /* Port Configuration */
    #define JoyX_PC                 (* (reg32 *) JoyX__PC)
#endif
/* Pin State */
#define JoyX_PS                     (* (reg32 *) JoyX__PS)
/* Data Register */
#define JoyX_DR                     (* (reg32 *) JoyX__DR)
/* Input Buffer Disable Override */
#define JoyX_INP_DIS                (* (reg32 *) JoyX__PC2)

/* Interrupt configuration Registers */
#define JoyX_INTCFG                 (* (reg32 *) JoyX__INTCFG)
#define JoyX_INTSTAT                (* (reg32 *) JoyX__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define JoyX_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(JoyX__SIO)
    #define JoyX_SIO_REG            (* (reg32 *) JoyX__SIO)
#endif /* (JoyX__SIO_CFG) */

/* USBIO registers */
#if !defined(JoyX__PC) && (CY_PSOC4_4200L)
    #define JoyX_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define JoyX_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define JoyX_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define JoyX_DRIVE_MODE_SHIFT       (0x00u)
#define JoyX_DRIVE_MODE_MASK        (0x07u << JoyX_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins JoyX_H */


/* [] END OF FILE */
