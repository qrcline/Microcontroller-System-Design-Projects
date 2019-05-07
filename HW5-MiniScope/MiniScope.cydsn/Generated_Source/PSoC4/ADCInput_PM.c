/*******************************************************************************
* File Name: ADCInput_PM.c
* Version 2.50
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADCInput.h"


/***************************************
* Local data allocation
***************************************/

static ADCInput_BACKUP_STRUCT  ADCInput_backup =
{
    ADCInput_DISABLED,
    0u    
};


/*******************************************************************************
* Function Name: ADCInput_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADCInput_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADCInput_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ADCInput_RestoreConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: ADCInput_Sleep
********************************************************************************
*
* Summary:
*  Stops the ADC operation and saves the configuration registers and component
*  enable state. Should be called just prior to entering sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADCInput_backup - modified.
*
*******************************************************************************/
void ADCInput_Sleep(void)
{
    /* During deepsleep/ hibernate mode keep SARMUX active, i.e. do not open
    *   all switches (disconnect), to be used for ADFT
    */
    ADCInput_backup.dftRegVal = ADCInput_SAR_DFT_CTRL_REG & (uint32)~ADCInput_ADFT_OVERRIDE;
    ADCInput_SAR_DFT_CTRL_REG |= ADCInput_ADFT_OVERRIDE;
    if((ADCInput_SAR_CTRL_REG  & ADCInput_ENABLE) != 0u)
    {
        if((ADCInput_SAR_SAMPLE_CTRL_REG & ADCInput_CONTINUOUS_EN) != 0u)
        {
            ADCInput_backup.enableState = ADCInput_ENABLED | ADCInput_STARTED;
        }
        else
        {
            ADCInput_backup.enableState = ADCInput_ENABLED;
        }
        ADCInput_StopConvert();
        ADCInput_Stop();
        
        /* Disable the SAR internal pump before entering the chip low power mode */
        if((ADCInput_SAR_CTRL_REG & ADCInput_BOOSTPUMP_EN) != 0u)
        {
            ADCInput_SAR_CTRL_REG &= (uint32)~ADCInput_BOOSTPUMP_EN;
            ADCInput_backup.enableState |= ADCInput_BOOSTPUMP_ENABLED;
        }
    }
    else
    {
        ADCInput_backup.enableState = ADCInput_DISABLED;
    }
}


/*******************************************************************************
* Function Name: ADCInput_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component enable state and configuration registers.
*  This should be called just after awaking from sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  ADCInput_backup - used.
*
*******************************************************************************/
void ADCInput_Wakeup(void)
{
    ADCInput_SAR_DFT_CTRL_REG = ADCInput_backup.dftRegVal;
    if(ADCInput_backup.enableState != ADCInput_DISABLED)
    {
        /* Enable the SAR internal pump  */
        if((ADCInput_backup.enableState & ADCInput_BOOSTPUMP_ENABLED) != 0u)
        {
            ADCInput_SAR_CTRL_REG |= ADCInput_BOOSTPUMP_EN;
        }
        ADCInput_Enable();
        if((ADCInput_backup.enableState & ADCInput_STARTED) != 0u)
        {
            ADCInput_StartConvert();
        }
    }
}
/* [] END OF FILE */
