/*******************************************************************************
* File Name: DirectionInt.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_DirectionInt_H)
#define CY_ISR_DirectionInt_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void DirectionInt_Start(void);
void DirectionInt_StartEx(cyisraddress address);
void DirectionInt_Stop(void);

CY_ISR_PROTO(DirectionInt_Interrupt);

void DirectionInt_SetVector(cyisraddress address);
cyisraddress DirectionInt_GetVector(void);

void DirectionInt_SetPriority(uint8 priority);
uint8 DirectionInt_GetPriority(void);

void DirectionInt_Enable(void);
uint8 DirectionInt_GetState(void);
void DirectionInt_Disable(void);

void DirectionInt_SetPending(void);
void DirectionInt_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the DirectionInt ISR. */
#define DirectionInt_INTC_VECTOR            ((reg32 *) DirectionInt__INTC_VECT)

/* Address of the DirectionInt ISR priority. */
#define DirectionInt_INTC_PRIOR             ((reg32 *) DirectionInt__INTC_PRIOR_REG)

/* Priority of the DirectionInt interrupt. */
#define DirectionInt_INTC_PRIOR_NUMBER      DirectionInt__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable DirectionInt interrupt. */
#define DirectionInt_INTC_SET_EN            ((reg32 *) DirectionInt__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the DirectionInt interrupt. */
#define DirectionInt_INTC_CLR_EN            ((reg32 *) DirectionInt__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the DirectionInt interrupt state to pending. */
#define DirectionInt_INTC_SET_PD            ((reg32 *) DirectionInt__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the DirectionInt interrupt. */
#define DirectionInt_INTC_CLR_PD            ((reg32 *) DirectionInt__INTC_CLR_PD_REG)



#endif /* CY_ISR_DirectionInt_H */


/* [] END OF FILE */
