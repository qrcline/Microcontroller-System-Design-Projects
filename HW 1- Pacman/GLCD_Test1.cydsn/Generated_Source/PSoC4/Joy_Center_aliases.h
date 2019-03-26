/*******************************************************************************
* File Name: Joy_Center.h  
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

#if !defined(CY_PINS_Joy_Center_ALIASES_H) /* Pins Joy_Center_ALIASES_H */
#define CY_PINS_Joy_Center_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Joy_Center_0			(Joy_Center__0__PC)
#define Joy_Center_0_PS		(Joy_Center__0__PS)
#define Joy_Center_0_PC		(Joy_Center__0__PC)
#define Joy_Center_0_DR		(Joy_Center__0__DR)
#define Joy_Center_0_SHIFT	(Joy_Center__0__SHIFT)
#define Joy_Center_0_INTR	((uint16)((uint16)0x0003u << (Joy_Center__0__SHIFT*2u)))

#define Joy_Center_INTR_ALL	 ((uint16)(Joy_Center_0_INTR))


#endif /* End Pins Joy_Center_ALIASES_H */


/* [] END OF FILE */
