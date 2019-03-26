/*******************************************************************************
* File Name: Y.c  
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
#include "Y.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Y_PC =   (Y_PC & \
                                (uint32)(~(uint32)(Y_DRIVE_MODE_IND_MASK << (Y_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Y_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Y_Write
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
void Y_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Y_DR & (uint8)(~Y_MASK));
    drVal = (drVal | ((uint8)(value << Y_SHIFT) & Y_MASK));
    Y_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Y_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Y_DM_STRONG     Strong Drive 
*  Y_DM_OD_HI      Open Drain, Drives High 
*  Y_DM_OD_LO      Open Drain, Drives Low 
*  Y_DM_RES_UP     Resistive Pull Up 
*  Y_DM_RES_DWN    Resistive Pull Down 
*  Y_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Y_DM_DIG_HIZ    High Impedance Digital 
*  Y_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Y_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Y__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Y_Read
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
*  Macro Y_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Y_Read(void) 
{
    return (uint8)((Y_PS & Y_MASK) >> Y_SHIFT);
}


/*******************************************************************************
* Function Name: Y_ReadDataReg
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
uint8 Y_ReadDataReg(void) 
{
    return (uint8)((Y_DR & Y_MASK) >> Y_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Y_INTSTAT) 

    /*******************************************************************************
    * Function Name: Y_ClearInterrupt
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
    uint8 Y_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Y_INTSTAT & Y_MASK);
		Y_INTSTAT = maskedStatus;
        return maskedStatus >> Y_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
