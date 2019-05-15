/*******************************************************************************
* File Name: ADCInput_intClock.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_ADCInput_intClock_H)
#define CY_CLOCK_ADCInput_intClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void ADCInput_intClock_StartEx(uint32 alignClkDiv);
#define ADCInput_intClock_Start() \
    ADCInput_intClock_StartEx(ADCInput_intClock__PA_DIV_ID)

#else

void ADCInput_intClock_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void ADCInput_intClock_Stop(void);

void ADCInput_intClock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 ADCInput_intClock_GetDividerRegister(void);
uint8  ADCInput_intClock_GetFractionalDividerRegister(void);

#define ADCInput_intClock_Enable()                         ADCInput_intClock_Start()
#define ADCInput_intClock_Disable()                        ADCInput_intClock_Stop()
#define ADCInput_intClock_SetDividerRegister(clkDivider, reset)  \
    ADCInput_intClock_SetFractionalDividerRegister((clkDivider), 0u)
#define ADCInput_intClock_SetDivider(clkDivider)           ADCInput_intClock_SetDividerRegister((clkDivider), 1u)
#define ADCInput_intClock_SetDividerValue(clkDivider)      ADCInput_intClock_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define ADCInput_intClock_DIV_ID     ADCInput_intClock__DIV_ID

#define ADCInput_intClock_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define ADCInput_intClock_CTRL_REG   (*(reg32 *)ADCInput_intClock__CTRL_REGISTER)
#define ADCInput_intClock_DIV_REG    (*(reg32 *)ADCInput_intClock__DIV_REGISTER)

#define ADCInput_intClock_CMD_DIV_SHIFT          (0u)
#define ADCInput_intClock_CMD_PA_DIV_SHIFT       (8u)
#define ADCInput_intClock_CMD_DISABLE_SHIFT      (30u)
#define ADCInput_intClock_CMD_ENABLE_SHIFT       (31u)

#define ADCInput_intClock_CMD_DISABLE_MASK       ((uint32)((uint32)1u << ADCInput_intClock_CMD_DISABLE_SHIFT))
#define ADCInput_intClock_CMD_ENABLE_MASK        ((uint32)((uint32)1u << ADCInput_intClock_CMD_ENABLE_SHIFT))

#define ADCInput_intClock_DIV_FRAC_MASK  (0x000000F8u)
#define ADCInput_intClock_DIV_FRAC_SHIFT (3u)
#define ADCInput_intClock_DIV_INT_MASK   (0xFFFFFF00u)
#define ADCInput_intClock_DIV_INT_SHIFT  (8u)

#else 

#define ADCInput_intClock_DIV_REG        (*(reg32 *)ADCInput_intClock__REGISTER)
#define ADCInput_intClock_ENABLE_REG     ADCInput_intClock_DIV_REG
#define ADCInput_intClock_DIV_FRAC_MASK  ADCInput_intClock__FRAC_MASK
#define ADCInput_intClock_DIV_FRAC_SHIFT (16u)
#define ADCInput_intClock_DIV_INT_MASK   ADCInput_intClock__DIVIDER_MASK
#define ADCInput_intClock_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_ADCInput_intClock_H) */

/* [] END OF FILE */
