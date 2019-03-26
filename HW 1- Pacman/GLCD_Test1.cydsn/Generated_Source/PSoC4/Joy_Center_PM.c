/*******************************************************************************
* File Name: Joy_Center.c  
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
#include "Joy_Center.h"

static Joy_Center_BACKUP_STRUCT  Joy_Center_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Joy_Center_Sleep
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
*  \snippet Joy_Center_SUT.c usage_Joy_Center_Sleep_Wakeup
*******************************************************************************/
void Joy_Center_Sleep(void)
{
    #if defined(Joy_Center__PC)
        Joy_Center_backup.pcState = Joy_Center_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Joy_Center_backup.usbState = Joy_Center_CR1_REG;
            Joy_Center_USB_POWER_REG |= Joy_Center_USBIO_ENTER_SLEEP;
            Joy_Center_CR1_REG &= Joy_Center_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Joy_Center__SIO)
        Joy_Center_backup.sioState = Joy_Center_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Joy_Center_SIO_REG &= (uint32)(~Joy_Center_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Joy_Center_Wakeup
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
*  Refer to Joy_Center_Sleep() for an example usage.
*******************************************************************************/
void Joy_Center_Wakeup(void)
{
    #if defined(Joy_Center__PC)
        Joy_Center_PC = Joy_Center_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Joy_Center_USB_POWER_REG &= Joy_Center_USBIO_EXIT_SLEEP_PH1;
            Joy_Center_CR1_REG = Joy_Center_backup.usbState;
            Joy_Center_USB_POWER_REG &= Joy_Center_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Joy_Center__SIO)
        Joy_Center_SIO_REG = Joy_Center_backup.sioState;
    #endif
}


/* [] END OF FILE */
