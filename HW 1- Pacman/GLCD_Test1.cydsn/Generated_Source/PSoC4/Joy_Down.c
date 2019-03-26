/*******************************************************************************
* File Name: Joy_Down.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Joy_Down.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Joy_Down_PC =   (Joy_Down_PC & \
                                (uint32)(~(uint32)(Joy_Down_DRIVE_MODE_IND_MASK << (Joy_Down_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Joy_Down_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Joy_Down_Write
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
void Joy_Down_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Joy_Down_DR & (uint8)(~Joy_Down_MASK));
    drVal = (drVal | ((uint8)(value << Joy_Down_SHIFT) & Joy_Down_MASK));
    Joy_Down_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Joy_Down_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void Joy_Down_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Joy_Down__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Joy_Down_Read
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
*  Macro Joy_Down_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Joy_Down_Read(void) 
{
    return (uint8)((Joy_Down_PS & Joy_Down_MASK) >> Joy_Down_SHIFT);
}


/*******************************************************************************
* Function Name: Joy_Down_ReadDataReg
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
uint8 Joy_Down_ReadDataReg(void) 
{
    return (uint8)((Joy_Down_DR & Joy_Down_MASK) >> Joy_Down_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Joy_Down_INTSTAT) 

    /*******************************************************************************
    * Function Name: Joy_Down_ClearInterrupt
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
    uint8 Joy_Down_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Joy_Down_INTSTAT & Joy_Down_MASK);
		Joy_Down_INTSTAT = maskedStatus;
        return maskedStatus >> Joy_Down_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
