/*******************************************************************************
* File Name: ReversePin.h  
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

#if !defined(CY_PINS_ReversePin_ALIASES_H) /* Pins ReversePin_ALIASES_H */
#define CY_PINS_ReversePin_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ReversePin_0			(ReversePin__0__PC)
#define ReversePin_0_PS		(ReversePin__0__PS)
#define ReversePin_0_PC		(ReversePin__0__PC)
#define ReversePin_0_DR		(ReversePin__0__DR)
#define ReversePin_0_SHIFT	(ReversePin__0__SHIFT)
#define ReversePin_0_INTR	((uint16)((uint16)0x0003u << (ReversePin__0__SHIFT*2u)))

#define ReversePin_INTR_ALL	 ((uint16)(ReversePin_0_INTR))


#endif /* End Pins ReversePin_ALIASES_H */


/* [] END OF FILE */
