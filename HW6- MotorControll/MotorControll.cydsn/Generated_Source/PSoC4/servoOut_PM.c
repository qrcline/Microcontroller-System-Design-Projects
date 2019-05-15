/*******************************************************************************
* File Name: servoOut.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "servoOut.h"

static servoOut_BACKUP_STRUCT  servoOut_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: servoOut_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet servoOut_SUT.c usage_servoOut_Sleep_Wakeup
*******************************************************************************/
void servoOut_Sleep(void)
{
    #if defined(servoOut__PC)
        servoOut_backup.pcState = servoOut_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            servoOut_backup.usbState = servoOut_CR1_REG;
            servoOut_USB_POWER_REG |= servoOut_USBIO_ENTER_SLEEP;
            servoOut_CR1_REG &= servoOut_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(servoOut__SIO)
        servoOut_backup.sioState = servoOut_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        servoOut_SIO_REG &= (uint32)(~servoOut_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: servoOut_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to servoOut_Sleep() for an example usage.
*******************************************************************************/
void servoOut_Wakeup(void)
{
    #if defined(servoOut__PC)
        servoOut_PC = servoOut_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            servoOut_USB_POWER_REG &= servoOut_USBIO_EXIT_SLEEP_PH1;
            servoOut_CR1_REG = servoOut_backup.usbState;
            servoOut_USB_POWER_REG &= servoOut_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(servoOut__SIO)
        servoOut_SIO_REG = servoOut_backup.sioState;
    #endif
}


/* [] END OF FILE */
