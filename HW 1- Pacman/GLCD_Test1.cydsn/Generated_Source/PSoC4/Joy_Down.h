/*******************************************************************************
* File Name: Joy_Down.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Joy_Down_H) /* Pins Joy_Down_H */
#define CY_PINS_Joy_Down_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Joy_Down_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Joy_Down_Write(uint8 value) ;
void    Joy_Down_SetDriveMode(uint8 mode) ;
uint8   Joy_Down_ReadDataReg(void) ;
uint8   Joy_Down_Read(void) ;
uint8   Joy_Down_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Joy_Down_DRIVE_MODE_BITS        (3)
#define Joy_Down_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Joy_Down_DRIVE_MODE_BITS))
#define Joy_Down_DRIVE_MODE_SHIFT       (0x00u)
#define Joy_Down_DRIVE_MODE_MASK        (0x07u << Joy_Down_DRIVE_MODE_SHIFT)

#define Joy_Down_DM_ALG_HIZ         (0x00u << Joy_Down_DRIVE_MODE_SHIFT)
#define Joy_Down_DM_DIG_HIZ         (0x01u << Joy_Down_DRIVE_MODE_SHIFT)
#define Joy_Down_DM_RES_UP          (0x02u << Joy_Down_DRIVE_MODE_SHIFT)
#define Joy_Down_DM_RES_DWN         (0x03u << Joy_Down_DRIVE_MODE_SHIFT)
#define Joy_Down_DM_OD_LO           (0x04u << Joy_Down_DRIVE_MODE_SHIFT)
#define Joy_Down_DM_OD_HI           (0x05u << Joy_Down_DRIVE_MODE_SHIFT)
#define Joy_Down_DM_STRONG          (0x06u << Joy_Down_DRIVE_MODE_SHIFT)
#define Joy_Down_DM_RES_UPDWN       (0x07u << Joy_Down_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define Joy_Down_MASK               Joy_Down__MASK
#define Joy_Down_SHIFT              Joy_Down__SHIFT
#define Joy_Down_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Joy_Down_PS                     (* (reg32 *) Joy_Down__PS)
/* Port Configuration */
#define Joy_Down_PC                     (* (reg32 *) Joy_Down__PC)
/* Data Register */
#define Joy_Down_DR                     (* (reg32 *) Joy_Down__DR)
/* Input Buffer Disable Override */
#define Joy_Down_INP_DIS                (* (reg32 *) Joy_Down__PC2)


#if defined(Joy_Down__INTSTAT)  /* Interrupt Registers */

    #define Joy_Down_INTSTAT                (* (reg32 *) Joy_Down__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins Joy_Down_H */


/* [] END OF FILE */
