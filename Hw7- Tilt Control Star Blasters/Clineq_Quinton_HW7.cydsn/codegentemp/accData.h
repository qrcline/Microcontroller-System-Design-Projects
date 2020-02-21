/*******************************************************************************
* File Name: accData.h
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
#if !defined(CY_ISR_accData_H)
#define CY_ISR_accData_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void accData_Start(void);
void accData_StartEx(cyisraddress address);
void accData_Stop(void);

CY_ISR_PROTO(accData_Interrupt);

void accData_SetVector(cyisraddress address);
cyisraddress accData_GetVector(void);

void accData_SetPriority(uint8 priority);
uint8 accData_GetPriority(void);

void accData_Enable(void);
uint8 accData_GetState(void);
void accData_Disable(void);

void accData_SetPending(void);
void accData_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the accData ISR. */
#define accData_INTC_VECTOR            ((reg32 *) accData__INTC_VECT)

/* Address of the accData ISR priority. */
#define accData_INTC_PRIOR             ((reg32 *) accData__INTC_PRIOR_REG)

/* Priority of the accData interrupt. */
#define accData_INTC_PRIOR_NUMBER      accData__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable accData interrupt. */
#define accData_INTC_SET_EN            ((reg32 *) accData__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the accData interrupt. */
#define accData_INTC_CLR_EN            ((reg32 *) accData__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the accData interrupt state to pending. */
#define accData_INTC_SET_PD            ((reg32 *) accData__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the accData interrupt. */
#define accData_INTC_CLR_PD            ((reg32 *) accData__INTC_CLR_PD_REG)



#endif /* CY_ISR_accData_H */


/* [] END OF FILE */
