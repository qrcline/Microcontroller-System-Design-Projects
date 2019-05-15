/*******************************************************************************
* File Name: Enable.h  
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

#if !defined(CY_PINS_Enable_H) /* Pins Enable_H */
#define CY_PINS_Enable_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Enable_aliases.h"


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
} Enable_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Enable_Read(void);
void    Enable_Write(uint8 value);
uint8   Enable_ReadDataReg(void);
#if defined(Enable__PC) || (CY_PSOC4_4200L) 
    void    Enable_SetDriveMode(uint8 mode);
#endif
void    Enable_SetInterruptMode(uint16 position, uint16 mode);
uint8   Enable_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Enable_Sleep(void); 
void Enable_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Enable__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Enable_DRIVE_MODE_BITS        (3)
    #define Enable_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Enable_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Enable_SetDriveMode() function.
         *  @{
         */
        #define Enable_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Enable_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Enable_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Enable_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Enable_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Enable_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Enable_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Enable_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Enable_MASK               Enable__MASK
#define Enable_SHIFT              Enable__SHIFT
#define Enable_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Enable_SetInterruptMode() function.
     *  @{
     */
        #define Enable_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Enable_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Enable_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Enable_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Enable__SIO)
    #define Enable_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Enable__PC) && (CY_PSOC4_4200L)
    #define Enable_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Enable_USBIO_DISABLE              ((uint32)(~Enable_USBIO_ENABLE))
    #define Enable_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Enable_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Enable_USBIO_ENTER_SLEEP          ((uint32)((1u << Enable_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Enable_USBIO_SUSPEND_DEL_SHIFT)))
    #define Enable_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Enable_USBIO_SUSPEND_SHIFT)))
    #define Enable_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Enable_USBIO_SUSPEND_DEL_SHIFT)))
    #define Enable_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Enable__PC)
    /* Port Configuration */
    #define Enable_PC                 (* (reg32 *) Enable__PC)
#endif
/* Pin State */
#define Enable_PS                     (* (reg32 *) Enable__PS)
/* Data Register */
#define Enable_DR                     (* (reg32 *) Enable__DR)
/* Input Buffer Disable Override */
#define Enable_INP_DIS                (* (reg32 *) Enable__PC2)

/* Interrupt configuration Registers */
#define Enable_INTCFG                 (* (reg32 *) Enable__INTCFG)
#define Enable_INTSTAT                (* (reg32 *) Enable__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Enable_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Enable__SIO)
    #define Enable_SIO_REG            (* (reg32 *) Enable__SIO)
#endif /* (Enable__SIO_CFG) */

/* USBIO registers */
#if !defined(Enable__PC) && (CY_PSOC4_4200L)
    #define Enable_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Enable_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Enable_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Enable_DRIVE_MODE_SHIFT       (0x00u)
#define Enable_DRIVE_MODE_MASK        (0x07u << Enable_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Enable_H */


/* [] END OF FILE */
