/*******************************************************************************
* File Name: JoyX.h  
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

#if !defined(CY_PINS_JoyX_ALIASES_H) /* Pins JoyX_ALIASES_H */
#define CY_PINS_JoyX_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define JoyX_0			(JoyX__0__PC)
#define JoyX_0_PS		(JoyX__0__PS)
#define JoyX_0_PC		(JoyX__0__PC)
#define JoyX_0_DR		(JoyX__0__DR)
#define JoyX_0_SHIFT	(JoyX__0__SHIFT)
#define JoyX_0_INTR	((uint16)((uint16)0x0003u << (JoyX__0__SHIFT*2u)))

#define JoyX_INTR_ALL	 ((uint16)(JoyX_0_INTR))


#endif /* End Pins JoyX_ALIASES_H */


/* [] END OF FILE */
