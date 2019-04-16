/*******************************************************************************
* File Name: JoyA.h  
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

#if !defined(CY_PINS_JoyA_H) /* Pins JoyA_H */
#define CY_PINS_JoyA_H

#include "cytypes.h"
#include "cyfitter.h"
#include "JoyA_aliases.h"


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
} JoyA_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   JoyA_Read(void);
void    JoyA_Write(uint8 value);
uint8   JoyA_ReadDataReg(void);
#if defined(JoyA__PC) || (CY_PSOC4_4200L) 
    void    JoyA_SetDriveMode(uint8 mode);
#endif
void    JoyA_SetInterruptMode(uint16 position, uint16 mode);
uint8   JoyA_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void JoyA_Sleep(void); 
void JoyA_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(JoyA__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define JoyA_DRIVE_MODE_BITS        (3)
    #define JoyA_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - JoyA_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the JoyA_SetDriveMode() function.
         *  @{
         */
        #define JoyA_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define JoyA_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define JoyA_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define JoyA_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define JoyA_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define JoyA_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define JoyA_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define JoyA_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define JoyA_MASK               JoyA__MASK
#define JoyA_SHIFT              JoyA__SHIFT
#define JoyA_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in JoyA_SetInterruptMode() function.
     *  @{
     */
        #define JoyA_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define JoyA_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define JoyA_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define JoyA_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(JoyA__SIO)
    #define JoyA_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(JoyA__PC) && (CY_PSOC4_4200L)
    #define JoyA_USBIO_ENABLE               ((uint32)0x80000000u)
    #define JoyA_USBIO_DISABLE              ((uint32)(~JoyA_USBIO_ENABLE))
    #define JoyA_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define JoyA_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define JoyA_USBIO_ENTER_SLEEP          ((uint32)((1u << JoyA_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << JoyA_USBIO_SUSPEND_DEL_SHIFT)))
    #define JoyA_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << JoyA_USBIO_SUSPEND_SHIFT)))
    #define JoyA_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << JoyA_USBIO_SUSPEND_DEL_SHIFT)))
    #define JoyA_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(JoyA__PC)
    /* Port Configuration */
    #define JoyA_PC                 (* (reg32 *) JoyA__PC)
#endif
/* Pin State */
#define JoyA_PS                     (* (reg32 *) JoyA__PS)
/* Data Register */
#define JoyA_DR                     (* (reg32 *) JoyA__DR)
/* Input Buffer Disable Override */
#define JoyA_INP_DIS                (* (reg32 *) JoyA__PC2)

/* Interrupt configuration Registers */
#define JoyA_INTCFG                 (* (reg32 *) JoyA__INTCFG)
#define JoyA_INTSTAT                (* (reg32 *) JoyA__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define JoyA_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(JoyA__SIO)
    #define JoyA_SIO_REG            (* (reg32 *) JoyA__SIO)
#endif /* (JoyA__SIO_CFG) */

/* USBIO registers */
#if !defined(JoyA__PC) && (CY_PSOC4_4200L)
    #define JoyA_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define JoyA_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define JoyA_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define JoyA_DRIVE_MODE_SHIFT       (0x00u)
#define JoyA_DRIVE_MODE_MASK        (0x07u << JoyA_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins JoyA_H */


/* [] END OF FILE */
