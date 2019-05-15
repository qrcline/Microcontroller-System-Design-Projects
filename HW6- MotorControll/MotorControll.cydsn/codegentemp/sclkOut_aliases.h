/*******************************************************************************
* File Name: sclkOut.h  
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

#if !defined(CY_PINS_sclkOut_ALIASES_H) /* Pins sclkOut_ALIASES_H */
#define CY_PINS_sclkOut_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define sclkOut_0			(sclkOut__0__PC)
#define sclkOut_0_PS		(sclkOut__0__PS)
#define sclkOut_0_PC		(sclkOut__0__PC)
#define sclkOut_0_DR		(sclkOut__0__DR)
#define sclkOut_0_SHIFT	(sclkOut__0__SHIFT)
#define sclkOut_0_INTR	((uint16)((uint16)0x0003u << (sclkOut__0__SHIFT*2u)))

#define sclkOut_INTR_ALL	 ((uint16)(sclkOut_0_INTR))


#endif /* End Pins sclkOut_ALIASES_H */


/* [] END OF FILE */
