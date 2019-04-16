/*******************************************************************************
* File Name: JoyA_Interrupt.h
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
#if !defined(CY_ISR_JoyA_Interrupt_H)
#define CY_ISR_JoyA_Interrupt_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void JoyA_Interrupt_Start(void);
void JoyA_Interrupt_StartEx(cyisraddress address);
void JoyA_Interrupt_Stop(void);

CY_ISR_PROTO(JoyA_Interrupt_Interrupt);

void JoyA_Interrupt_SetVector(cyisraddress address);
cyisraddress JoyA_Interrupt_GetVector(void);

void JoyA_Interrupt_SetPriority(uint8 priority);
uint8 JoyA_Interrupt_GetPriority(void);

void JoyA_Interrupt_Enable(void);
uint8 JoyA_Interrupt_GetState(void);
void JoyA_Interrupt_Disable(void);

void JoyA_Interrupt_SetPending(void);
void JoyA_Interrupt_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the JoyA_Interrupt ISR. */
#define JoyA_Interrupt_INTC_VECTOR            ((reg32 *) JoyA_Interrupt__INTC_VECT)

/* Address of the JoyA_Interrupt ISR priority. */
#define JoyA_Interrupt_INTC_PRIOR             ((reg32 *) JoyA_Interrupt__INTC_PRIOR_REG)

/* Priority of the JoyA_Interrupt interrupt. */
#define JoyA_Interrupt_INTC_PRIOR_NUMBER      JoyA_Interrupt__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable JoyA_Interrupt interrupt. */
#define JoyA_Interrupt_INTC_SET_EN            ((reg32 *) JoyA_Interrupt__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the JoyA_Interrupt interrupt. */
#define JoyA_Interrupt_INTC_CLR_EN            ((reg32 *) JoyA_Interrupt__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the JoyA_Interrupt interrupt state to pending. */
#define JoyA_Interrupt_INTC_SET_PD            ((reg32 *) JoyA_Interrupt__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the JoyA_Interrupt interrupt. */
#define JoyA_Interrupt_INTC_CLR_PD            ((reg32 *) JoyA_Interrupt__INTC_CLR_PD_REG)



#endif /* CY_ISR_JoyA_Interrupt_H */


/* [] END OF FILE */
