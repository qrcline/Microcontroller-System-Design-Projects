/*******************************************************************************
* File Name: JoyA.h  
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

#if !defined(CY_PINS_JoyA_ALIASES_H) /* Pins JoyA_ALIASES_H */
#define CY_PINS_JoyA_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define JoyA_0			(JoyA__0__PC)
#define JoyA_0_PS		(JoyA__0__PS)
#define JoyA_0_PC		(JoyA__0__PC)
#define JoyA_0_DR		(JoyA__0__DR)
#define JoyA_0_SHIFT	(JoyA__0__SHIFT)
#define JoyA_0_INTR	((uint16)((uint16)0x0003u << (JoyA__0__SHIFT*2u)))

#define JoyA_INTR_ALL	 ((uint16)(JoyA_0_INTR))


#endif /* End Pins JoyA_ALIASES_H */


/* [] END OF FILE */
