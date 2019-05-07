/*******************************************************************************
* File Name: StickButton_Interrupt.h
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
#if !defined(CY_ISR_StickButton_Interrupt_H)
#define CY_ISR_StickButton_Interrupt_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void StickButton_Interrupt_Start(void);
void StickButton_Interrupt_StartEx(cyisraddress address);
void StickButton_Interrupt_Stop(void);

CY_ISR_PROTO(StickButton_Interrupt_Interrupt);

void StickButton_Interrupt_SetVector(cyisraddress address);
cyisraddress StickButton_Interrupt_GetVector(void);

void StickButton_Interrupt_SetPriority(uint8 priority);
uint8 StickButton_Interrupt_GetPriority(void);

void StickButton_Interrupt_Enable(void);
uint8 StickButton_Interrupt_GetState(void);
void StickButton_Interrupt_Disable(void);

void StickButton_Interrupt_SetPending(void);
void StickButton_Interrupt_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the StickButton_Interrupt ISR. */
#define StickButton_Interrupt_INTC_VECTOR            ((reg32 *) StickButton_Interrupt__INTC_VECT)

/* Address of the StickButton_Interrupt ISR priority. */
#define StickButton_Interrupt_INTC_PRIOR             ((reg32 *) StickButton_Interrupt__INTC_PRIOR_REG)

/* Priority of the StickButton_Interrupt interrupt. */
#define StickButton_Interrupt_INTC_PRIOR_NUMBER      StickButton_Interrupt__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable StickButton_Interrupt interrupt. */
#define StickButton_Interrupt_INTC_SET_EN            ((reg32 *) StickButton_Interrupt__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the StickButton_Interrupt interrupt. */
#define StickButton_Interrupt_INTC_CLR_EN            ((reg32 *) StickButton_Interrupt__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the StickButton_Interrupt interrupt state to pending. */
#define StickButton_Interrupt_INTC_SET_PD            ((reg32 *) StickButton_Interrupt__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the StickButton_Interrupt interrupt. */
#define StickButton_Interrupt_INTC_CLR_PD            ((reg32 *) StickButton_Interrupt__INTC_CLR_PD_REG)



#endif /* CY_ISR_StickButton_Interrupt_H */


/* [] END OF FILE */
