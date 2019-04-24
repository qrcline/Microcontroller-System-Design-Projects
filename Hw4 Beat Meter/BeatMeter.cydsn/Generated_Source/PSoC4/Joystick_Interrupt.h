/*******************************************************************************
* File Name: Joystick_Interrupt.h
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
#if !defined(CY_ISR_Joystick_Interrupt_H)
#define CY_ISR_Joystick_Interrupt_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Joystick_Interrupt_Start(void);
void Joystick_Interrupt_StartEx(cyisraddress address);
void Joystick_Interrupt_Stop(void);

CY_ISR_PROTO(Joystick_Interrupt_Interrupt);

void Joystick_Interrupt_SetVector(cyisraddress address);
cyisraddress Joystick_Interrupt_GetVector(void);

void Joystick_Interrupt_SetPriority(uint8 priority);
uint8 Joystick_Interrupt_GetPriority(void);

void Joystick_Interrupt_Enable(void);
uint8 Joystick_Interrupt_GetState(void);
void Joystick_Interrupt_Disable(void);

void Joystick_Interrupt_SetPending(void);
void Joystick_Interrupt_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Joystick_Interrupt ISR. */
#define Joystick_Interrupt_INTC_VECTOR            ((reg32 *) Joystick_Interrupt__INTC_VECT)

/* Address of the Joystick_Interrupt ISR priority. */
#define Joystick_Interrupt_INTC_PRIOR             ((reg32 *) Joystick_Interrupt__INTC_PRIOR_REG)

/* Priority of the Joystick_Interrupt interrupt. */
#define Joystick_Interrupt_INTC_PRIOR_NUMBER      Joystick_Interrupt__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Joystick_Interrupt interrupt. */
#define Joystick_Interrupt_INTC_SET_EN            ((reg32 *) Joystick_Interrupt__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Joystick_Interrupt interrupt. */
#define Joystick_Interrupt_INTC_CLR_EN            ((reg32 *) Joystick_Interrupt__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Joystick_Interrupt interrupt state to pending. */
#define Joystick_Interrupt_INTC_SET_PD            ((reg32 *) Joystick_Interrupt__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Joystick_Interrupt interrupt. */
#define Joystick_Interrupt_INTC_CLR_PD            ((reg32 *) Joystick_Interrupt__INTC_CLR_PD_REG)



#endif /* CY_ISR_Joystick_Interrupt_H */


/* [] END OF FILE */
