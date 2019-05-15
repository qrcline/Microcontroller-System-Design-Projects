/*******************************************************************************
* File Name: dcMotorOut.h  
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

#if !defined(CY_PINS_dcMotorOut_ALIASES_H) /* Pins dcMotorOut_ALIASES_H */
#define CY_PINS_dcMotorOut_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define dcMotorOut_0			(dcMotorOut__0__PC)
#define dcMotorOut_0_PS		(dcMotorOut__0__PS)
#define dcMotorOut_0_PC		(dcMotorOut__0__PC)
#define dcMotorOut_0_DR		(dcMotorOut__0__DR)
#define dcMotorOut_0_SHIFT	(dcMotorOut__0__SHIFT)
#define dcMotorOut_0_INTR	((uint16)((uint16)0x0003u << (dcMotorOut__0__SHIFT*2u)))

#define dcMotorOut_INTR_ALL	 ((uint16)(dcMotorOut_0_INTR))


#endif /* End Pins dcMotorOut_ALIASES_H */


/* [] END OF FILE */
