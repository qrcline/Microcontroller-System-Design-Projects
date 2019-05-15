/*******************************************************************************
* File Name: dcMotorOut.c  
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
#include "dcMotorOut.h"

static dcMotorOut_BACKUP_STRUCT  dcMotorOut_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: dcMotorOut_Sleep
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
*  \snippet dcMotorOut_SUT.c usage_dcMotorOut_Sleep_Wakeup
*******************************************************************************/
void dcMotorOut_Sleep(void)
{
    #if defined(dcMotorOut__PC)
        dcMotorOut_backup.pcState = dcMotorOut_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            dcMotorOut_backup.usbState = dcMotorOut_CR1_REG;
            dcMotorOut_USB_POWER_REG |= dcMotorOut_USBIO_ENTER_SLEEP;
            dcMotorOut_CR1_REG &= dcMotorOut_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(dcMotorOut__SIO)
        dcMotorOut_backup.sioState = dcMotorOut_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        dcMotorOut_SIO_REG &= (uint32)(~dcMotorOut_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: dcMotorOut_Wakeup
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
*  Refer to dcMotorOut_Sleep() for an example usage.
*******************************************************************************/
void dcMotorOut_Wakeup(void)
{
    #if defined(dcMotorOut__PC)
        dcMotorOut_PC = dcMotorOut_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            dcMotorOut_USB_POWER_REG &= dcMotorOut_USBIO_EXIT_SLEEP_PH1;
            dcMotorOut_CR1_REG = dcMotorOut_backup.usbState;
            dcMotorOut_USB_POWER_REG &= dcMotorOut_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(dcMotorOut__SIO)
        dcMotorOut_SIO_REG = dcMotorOut_backup.sioState;
    #endif
}


/* [] END OF FILE */
