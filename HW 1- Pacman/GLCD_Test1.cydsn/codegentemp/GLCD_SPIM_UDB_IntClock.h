/*******************************************************************************
* File Name: GLCD_SPIM_UDB_IntClock.h
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

#if !defined(CY_CLOCK_GLCD_SPIM_UDB_IntClock_H)
#define CY_CLOCK_GLCD_SPIM_UDB_IntClock_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void GLCD_SPIM_UDB_IntClock_StartEx(uint32 alignClkDiv);
#define GLCD_SPIM_UDB_IntClock_Start() \
    GLCD_SPIM_UDB_IntClock_StartEx(GLCD_SPIM_UDB_IntClock__PA_DIV_ID)

#else

void GLCD_SPIM_UDB_IntClock_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void GLCD_SPIM_UDB_IntClock_Stop(void);

void GLCD_SPIM_UDB_IntClock_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 GLCD_SPIM_UDB_IntClock_GetDividerRegister(void);
uint8  GLCD_SPIM_UDB_IntClock_GetFractionalDividerRegister(void);

#define GLCD_SPIM_UDB_IntClock_Enable()                         GLCD_SPIM_UDB_IntClock_Start()
#define GLCD_SPIM_UDB_IntClock_Disable()                        GLCD_SPIM_UDB_IntClock_Stop()
#define GLCD_SPIM_UDB_IntClock_SetDividerRegister(clkDivider, reset)  \
    GLCD_SPIM_UDB_IntClock_SetFractionalDividerRegister((clkDivider), 0u)
#define GLCD_SPIM_UDB_IntClock_SetDivider(clkDivider)           GLCD_SPIM_UDB_IntClock_SetDividerRegister((clkDivider), 1u)
#define GLCD_SPIM_UDB_IntClock_SetDividerValue(clkDivider)      GLCD_SPIM_UDB_IntClock_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define GLCD_SPIM_UDB_IntClock_DIV_ID     GLCD_SPIM_UDB_IntClock__DIV_ID

#define GLCD_SPIM_UDB_IntClock_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define GLCD_SPIM_UDB_IntClock_CTRL_REG   (*(reg32 *)GLCD_SPIM_UDB_IntClock__CTRL_REGISTER)
#define GLCD_SPIM_UDB_IntClock_DIV_REG    (*(reg32 *)GLCD_SPIM_UDB_IntClock__DIV_REGISTER)

#define GLCD_SPIM_UDB_IntClock_CMD_DIV_SHIFT          (0u)
#define GLCD_SPIM_UDB_IntClock_CMD_PA_DIV_SHIFT       (8u)
#define GLCD_SPIM_UDB_IntClock_CMD_DISABLE_SHIFT      (30u)
#define GLCD_SPIM_UDB_IntClock_CMD_ENABLE_SHIFT       (31u)

#define GLCD_SPIM_UDB_IntClock_CMD_DISABLE_MASK       ((uint32)((uint32)1u << GLCD_SPIM_UDB_IntClock_CMD_DISABLE_SHIFT))
#define GLCD_SPIM_UDB_IntClock_CMD_ENABLE_MASK        ((uint32)((uint32)1u << GLCD_SPIM_UDB_IntClock_CMD_ENABLE_SHIFT))

#define GLCD_SPIM_UDB_IntClock_DIV_FRAC_MASK  (0x000000F8u)
#define GLCD_SPIM_UDB_IntClock_DIV_FRAC_SHIFT (3u)
#define GLCD_SPIM_UDB_IntClock_DIV_INT_MASK   (0xFFFFFF00u)
#define GLCD_SPIM_UDB_IntClock_DIV_INT_SHIFT  (8u)

#else 

#define GLCD_SPIM_UDB_IntClock_DIV_REG        (*(reg32 *)GLCD_SPIM_UDB_IntClock__REGISTER)
#define GLCD_SPIM_UDB_IntClock_ENABLE_REG     GLCD_SPIM_UDB_IntClock_DIV_REG
#define GLCD_SPIM_UDB_IntClock_DIV_FRAC_MASK  GLCD_SPIM_UDB_IntClock__FRAC_MASK
#define GLCD_SPIM_UDB_IntClock_DIV_FRAC_SHIFT (16u)
#define GLCD_SPIM_UDB_IntClock_DIV_INT_MASK   GLCD_SPIM_UDB_IntClock__DIVIDER_MASK
#define GLCD_SPIM_UDB_IntClock_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_GLCD_SPIM_UDB_IntClock_H) */

/* [] END OF FILE */
