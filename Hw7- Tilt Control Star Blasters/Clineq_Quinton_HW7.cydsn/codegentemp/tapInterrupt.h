/*******************************************************************************
* File Name: tapInterrupt.h
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
#if !defined(CY_ISR_tapInterrupt_H)
#define CY_ISR_tapInterrupt_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void tapInterrupt_Start(void);
void tapInterrupt_StartEx(cyisraddress address);
void tapInterrupt_Stop(void);

CY_ISR_PROTO(tapInterrupt_Interrupt);

void tapInterrupt_SetVector(cyisraddress address);
cyisraddress tapInterrupt_GetVector(void);

void tapInterrupt_SetPriority(uint8 priority);
uint8 tapInterrupt_GetPriority(void);

void tapInterrupt_Enable(void);
uint8 tapInterrupt_GetState(void);
void tapInterrupt_Disable(void);

void tapInterrupt_SetPending(void);
void tapInterrupt_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the tapInterrupt ISR. */
#define tapInterrupt_INTC_VECTOR            ((reg32 *) tapInterrupt__INTC_VECT)

/* Address of the tapInterrupt ISR priority. */
#define tapInterrupt_INTC_PRIOR             ((reg32 *) tapInterrupt__INTC_PRIOR_REG)

/* Priority of the tapInterrupt interrupt. */
#define tapInterrupt_INTC_PRIOR_NUMBER      tapInterrupt__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable tapInterrupt interrupt. */
#define tapInterrupt_INTC_SET_EN            ((reg32 *) tapInterrupt__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the tapInterrupt interrupt. */
#define tapInterrupt_INTC_CLR_EN            ((reg32 *) tapInterrupt__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the tapInterrupt interrupt state to pending. */
#define tapInterrupt_INTC_SET_PD            ((reg32 *) tapInterrupt__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the tapInterrupt interrupt. */
#define tapInterrupt_INTC_CLR_PD            ((reg32 *) tapInterrupt__INTC_CLR_PD_REG)



#endif /* CY_ISR_tapInterrupt_H */


/* [] END OF FILE */
