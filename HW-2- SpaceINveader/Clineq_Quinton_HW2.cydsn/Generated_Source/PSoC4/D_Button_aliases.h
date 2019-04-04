/*******************************************************************************
* File Name: D_Button.h  
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

#if !defined(CY_PINS_D_Button_ALIASES_H) /* Pins D_Button_ALIASES_H */
#define CY_PINS_D_Button_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define D_Button_0			(D_Button__0__PC)
#define D_Button_0_PS		(D_Button__0__PS)
#define D_Button_0_PC		(D_Button__0__PC)
#define D_Button_0_DR		(D_Button__0__DR)
#define D_Button_0_SHIFT	(D_Button__0__SHIFT)
#define D_Button_0_INTR	((uint16)((uint16)0x0003u << (D_Button__0__SHIFT*2u)))

#define D_Button_INTR_ALL	 ((uint16)(D_Button_0_INTR))


#endif /* End Pins D_Button_ALIASES_H */


/* [] END OF FILE */