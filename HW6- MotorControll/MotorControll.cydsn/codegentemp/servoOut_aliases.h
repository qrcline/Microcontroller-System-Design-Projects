/*******************************************************************************
* File Name: servoOut.h  
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

#if !defined(CY_PINS_servoOut_ALIASES_H) /* Pins servoOut_ALIASES_H */
#define CY_PINS_servoOut_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define servoOut_0			(servoOut__0__PC)
#define servoOut_0_PS		(servoOut__0__PS)
#define servoOut_0_PC		(servoOut__0__PC)
#define servoOut_0_DR		(servoOut__0__DR)
#define servoOut_0_SHIFT	(servoOut__0__SHIFT)
#define servoOut_0_INTR	((uint16)((uint16)0x0003u << (servoOut__0__SHIFT*2u)))

#define servoOut_INTR_ALL	 ((uint16)(servoOut_0_INTR))


#endif /* End Pins servoOut_ALIASES_H */


/* [] END OF FILE */
