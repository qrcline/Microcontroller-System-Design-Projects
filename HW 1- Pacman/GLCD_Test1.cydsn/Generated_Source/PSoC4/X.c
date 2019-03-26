/*******************************************************************************
* File Name: X.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "X.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        X_PC =   (X_PC & \
                                (uint32)(~(uint32)(X_DRIVE_MODE_IND_MASK << (X_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (X_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: X_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void X_Write(uint8 value) 
{
    uint8 drVal = (uint8)(X_DR & (uint8)(~X_MASK));
    drVal = (drVal | ((uint8)(value << X_SHIFT) & X_MASK));
    X_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: X_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  X_DM_STRONG     Strong Drive 
*  X_DM_OD_HI      Open Drain, Drives High 
*  X_DM_OD_LO      Open Drain, Drives Low 
*  X_DM_RES_UP     Resistive Pull Up 
*  X_DM_RES_DWN    Resistive Pull Down 
*  X_DM_RES_UPDWN  Resistive Pull Up/Down 
*  X_DM_DIG_HIZ    High Impedance Digital 
*  X_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void X_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(X__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: X_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro X_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 X_Read(void) 
{
    return (uint8)((X_PS & X_MASK) >> X_SHIFT);
}


/*******************************************************************************
* Function Name: X_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 X_ReadDataReg(void) 
{
    return (uint8)((X_DR & X_MASK) >> X_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(X_INTSTAT) 

    /*******************************************************************************
    * Function Name: X_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 X_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(X_INTSTAT & X_MASK);
		X_INTSTAT = maskedStatus;
        return maskedStatus >> X_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
