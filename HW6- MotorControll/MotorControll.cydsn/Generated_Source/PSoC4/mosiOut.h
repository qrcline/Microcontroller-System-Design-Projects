/*******************************************************************************
* File Name: mosiOut.h  
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

#if !defined(CY_PINS_mosiOut_H) /* Pins mosiOut_H */
#define CY_PINS_mosiOut_H

#include "cytypes.h"
#include "cyfitter.h"
#include "mosiOut_aliases.h"


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
} mosiOut_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   mosiOut_Read(void);
void    mosiOut_Write(uint8 value);
uint8   mosiOut_ReadDataReg(void);
#if defined(mosiOut__PC) || (CY_PSOC4_4200L) 
    void    mosiOut_SetDriveMode(uint8 mode);
#endif
void    mosiOut_SetInterruptMode(uint16 position, uint16 mode);
uint8   mosiOut_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void mosiOut_Sleep(void); 
void mosiOut_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(mosiOut__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define mosiOut_DRIVE_MODE_BITS        (3)
    #define mosiOut_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - mosiOut_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the mosiOut_SetDriveMode() function.
         *  @{
         */
        #define mosiOut_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define mosiOut_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define mosiOut_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define mosiOut_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define mosiOut_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define mosiOut_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define mosiOut_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define mosiOut_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define mosiOut_MASK               mosiOut__MASK
#define mosiOut_SHIFT              mosiOut__SHIFT
#define mosiOut_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in mosiOut_SetInterruptMode() function.
     *  @{
     */
        #define mosiOut_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define mosiOut_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define mosiOut_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define mosiOut_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(mosiOut__SIO)
    #define mosiOut_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(mosiOut__PC) && (CY_PSOC4_4200L)
    #define mosiOut_USBIO_ENABLE               ((uint32)0x80000000u)
    #define mosiOut_USBIO_DISABLE              ((uint32)(~mosiOut_USBIO_ENABLE))
    #define mosiOut_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define mosiOut_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define mosiOut_USBIO_ENTER_SLEEP          ((uint32)((1u << mosiOut_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << mosiOut_USBIO_SUSPEND_DEL_SHIFT)))
    #define mosiOut_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << mosiOut_USBIO_SUSPEND_SHIFT)))
    #define mosiOut_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << mosiOut_USBIO_SUSPEND_DEL_SHIFT)))
    #define mosiOut_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(mosiOut__PC)
    /* Port Configuration */
    #define mosiOut_PC                 (* (reg32 *) mosiOut__PC)
#endif
/* Pin State */
#define mosiOut_PS                     (* (reg32 *) mosiOut__PS)
/* Data Register */
#define mosiOut_DR                     (* (reg32 *) mosiOut__DR)
/* Input Buffer Disable Override */
#define mosiOut_INP_DIS                (* (reg32 *) mosiOut__PC2)

/* Interrupt configuration Registers */
#define mosiOut_INTCFG                 (* (reg32 *) mosiOut__INTCFG)
#define mosiOut_INTSTAT                (* (reg32 *) mosiOut__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define mosiOut_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(mosiOut__SIO)
    #define mosiOut_SIO_REG            (* (reg32 *) mosiOut__SIO)
#endif /* (mosiOut__SIO_CFG) */

/* USBIO registers */
#if !defined(mosiOut__PC) && (CY_PSOC4_4200L)
    #define mosiOut_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define mosiOut_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define mosiOut_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define mosiOut_DRIVE_MODE_SHIFT       (0x00u)
#define mosiOut_DRIVE_MODE_MASK        (0x07u << mosiOut_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins mosiOut_H */


/* [] END OF FILE */
