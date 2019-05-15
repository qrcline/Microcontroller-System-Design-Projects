/*******************************************************************************
* File Name: ReversePin.h  
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

#if !defined(CY_PINS_ReversePin_H) /* Pins ReversePin_H */
#define CY_PINS_ReversePin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ReversePin_aliases.h"


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
} ReversePin_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   ReversePin_Read(void);
void    ReversePin_Write(uint8 value);
uint8   ReversePin_ReadDataReg(void);
#if defined(ReversePin__PC) || (CY_PSOC4_4200L) 
    void    ReversePin_SetDriveMode(uint8 mode);
#endif
void    ReversePin_SetInterruptMode(uint16 position, uint16 mode);
uint8   ReversePin_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void ReversePin_Sleep(void); 
void ReversePin_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(ReversePin__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define ReversePin_DRIVE_MODE_BITS        (3)
    #define ReversePin_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ReversePin_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the ReversePin_SetDriveMode() function.
         *  @{
         */
        #define ReversePin_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define ReversePin_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define ReversePin_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define ReversePin_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define ReversePin_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define ReversePin_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define ReversePin_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define ReversePin_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define ReversePin_MASK               ReversePin__MASK
#define ReversePin_SHIFT              ReversePin__SHIFT
#define ReversePin_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ReversePin_SetInterruptMode() function.
     *  @{
     */
        #define ReversePin_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define ReversePin_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define ReversePin_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define ReversePin_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(ReversePin__SIO)
    #define ReversePin_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(ReversePin__PC) && (CY_PSOC4_4200L)
    #define ReversePin_USBIO_ENABLE               ((uint32)0x80000000u)
    #define ReversePin_USBIO_DISABLE              ((uint32)(~ReversePin_USBIO_ENABLE))
    #define ReversePin_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define ReversePin_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define ReversePin_USBIO_ENTER_SLEEP          ((uint32)((1u << ReversePin_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << ReversePin_USBIO_SUSPEND_DEL_SHIFT)))
    #define ReversePin_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << ReversePin_USBIO_SUSPEND_SHIFT)))
    #define ReversePin_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << ReversePin_USBIO_SUSPEND_DEL_SHIFT)))
    #define ReversePin_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(ReversePin__PC)
    /* Port Configuration */
    #define ReversePin_PC                 (* (reg32 *) ReversePin__PC)
#endif
/* Pin State */
#define ReversePin_PS                     (* (reg32 *) ReversePin__PS)
/* Data Register */
#define ReversePin_DR                     (* (reg32 *) ReversePin__DR)
/* Input Buffer Disable Override */
#define ReversePin_INP_DIS                (* (reg32 *) ReversePin__PC2)

/* Interrupt configuration Registers */
#define ReversePin_INTCFG                 (* (reg32 *) ReversePin__INTCFG)
#define ReversePin_INTSTAT                (* (reg32 *) ReversePin__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define ReversePin_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(ReversePin__SIO)
    #define ReversePin_SIO_REG            (* (reg32 *) ReversePin__SIO)
#endif /* (ReversePin__SIO_CFG) */

/* USBIO registers */
#if !defined(ReversePin__PC) && (CY_PSOC4_4200L)
    #define ReversePin_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define ReversePin_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define ReversePin_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define ReversePin_DRIVE_MODE_SHIFT       (0x00u)
#define ReversePin_DRIVE_MODE_MASK        (0x07u << ReversePin_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins ReversePin_H */


/* [] END OF FILE */
