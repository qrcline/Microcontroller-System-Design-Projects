/*******************************************************************************
* File Name: mosiOut.h  
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

#if !defined(CY_PINS_mosiOut_ALIASES_H) /* Pins mosiOut_ALIASES_H */
#define CY_PINS_mosiOut_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define mosiOut_0			(mosiOut__0__PC)
#define mosiOut_0_PS		(mosiOut__0__PS)
#define mosiOut_0_PC		(mosiOut__0__PC)
#define mosiOut_0_DR		(mosiOut__0__DR)
#define mosiOut_0_SHIFT	(mosiOut__0__SHIFT)
#define mosiOut_0_INTR	((uint16)((uint16)0x0003u << (mosiOut__0__SHIFT*2u)))

#define mosiOut_INTR_ALL	 ((uint16)(mosiOut_0_INTR))


#endif /* End Pins mosiOut_ALIASES_H */


/* [] END OF FILE */
