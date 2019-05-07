/*******************************************************************************
* File Name: JoyY.h  
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

#if !defined(CY_PINS_JoyY_ALIASES_H) /* Pins JoyY_ALIASES_H */
#define CY_PINS_JoyY_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define JoyY_0			(JoyY__0__PC)
#define JoyY_0_PS		(JoyY__0__PS)
#define JoyY_0_PC		(JoyY__0__PC)
#define JoyY_0_DR		(JoyY__0__DR)
#define JoyY_0_SHIFT	(JoyY__0__SHIFT)
#define JoyY_0_INTR	((uint16)((uint16)0x0003u << (JoyY__0__SHIFT*2u)))

#define JoyY_INTR_ALL	 ((uint16)(JoyY_0_INTR))


#endif /* End Pins JoyY_ALIASES_H */


/* [] END OF FILE */
