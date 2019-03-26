/*******************************************************************************
* File Name: D.h  
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

#if !defined(CY_PINS_D_ALIASES_H) /* Pins D_ALIASES_H */
#define CY_PINS_D_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define D_0			(D__0__PC)
#define D_0_PS		(D__0__PS)
#define D_0_PC		(D__0__PC)
#define D_0_DR		(D__0__DR)
#define D_0_SHIFT	(D__0__SHIFT)
#define D_0_INTR	((uint16)((uint16)0x0003u << (D__0__SHIFT*2u)))

#define D_INTR_ALL	 ((uint16)(D_0_INTR))


#endif /* End Pins D_ALIASES_H */


/* [] END OF FILE */
