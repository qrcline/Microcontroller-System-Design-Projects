/*******************************************************************************
* File Name: StickButton.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_StickButton_ALIASES_H) /* Pins StickButton_ALIASES_H */
#define CY_PINS_StickButton_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define StickButton_0			(StickButton__0__PC)
#define StickButton_0_PS		(StickButton__0__PS)
#define StickButton_0_PC		(StickButton__0__PC)
#define StickButton_0_DR		(StickButton__0__DR)
#define StickButton_0_SHIFT	(StickButton__0__SHIFT)
#define StickButton_0_INTR	((uint16)((uint16)0x0003u << (StickButton__0__SHIFT*2u)))

#define StickButton_INTR_ALL	 ((uint16)(StickButton_0_INTR))


#endif /* End Pins StickButton_ALIASES_H */


/* [] END OF FILE */
