/*******************************************************************************
* File Name: B_Interrupt.h
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
#if !defined(CY_ISR_B_Interrupt_H)
#define CY_ISR_B_Interrupt_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void B_Interrupt_Start(void);
void B_Interrupt_StartEx(cyisraddress address);
void B_Interrupt_Stop(void);

CY_ISR_PROTO(B_Interrupt_Interrupt);

void B_Interrupt_SetVector(cyisraddress address);
cyisraddress B_Interrupt_GetVector(void);

void B_Interrupt_SetPriority(uint8 priority);
uint8 B_Interrupt_GetPriority(void);

void B_Interrupt_Enable(void);
uint8 B_Interrupt_GetState(void);
void B_Interrupt_Disable(void);

void B_Interrupt_SetPending(void);
void B_Interrupt_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the B_Interrupt ISR. */
#define B_Interrupt_INTC_VECTOR            ((reg32 *) B_Interrupt__INTC_VECT)

/* Address of the B_Interrupt ISR priority. */
#define B_Interrupt_INTC_PRIOR             ((reg32 *) B_Interrupt__INTC_PRIOR_REG)

/* Priority of the B_Interrupt interrupt. */
#define B_Interrupt_INTC_PRIOR_NUMBER      B_Interrupt__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable B_Interrupt interrupt. */
#define B_Interrupt_INTC_SET_EN            ((reg32 *) B_Interrupt__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the B_Interrupt interrupt. */
#define B_Interrupt_INTC_CLR_EN            ((reg32 *) B_Interrupt__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the B_Interrupt interrupt state to pending. */
#define B_Interrupt_INTC_SET_PD            ((reg32 *) B_Interrupt__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the B_Interrupt interrupt. */
#define B_Interrupt_INTC_CLR_PD            ((reg32 *) B_Interrupt__INTC_CLR_PD_REG)



#endif /* CY_ISR_B_Interrupt_H */


/* [] END OF FILE */
