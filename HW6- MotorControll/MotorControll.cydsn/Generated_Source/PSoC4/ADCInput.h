/*******************************************************************************
* File Name: ADCInput.h
* Version 2.50
*
* Description:
*  This file contains the function prototypes and constants used in
*  the Sequencing Successive Approximation ADC Component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_ADC_SAR_SEQ_ADCInput_H)
#define CY_ADC_SAR_SEQ_ADCInput_H

#include "cytypes.h"
#include "CyLib.h"


/***************************************
*      Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
    uint32 dftRegVal;
} ADCInput_BACKUP_STRUCT;


/**************************************
*    Enumerated Types and Parameters
**************************************/

/*  Clock Source setting constants */
#define ADCInput__EXTERNAL 0
#define ADCInput__INTERNAL 1

/*  Sample Mode setting constants */
#define ADCInput__FREERUNNING 0
#define ADCInput__HARDWARESOC 1

/*  Reference type setting constants */
#define ADCInput__VDDA_2 0
#define ADCInput__VDDA 1
#define ADCInput__INTERNAL1024 2
#define ADCInput__INTERNAL1024BYPASSED 3
#define ADCInput__INTERNALVREF 4
#define ADCInput__INTERNALVREFBYPASSED 5
#define ADCInput__VDDA_2BYPASSED 6
#define ADCInput__EXTERNALVREF 7

/* Input buffer gain setting constants */
#define ADCInput__DISABLED 0
#define ADCInput__ONE 1
#define ADCInput__TWO 2
#define ADCInput__FOUR 3
#define ADCInput__EIGHT 4
#define ADCInput__SIXTEEN 5

/* Negative input setting sonstants in single ended mode */
#define ADCInput__VSS 0
#define ADCInput__VREF 1
#define ADCInput__OTHER 2

/* Compare mode setting constants:
*    Mode0 - Disable
*    Mode1 - Result < Low_Limit
*    Mode2 - Low_Limit <= Result < High_Limit
*    Mode3 - High_Limit <= Result
*    Mode4 - (Result < Low_Limit) or (High_Limit <= Result)
*/
#define ADCInput__MODE0 0
#define ADCInput__MODE1 1
#define ADCInput__MODE2 2
#define ADCInput__MODE3 3

#define ADCInput__RES8 0
#define ADCInput__RES10 1

#define ADCInput__RIGHT 0
#define ADCInput__LEFT 1

#define ADCInput__FSIGNED 1
#define ADCInput__FUNSIGNED 0

#define ADCInput__ACCUMULATE 0
#define ADCInput__FIXEDRESOLUTION 1



/***************************************
*   Conditional Compilation Parameters
****************************************/ 

#define ADCInput_CY_SAR_IP_VER0               	(0u)
#define ADCInput_CY_SAR_IP_VER1               	(1u)

#if (CY_PSOC4_4100 || CY_PSOC4_4200)
    #define ADCInput_CY_SAR_IP_VER              (ADCInput_CY_SAR_IP_VER0)
#else /* Other devices */
    #define ADCInput_CY_SAR_IP_VER              (ADCInput_CY_SAR_IP_VER1)
#endif  /* (CY_PSOC4_4100 || CY_PSOC4_4200) */


/***************************************
*    Initial Parameter Constants
***************************************/
#define ADCInput_DEFAULT_SAMPLE_MODE_SEL        (0u)
#define ADCInput_DEFAULT_VREF_SEL               (1u)
#define ADCInput_DEFAULT_NEG_INPUT_SEL          (0u)
#define ADCInput_DEFAULT_ALT_RESOLUTION_SEL     (0u)
#define ADCInput_DEFAULT_JUSTIFICATION_SEL      (0u)
#define ADCInput_DEFAULT_DIFF_RESULT_FORMAT_SEL (1u)
#define ADCInput_DEFAULT_SE_RESULT_FORMAT_SEL   (1u)
#define ADCInput_DEFAULT_CLOCK_SOURCE           (1u)
#define ADCInput_DEFAULT_VREF_MV_VALUE          (3300)
#define ADCInput_DEFAULT_BUFFER_GAIN            (0u)
#define ADCInput_DEFAULT_AVG_SAMPLES_NUM        (0u)
#define ADCInput_DEFAULT_AVG_SAMPLES_DIV        (0u < 4u) ? (int16)(0x100u >> (7u - 0u)) : (int16)(0x100u >> 4u)
#define ADCInput_DEFAULT_AVG_MODE               (1u)
#define ADCInput_MAX_RESOLUTION                 (12u)
#define ADCInput_DEFAULT_LOW_LIMIT              (0u)
#define ADCInput_DEFAULT_HIGH_LIMIT             (2047u)
#define ADCInput_DEFAULT_COMPARE_MODE           (0u)
#define ADCInput_DEFAULT_ACLKS_NUM              (4u)
#define ADCInput_DEFAULT_BCLKS_NUM              (4u)
#define ADCInput_DEFAULT_CCLKS_NUM              (4u)
#define ADCInput_DEFAULT_DCLKS_NUM              (4u)
#define ADCInput_TOTAL_CHANNELS_NUM             (2u)
#define ADCInput_SEQUENCED_CHANNELS_NUM         (2u)
#define ADCInput_DEFAULT_EN_CHANNELS            (3u)
#define ADCInput_NOMINAL_CLOCK_FREQ             (6000000)
#define ADCInput_INJ_CHANNEL_ENABLED            (0u)
#define ADCInput_IRQ_REMOVE                     (0u)

/* Determines whether the configuration contains external negative input. */
#define ADCInput_SINGLE_PRESENT                 (0u)
#define ADCInput_CHANNELS_MODE                  (0u)
#define ADCInput_MAX_CHANNELS_EN_MASK           (0xffffu >> (16u - ADCInput_SEQUENCED_CHANNELS_NUM))


/***************************************
*        Function Prototypes
***************************************/

void ADCInput_Start(void);
void ADCInput_Stop(void);
void ADCInput_Init(void);
void ADCInput_Enable(void);
void ADCInput_StartConvert(void);
void ADCInput_StopConvert(void);
uint32 ADCInput_IsEndConversion(uint32 retMode);
int16 ADCInput_GetResult16(uint32 chan);
void ADCInput_SetChanMask(uint32 mask);
void ADCInput_SetLowLimit(uint32 lowLimit);
void ADCInput_SetHighLimit(uint32 highLimit);
void ADCInput_SetLimitMask(uint32 mask);
void ADCInput_SetSatMask(uint32 mask);
void ADCInput_SetOffset(uint32 chan, int16 offset);
void ADCInput_SetGain(uint32 chan, int32 adcGain);
#if(ADCInput_INJ_CHANNEL_ENABLED)
    void ADCInput_EnableInjection(void);
#endif /* ADCInput_INJ_CHANNEL_ENABLED */
#if(ADCInput_DEFAULT_JUSTIFICATION_SEL == ADCInput__RIGHT)
    int16 ADCInput_CountsTo_mVolts(uint32 chan, int16 adcCounts);
    int32 ADCInput_CountsTo_uVolts(uint32 chan, int16 adcCounts);
    float32 ADCInput_CountsTo_Volts(uint32 chan, int16 adcCounts);
#endif /* End ADCInput_DEFAULT_JUSTIFICATION_SEL == ADCInput__RIGHT */
void ADCInput_Sleep(void);
void ADCInput_Wakeup(void);
void ADCInput_SaveConfig(void);
void ADCInput_RestoreConfig(void);

CY_ISR_PROTO( ADCInput_ISR );


/**************************************
*           API Constants
**************************************/
/* Constants for Sleep mode states */
#define ADCInput_DISABLED                   (0x00u)
#define ADCInput_ENABLED                    (0x01u)
#define ADCInput_STARTED                    (0x02u)
#define ADCInput_BOOSTPUMP_ENABLED          (0x04u)

/*   Constants for IsEndConversion() "retMode" parameter  */
#define ADCInput_RETURN_STATUS              (0x01u)
#define ADCInput_WAIT_FOR_RESULT            (0x02u)
#define ADCInput_RETURN_STATUS_INJ          (0x04u)
#define ADCInput_WAIT_FOR_RESULT_INJ        (0x08u)

#define ADCInput_MAX_FREQUENCY              (18000000)       /*18Mhz*/

#define ADCInput_RESOLUTION_12              (12u)
#define ADCInput_RESOLUTION_10              (10u)
#define ADCInput_RESOLUTION_8               (8u)

#define ADCInput_10US_DELAY                 (10u)

#define ADCInput_10V_COUNTS                 (10.0F)
#define ADCInput_10MV_COUNTS                (10000)
#define ADCInput_10UV_COUNTS                (10000000L)


/***************************************
* Global variables external identifier
***************************************/

extern uint8 ADCInput_initVar;
extern volatile int16 ADCInput_offset[ADCInput_TOTAL_CHANNELS_NUM];
extern volatile int32 ADCInput_countsPer10Volt[ADCInput_TOTAL_CHANNELS_NUM];


/***************************************
*              Registers
***************************************/

#define ADCInput_SAR_CTRL_REG                (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_CTRL )
#define ADCInput_SAR_CTRL_PTR                ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_CTRL )

#define ADCInput_SAR_SAMPLE_CTRL_REG         (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_SAMPLE_CTRL )
#define ADCInput_SAR_SAMPLE_CTRL_PTR         ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_SAMPLE_CTRL )

#define ADCInput_SAR_SAMPLE_TIME01_REG       (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_SAMPLE_TIME01 )
#define ADCInput_SAR_SAMPLE_TIME01_PTR       ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_SAMPLE_TIME01 )

#define ADCInput_SAR_SAMPLE_TIME23_REG       (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_SAMPLE_TIME23 )
#define ADCInput_SAR_SAMPLE_TIME23_PTR       ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_SAMPLE_TIME23 )

#define ADCInput_SAR_RANGE_THRES_REG         (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_RANGE_THRES )
#define ADCInput_SAR_RANGE_THRES_PTR         ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_RANGE_THRES )

#define ADCInput_SAR_RANGE_COND_REG          (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_RANGE_COND )
#define ADCInput_SAR_RANGE_COND_PTR          ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_RANGE_COND )

#define ADCInput_SAR_CHAN_EN_REG             (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_EN )
#define ADCInput_SAR_CHAN_EN_PTR             ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_EN )

#define ADCInput_SAR_START_CTRL_REG          (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_START_CTRL )
#define ADCInput_SAR_START_CTRL_PTR          ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_START_CTRL )

#define ADCInput_SAR_DFT_CTRL_REG            (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_DFT_CTRL )
#define ADCInput_SAR_DFT_CTRL_PTR            ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_DFT_CTRL )

#define ADCInput_SAR_CHAN_CONFIG_REG         (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_CONFIG00 )
#define ADCInput_SAR_CHAN_CONFIG_PTR         ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_CONFIG00 )
#define ADCInput_SAR_CHAN_CONFIG_IND         ADCInput_cy_psoc4_sar__SAR_CHAN_CONFIG00

#define ADCInput_SAR_CHAN_WORK_REG           (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_WORK00 )
#define ADCInput_SAR_CHAN_WORK_PTR           ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_WORK00 )

#define ADCInput_SAR_CHAN_RESULT_REG         (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT00 )
#define ADCInput_SAR_CHAN_RESULT_PTR         ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT00 )
#define ADCInput_SAR_CHAN_RESULT_IND         ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT00

#define ADCInput_SAR_CHAN0_RESULT_REG         (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT00 )
#define ADCInput_SAR_CHAN0_RESULT_PTR         ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT00 )

#define ADCInput_SAR_CHAN1_RESULT_REG         (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT01 )
#define ADCInput_SAR_CHAN1_RESULT_PTR         ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT01 )

#define ADCInput_SAR_CHAN2_RESULT_REG         (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT02 )
#define ADCInput_SAR_CHAN2_RESULT_PTR         ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT02 )

#define ADCInput_SAR_CHAN3_RESULT_REG         (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT03 )
#define ADCInput_SAR_CHAN3_RESULT_PTR         ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT03 )

#define ADCInput_SAR_CHAN4_RESULT_REG         (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT04 )
#define ADCInput_SAR_CHAN4_RESULT_PTR         ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT04 )

#define ADCInput_SAR_CHAN5_RESULT_REG         (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT05 )
#define ADCInput_SAR_CHAN5_RESULT_PTR         ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT05 )

#define ADCInput_SAR_CHAN6_RESULT_REG         (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT06 )
#define ADCInput_SAR_CHAN6_RESULT_PTR         ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT06 )

#define ADCInput_SAR_CHAN7_RESULT_REG         (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT07 )
#define ADCInput_SAR_CHAN7_RESULT_PTR         ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT07 )

#if(ADCInput_CY_SAR_IP_VER != ADCInput_CY_SAR_IP_VER0)
    #define ADCInput_SAR_CHAN8_RESULT_REG     (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT08 )
    #define ADCInput_SAR_CHAN8_RESULT_PTR     ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT08 )

    #define ADCInput_SAR_CHAN9_RESULT_REG     (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT09 )
    #define ADCInput_SAR_CHAN9_RESULT_PTR     ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT09 )

    #define ADCInput_SAR_CHAN10_RESULT_REG    (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT10 )
    #define ADCInput_SAR_CHAN10_RESULT_PTR    ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT10 )

    #define ADCInput_SAR_CHAN11_RESULT_REG    (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT11 )
    #define ADCInput_SAR_CHAN11_RESULT_PTR    ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT11 )

    #define ADCInput_SAR_CHAN12_RESULT_REG    (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT12 )
    #define ADCInput_SAR_CHAN12_RESULT_PTR    ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT12 )

    #define ADCInput_SAR_CHAN13_RESULT_REG    (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT13 )
    #define ADCInput_SAR_CHAN13_RESULT_PTR    ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT13 )

    #define ADCInput_SAR_CHAN14_RESULT_REG    (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT14 )
    #define ADCInput_SAR_CHAN14_RESULT_PTR    ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT14 )

    #define ADCInput_SAR_CHAN15_RESULT_REG    (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT15 )
    #define ADCInput_SAR_CHAN15_RESULT_PTR    ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT15 )
#endif /* (ADCInput_CY_SAR_IP_VER != ADCInput_CY_SAR_IP_VER0) */

#define ADCInput_SAR_CHAN_WORK_VALID_REG     (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_WORK_VALID)
#define ADCInput_SAR_CHAN_WORK_VALID_PTR     ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_WORK_VALID)

#define ADCInput_SAR_CHAN_RESULT_VALID_REG  ( *(reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT_VALID )
#define ADCInput_SAR_CHAN_RESULT_VALID_PTR  ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_CHAN_RESULT_VALID )

#define ADCInput_SAR_STATUS_REG              (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_STATUS )
#define ADCInput_SAR_STATUS_PTR              ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_STATUS )

#define ADCInput_SAR_AVG_START_REG           (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_AVG_STAT )
#define ADCInput_SAR_AVG_START_PTR           ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_AVG_STAT )

#define ADCInput_SAR_INTR_REG                (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_INTR )
#define ADCInput_SAR_INTR_PTR                ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_INTR )

#define ADCInput_SAR_INTR_SET_REG            (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_INTR_SET )
#define ADCInput_SAR_INTR_SET_PTR            ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_INTR_SET )

#define ADCInput_SAR_INTR_MASK_REG           (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_INTR_MASK )
#define ADCInput_SAR_INTR_MASK_PTR           ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_INTR_MASK )

#define ADCInput_SAR_INTR_MASKED_REG         (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_INTR_MASKED )
#define ADCInput_SAR_INTR_MASKED_PTR         ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_INTR_MASKED )

#define ADCInput_SAR_SATURATE_INTR_REG       (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_SATURATE_INTR )
#define ADCInput_SAR_SATURATE_INTR_PTR       ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_SATURATE_INTR )

#define ADCInput_SAR_SATURATE_INTR_SET_REG   (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_SATURATE_INTR_SET )
#define ADCInput_SAR_SATURATE_INTR_SET_PTR   ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_SATURATE_INTR_SET )

#define ADCInput_SAR_SATURATE_INTR_MASK_REG (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_SATURATE_INTR_MASK )
#define ADCInput_SAR_SATURATE_INTR_MASK_PTR ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_SATURATE_INTR_MASK )

#define ADCInput_SAR_SATURATE_INTR_MASKED_REG \
                                                 (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_SATURATE_INTR_MASKED )
#define ADCInput_SAR_SATURATE_INTR_MASKED_PTR \
                                                 ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_SATURATE_INTR_MASKED )

#define ADCInput_SAR_RANGE_INTR_REG          (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_RANGE_INTR )
#define ADCInput_SAR_RANGE_INTR_PTR          ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_RANGE_INTR )

#define ADCInput_SAR_RANGE_INTR_SET_REG      (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_RANGE_INTR_SET )
#define ADCInput_SAR_RANGE_INTR_SET_PTR      ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_RANGE_INTR_SET )

#define ADCInput_SAR_RANGE_INTR_MASK_REG     (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_RANGE_INTR_MASK )
#define ADCInput_SAR_RANGE_INTR_MASK_PTR     ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_RANGE_INTR_MASK )

#define ADCInput_SAR_RANGE_INTR_MASKED_REG   (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_RANGE_INTR_MASKED )
#define ADCInput_SAR_RANGE_INTR_MASKED_PTR   ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_RANGE_INTR_MASKED )

#define ADCInput_SAR_INTR_CAUSE_REG          (*(reg32 *) ADCInput_cy_psoc4_sar__SAR_INTR_CAUSE )
#define ADCInput_SAR_INTR_CAUSE_PTR          ( (reg32 *) ADCInput_cy_psoc4_sar__SAR_INTR_CAUSE )

#if(ADCInput_INJ_CHANNEL_ENABLED)
    #define ADCInput_SAR_INJ_CHAN_CONFIG_REG \
                                                 (*(reg32 *) ADCInput_cy_psoc4_sarmux_8__SAR_INJ_CHAN_CONFIG )
    #define ADCInput_SAR_INJ_CHAN_CONFIG_PTR    \
                                                 ( (reg32 *) ADCInput_cy_psoc4_sarmux_8__SAR_INJ_CHAN_CONFIG )

    #define ADCInput_SAR_INJ_RESULT_REG    (*(reg32 *) ADCInput_cy_psoc4_sarmux_8__SAR_INJ_RESULT )
    #define ADCInput_SAR_INJ_RESULT_PTR    ( (reg32 *) ADCInput_cy_psoc4_sarmux_8__SAR_INJ_RESULT )
#endif /* ADCInput_INJ_CHANNEL_ENABLED */
    
#define ADCInput_MUX_SWITCH0_REG           (*(reg32 *)  ADCInput_cy_psoc4_sar__SAR_MUX_SWITCH0 )
#define ADCInput_MUX_SWITCH0_PTR           ( (reg32 *)  ADCInput_cy_psoc4_sar__SAR_MUX_SWITCH0 )

#define ADCInput_MUX_SWITCH_HW_CTRL_REG    (*(reg32 *)  ADCInput_cy_psoc4_sar__SAR_MUX_SWITCH_HW_CTRL )
#define ADCInput_MUX_SWITCH_HW_CTRL_PTR    ( (reg32 *)  ADCInput_cy_psoc4_sar__SAR_MUX_SWITCH_HW_CTRL )

#define ADCInput_PUMP_CTRL_REG             (*(reg32 *)  ADCInput_cy_psoc4_sar__SAR_PUMP_CTRL )
#define ADCInput_PUMP_CTRL_PTR             ( (reg32 *)  ADCInput_cy_psoc4_sar__SAR_PUMP_CTRL )

#define ADCInput_ANA_TRIM_REG              (*(reg32 *)  ADCInput_cy_psoc4_sar__SAR_ANA_TRIM )
#define ADCInput_ANA_TRIM_PTR              ( (reg32 *)  ADCInput_cy_psoc4_sar__SAR_ANA_TRIM )

#define ADCInput_WOUNDING_REG              (*(reg32 *)  ADCInput_cy_psoc4_sar__SAR_WOUNDING )
#define ADCInput_WOUNDING_PTR              ( (reg32 *)  ADCInput_cy_psoc4_sar__SAR_WOUNDING )


/**************************************
*       Register Constants
**************************************/
#define ADCInput_INTC_NUMBER                (ADCInput_IRQ__INTC_NUMBER)
#define ADCInput_INTC_PRIOR_NUMBER          (ADCInput_IRQ__INTC_PRIOR_NUM)

/* defines for CTRL register */
#define ADCInput_VREF_INTERNAL1024          (0x00000040Lu)
#define ADCInput_VREF_EXTERNAL              (0x00000050Lu)
#define ADCInput_VREF_VDDA_2                (0x00000060Lu)
#define ADCInput_VREF_VDDA                  (0x00000070Lu)
#define ADCInput_VREF_INTERNAL1024BYPASSED  (0x000000C0Lu)
#define ADCInput_VREF_VDDA_2BYPASSED        (0x000000E0Lu)
#define ADCInput_VREF_INTERNALVREF          (0x00000040Lu)
#define ADCInput_VREF_INTERNALVREFBYPASSED  (0x000000C0Lu)

#define ADCInput_NEG_VSSA_KELVIN            (0x00000000Lu)
#define ADCInput_NEG_VSSA                   (0x00000200Lu)
#define ADCInput_NEG_VREF                   (0x00000E00Lu)
#if(ADCInput_TOTAL_CHANNELS_NUM > 1u)
    #define ADCInput_NEG_OTHER              (uint16)((uint16)ADCInput_cy_psoc4_sarmux_8__VNEG0 << 9u)
#else
    #define ADCInput_NEG_OTHER              (0)
#endif /* ADCInput_TOTAL_CHANNELS_NUM > 1u */

#define ADCInput_SAR_HW_CTRL_NEGVREF        (0x00002000Lu)

#define ADCInput_BOOSTPUMP_EN               (0x00100000Lu)

#define ADCInput_NORMAL_PWR                 (0x00000000Lu)
#define ADCInput_HALF_PWR                   (0x01000000Lu)
#define ADCInput_MORE_PWR                   (0x02000000Lu)
#define ADCInput_QUARTER_PWR                (0x03000000Lu)
#define ADCInput_DEEPSLEEP_ON               (0x08000000Lu)

#define ADCInput_DSI_SYNC_CONFIG            (0x10000000Lu)
#define ADCInput_DSI_MODE                   (0x20000000Lu)
#define ADCInput_SWITCH_DISABLE             (0x40000000Lu)
#define ADCInput_ENABLE                     (0x80000000Lu)

/* defines for STATUS register */
#define ADCInput_STATUS_BUSY                (0x80000000Lu)

/* defines for SAMPLE_CTRL register */
#define ADCInput_ALT_RESOLUTION_10BIT       (0x00000001Lu)
#define ADCInput_ALT_RESOLUTION_8BIT        (0x00000000Lu)

#define ADCInput_DATA_ALIGN_LEFT            (0x00000002Lu)
#define ADCInput_DATA_ALIGN_RIGHT           (0x00000000Lu)

#define ADCInput_SE_SIGNED_RESULT           (0x00000004Lu)
#define ADCInput_SE_UNSIGNED_RESULT         (0x00000000Lu)

#define ADCInput_DIFF_SIGNED_RESULT         (0x00000008Lu)
#define ADCInput_DIFF_UNSIGNED_RESULT       (0x00000000Lu)

#define ADCInput_AVG_CNT_OFFSET             (4u)
#define ADCInput_AVG_CNT_MASK               (0x00000070Lu)
#define ADCInput_AVG_SHIFT                  (0x00000080Lu)

#define ADCInput_CONTINUOUS_EN              (0x00010000Lu)
#define ADCInput_DSI_TRIGGER_EN             (0x00020000Lu)
#define ADCInput_DSI_TRIGGER_LEVEL          (0x00040000Lu)
#define ADCInput_DSI_SYNC_TRIGGER           (0x00080000Lu)
#define ADCInput_EOS_DSI_OUT_EN             (0x80000000Lu)

/* defines for SAMPLE_TIME01 / SAMPLE_TIME23 registers */
#define ADCInput_SAMPLE_TIME13_OFFSET       (16u)
#define ADCInput_SAMPLE_TIME02_MASK         (0x000003FFLu)
#define ADCInput_SAMPLE_TIME13_MASK         (0x03FF0000Lu)

/* defines for RANGE_THRES registers */
#define ADCInput_RANGE_HIGH_OFFSET          (16u)
#define ADCInput_RANGE_HIGH_MASK            (0xFFFF0000Lu)
#define ADCInput_RANGE_LOW_MASK             (0x0000FFFFLu)

/* defines for RANGE_COND register */
/* Compare mode setting constants:
*    BELOW   - Result < Low_Limit
*    INSIDE  - Low_Limit <= Result < High_Limit
*    ABOVE   - High_Limit <= Result
*    OUTSIDE - (Result < Low_Limit) or (High_Limit <= Result)
*/
#define ADCInput_CMP_MODE_BELOW             (0x00000000Lu)
#define ADCInput_CMP_MODE_INSIDE            (0x40000000Lu)
#define ADCInput_CMP_MODE_ABOVE             (0x80000000Lu)
#define ADCInput_CMP_MODE_OUTSIDE           (0xC0000000Lu)
#define ADCInput_CMP_OFFSET                 (30u)

/* defines for _START_CTRL register */
#define ADCInput_FW_TRIGGER                 (0x00000001Lu)

/* defines for DFT_CTRL register */
#define ADCInput_DLY_INC                    (0x00000001Lu)
#define ADCInput_HIZ                        (0x00000002Lu)
#define ADCInput_DFT_INC_MASK               (0x000F0000Lu)
#define ADCInput_DFT_OUTC_MASK              (0x00700000Lu)
#define ADCInput_SEL_CSEL_DFT_MASK          (0x0F000000Lu)

/* configuration for clock speed > 9 Mhz based on
* characterization results
*/
#define ADCInput_SEL_CSEL_DFT_CHAR          (0x03000000Lu)
#define ADCInput_EN_CSEL_DFT                (0x10000000Lu)
#define ADCInput_DCEN                       (0x20000000Lu)
#define ADCInput_ADFT_OVERRIDE              (0x80000000Lu)

/* defines for CHAN_CONFIG / DIE_CHAN_CONFIG register
*  and channelsConfig parameter
*/
#define ADCInput_SARMUX_VIRT_SELECT         (0x00000070Lu)
#define ADCInput_DIFFERENTIAL_EN            (0x00000100Lu)
#define ADCInput_ALT_RESOLUTION_ON          (0x00000200Lu)
#define ADCInput_AVERAGING_EN               (0x00000400Lu)

#define ADCInput_SAMPLE_TIME_SEL_SHIFT      (12u)
#define ADCInput_SAMPLE_TIME_SEL_MASK       (0x00003000Lu)

#define ADCInput_CHANNEL_CONFIG_MASK        (0x00003700Lu)

/* for CHAN_CONFIG only */
#define ADCInput_DSI_OUT_EN                 (0x80000000Lu)

/* for INJ_CHAN_CONFIG only */
#define ADCInput_INJ_TAILGATING             (0x40000000Lu)
#define ADCInput_INJ_CHAN_EN                (0x80000000Lu)

/* defines for CHAN_WORK register */
#define ADCInput_SAR_WRK_MAX_12BIT          (0x00001000Lu)
#define ADCInput_SAR_WRK_MAX_10BIT          (0x00000400Lu)
#define ADCInput_SAR_WRK_MAX_8BIT           (0x00000100Lu)

/* defines for CHAN_RESULT register */
#define ADCInput_RESULT_MASK                (0x0000FFFFLu)
#define ADCInput_SATURATE_INTR_MIR          (0x20000000Lu)
#define ADCInput_RANGE_INTR_MIR             (0x40000000Lu)
#define ADCInput_CHAN_RESULT_VALID_MIR      (0x80000000Lu)

/* defines for INTR_MASK register */
#define ADCInput_EOS_MASK                   (0x00000001Lu)
#define ADCInput_OVERFLOW_MASK              (0x00000002Lu)
#define ADCInput_FW_COLLISION_MASK          (0x00000004Lu)
#define ADCInput_DSI_COLLISION_MASK         (0x00000008Lu)
#define ADCInput_INJ_EOC_MASK               (0x00000010Lu)
#define ADCInput_INJ_SATURATE_MASK          (0x00000020Lu)
#define ADCInput_INJ_RANGE_MASK             (0x00000040Lu)
#define ADCInput_INJ_COLLISION_MASK         (0x00000080Lu)

/* defines for INJ_RESULT register */
#define ADCInput_INJ_COLLISION_INTR_MIR     (0x10000000Lu)
#define ADCInput_INJ_SATURATE_INTR_MIR      (0x20000000Lu)
#define ADCInput_INJ_RANGE_INTR_MIR         (0x40000000Lu)
#define ADCInput_INJ_EOC_INTR_MIR           (0x80000000Lu)

/* defines for MUX_SWITCH0 register */
#define ADCInput_MUX_FW_VSSA_VMINUS         (0x00010000Lu)

/* defines for PUMP_CTRL register */
#define ADCInput_PUMP_CTRL_ENABLED          (0x80000000Lu)

/* additional defines for channelsConfig parameter */
#define ADCInput_IS_SATURATE_EN_MASK        (0x00000001Lu)
#define ADCInput_IS_RANGE_CTRL_EN_MASK      (0x00000002Lu)

/* defines for WOUNDING register */
#define ADCInput_WOUNDING_12BIT             (0x00000000Lu)
#define ADCInput_WOUNDING_10BIT             (0x00000001Lu)
#define ADCInput_WOUNDING_8BIT              (0x00000002Lu)

/* Trim value based on characterization */
#define ADCInput_TRIM_COEF                  (2u)

#if(ADCInput_MAX_RESOLUTION == ADCInput_RESOLUTION_10)
    #define ADCInput_ALT_WOUNDING           ADCInput_WOUNDING_10BIT
#else
    #define ADCInput_ALT_WOUNDING           ADCInput_WOUNDING_8BIT
#endif /* ADCInput_MAX_RESOLUTION == ADCInput_RESOLUTION_10 */

#if(ADCInput_DEFAULT_VREF_SEL == ADCInput__VDDA_2)
    #define ADCInput_DEFAULT_VREF_SOURCE    ADCInput_VREF_VDDA_2
#elif(ADCInput_DEFAULT_VREF_SEL == ADCInput__VDDA)
    #define ADCInput_DEFAULT_VREF_SOURCE    ADCInput_VREF_VDDA
#elif(ADCInput_DEFAULT_VREF_SEL == ADCInput__INTERNAL1024)
    #define ADCInput_DEFAULT_VREF_SOURCE    ADCInput_VREF_INTERNAL1024
#elif(ADCInput_DEFAULT_VREF_SEL == ADCInput__INTERNAL1024BYPASSED)
    #define ADCInput_DEFAULT_VREF_SOURCE    ADCInput_VREF_INTERNAL1024BYPASSED
#elif(ADCInput_DEFAULT_VREF_SEL == ADCInput__INTERNALVREF)
    #define ADCInput_DEFAULT_VREF_SOURCE    ADCInput_VREF_INTERNALVREF
#elif(ADCInput_DEFAULT_VREF_SEL == ADCInput__INTERNALVREFBYPASSED)
    #define ADCInput_DEFAULT_VREF_SOURCE    ADCInput_VREF_INTERNALVREFBYPASSED
#elif(ADCInput_DEFAULT_VREF_SEL == ADCInput__VDDA_2BYPASSED)
    #define ADCInput_DEFAULT_VREF_SOURCE    ADCInput_VREF_VDDA_2BYPASSED
#else
    #define ADCInput_DEFAULT_VREF_SOURCE    ADCInput_VREF_EXTERNAL
#endif /* ADCInput_DEFAULT_VREF_SEL == ADCInput__VDDA_2 */

#if(ADCInput_DEFAULT_NEG_INPUT_SEL == ADCInput__VSS)
    /* Connect NEG input of SARADC to VSSA close to the SARADC for single channel mode */
    #if(ADCInput_TOTAL_CHANNELS_NUM == 1u)
        #define ADCInput_DEFAULT_SE_NEG_INPUT    ADCInput_NEG_VSSA
    #else
        #define ADCInput_DEFAULT_SE_NEG_INPUT    ADCInput_NEG_VSSA_KELVIN
    #endif /* (ADCInput_TOTAL_CHANNELS_NUM == 1u) */
    /* Do not connect VSSA to VMINUS when one channel in differential mode used */
    #if((ADCInput_TOTAL_CHANNELS_NUM == 1u) && (ADCInput_CHANNELS_MODE != 0u))
        #define ADCInput_DEFAULT_MUX_SWITCH0     0u
    #else    /* miltiple channels or one single channel */
        #define ADCInput_DEFAULT_MUX_SWITCH0     ADCInput_MUX_FW_VSSA_VMINUS
    #endif /* (ADCInput_TOTAL_CHANNELS_NUM == 1u) */
#elif(ADCInput_DEFAULT_NEG_INPUT_SEL == ADCInput__VREF)
    /* Do not connect VNEG to VREF when one channel in differential mode used */
    #if((ADCInput_TOTAL_CHANNELS_NUM == 1u) && (ADCInput_CHANNELS_MODE != 0u))
        #define ADCInput_DEFAULT_SE_NEG_INPUT    0u
    #else    /* miltiple channels or one single channel */
        #define ADCInput_DEFAULT_SE_NEG_INPUT    ADCInput_NEG_VREF
    #endif /* (ADCInput_TOTAL_CHANNELS_NUM == 1u) */
    #define ADCInput_DEFAULT_MUX_SWITCH0     0u
#elif (ADCInput_SINGLE_PRESENT != 0u)
    #define ADCInput_DEFAULT_SE_NEG_INPUT    ADCInput_NEG_OTHER
    #define ADCInput_DEFAULT_MUX_SWITCH0     0u
#else
    #define ADCInput_DEFAULT_SE_NEG_INPUT    0u
    #define ADCInput_DEFAULT_MUX_SWITCH0     0u
#endif /* ADCInput_DEFAULT_NEG_INPUT_SEL == ADCInput__VREF */

/* If the SAR is configured for multiple channels, always set SAR_HW_CTRL_NEGVREF to 1 */
#if(ADCInput_TOTAL_CHANNELS_NUM == 1u)
    #define ADCInput_DEFAULT_HW_CTRL_NEGVREF 0u
#else
    #define ADCInput_DEFAULT_HW_CTRL_NEGVREF ADCInput_SAR_HW_CTRL_NEGVREF
#endif /* (ADCInput_TOTAL_CHANNELS_NUM == 1u) */


#if(ADCInput_DEFAULT_ALT_RESOLUTION_SEL == ADCInput__RES8)
    #define ADCInput_DEFAULT_ALT_RESOLUTION     (ADCInput_ALT_RESOLUTION_8BIT)
    #define ADCInput_DEFAULT_MAX_WRK_ALT        (ADCInput_SAR_WRK_MAX_8BIT)
#else
    #define ADCInput_DEFAULT_ALT_RESOLUTION     (ADCInput_ALT_RESOLUTION_10BIT)
    #define ADCInput_DEFAULT_MAX_WRK_ALT        (ADCInput_SAR_WRK_MAX_10BIT)
#endif /* End ADCInput_DEFAULT_ALT_RESOLUTION_SEL == ADCInput__RES8 */

#if(ADCInput_DEFAULT_JUSTIFICATION_SEL == ADCInput__RIGHT)
    #define ADCInput_DEFAULT_JUSTIFICATION  ADCInput_DATA_ALIGN_RIGHT
#else
    #define ADCInput_DEFAULT_JUSTIFICATION  ADCInput_DATA_ALIGN_LEFT
#endif /* ADCInput_DEFAULT_JUSTIFICATION_SEL == ADCInput__RIGHT */

#if(ADCInput_DEFAULT_DIFF_RESULT_FORMAT_SEL == ADCInput__FSIGNED)
    #define ADCInput_DEFAULT_DIFF_RESULT_FORMAT ADCInput_DIFF_SIGNED_RESULT
#else
    #define ADCInput_DEFAULT_DIFF_RESULT_FORMAT ADCInput_DIFF_UNSIGNED_RESULT
#endif /* ADCInput_DEFAULT_DIFF_RESULT_FORMAT_SEL == ADCInput__FSIGNED */

#if(ADCInput_DEFAULT_SE_RESULT_FORMAT_SEL == ADCInput__FSIGNED)
    #define ADCInput_DEFAULT_SE_RESULT_FORMAT ADCInput_SE_SIGNED_RESULT
#else
    #define ADCInput_DEFAULT_SE_RESULT_FORMAT ADCInput_SE_UNSIGNED_RESULT
#endif /* ADCInput_DEFAULT_SE_RESULT_FORMAT_SEL == ADCInput__FSIGNED */

#if(ADCInput_DEFAULT_SAMPLE_MODE_SEL == ADCInput__FREERUNNING)
    #define ADCInput_DSI_TRIGGER        0u
#else /* Firmware trigger */
    #define ADCInput_DSI_TRIGGER        (ADCInput_DSI_TRIGGER_EN | ADCInput_DSI_SYNC_TRIGGER)
#endif /* End ADCInput_DEFAULT_SAMPLE_MODE == ADCInput__FREERUNNING */

#if(ADCInput_INJ_CHANNEL_ENABLED)
    #define ADCInput_SAR_INTR_MASK      (ADCInput_EOS_MASK | ADCInput_INJ_EOC_MASK)
#else
    #define ADCInput_SAR_INTR_MASK      (ADCInput_EOS_MASK)
#endif /* ADCInput_INJ_CHANNEL_ENABLED*/

#if(ADCInput_DEFAULT_AVG_MODE == ADCInput__FIXEDRESOLUTION)
    #define ADCInput_AVG_SHIFT_MODE     ADCInput_AVG_SHIFT
#else
    #define ADCInput_AVG_SHIFT_MODE     0u
#endif /* End ADCInput_DEFAULT_AVG_MODE */

#define ADCInput_COMPARE_MODE           (uint32)((uint32)(ADCInput_DEFAULT_COMPARE_MODE) \
                                                << ADCInput_CMP_OFFSET)

#if(ADCInput_TOTAL_CHANNELS_NUM > 1u)
    #define ADCInput_DEFAULT_SWITCH_CONF    0u
#else /* Disable SAR sequencer from enabling routing switches in single channel mode */
    #define ADCInput_DEFAULT_SWITCH_CONF    ADCInput_SWITCH_DISABLE
#endif /* End ADCInput_TOTAL_CHANNELS_NUM > 1 */

#define ADCInput_DEFAULT_POWER \
       ((ADCInput_NOMINAL_CLOCK_FREQ > (ADCInput_MAX_FREQUENCY / 4)) ? ADCInput_NORMAL_PWR : \
       ((ADCInput_NOMINAL_CLOCK_FREQ > (ADCInput_MAX_FREQUENCY / 8)) ? ADCInput_HALF_PWR : \
                                                                                       ADCInput_QUARTER_PWR))

#define ADCInput_DEFAULT_CTRL_REG_CFG       (ADCInput_DEFAULT_VREF_SOURCE \
                                                   | ADCInput_DEFAULT_SE_NEG_INPUT \
                                                   | ADCInput_DEFAULT_HW_CTRL_NEGVREF \
                                                   | ADCInput_DEFAULT_POWER \
                                                   | ADCInput_DSI_SYNC_CONFIG \
                                                   | ADCInput_DEFAULT_SWITCH_CONF)

#define ADCInput_DEFAULT_SAMPLE_CTRL_REG_CFG (ADCInput_DEFAULT_DIFF_RESULT_FORMAT \
                                                    | ADCInput_DEFAULT_SE_RESULT_FORMAT \
                                                    | ADCInput_DEFAULT_JUSTIFICATION \
                                                    | ADCInput_DEFAULT_ALT_RESOLUTION \
                                           | (uint8)(ADCInput_DEFAULT_AVG_SAMPLES_NUM \
                                                   << ADCInput_AVG_CNT_OFFSET) \
                                                    | ADCInput_AVG_SHIFT_MODE \
                                                    | ADCInput_DSI_TRIGGER \
                                                    | ADCInput_EOS_DSI_OUT_EN)

#define ADCInput_DEFAULT_RANGE_THRES_REG_CFG (ADCInput_DEFAULT_LOW_LIMIT \
            | (uint32)((uint32)ADCInput_DEFAULT_HIGH_LIMIT << ADCInput_RANGE_HIGH_OFFSET))

#define ADCInput_DEFAULT_SAMPLE_TIME01_REG_CFG (ADCInput_DEFAULT_ACLKS_NUM \
            | (uint32)((uint32)ADCInput_DEFAULT_BCLKS_NUM << ADCInput_SAMPLE_TIME13_OFFSET))

#define ADCInput_DEFAULT_SAMPLE_TIME23_REG_CFG (ADCInput_DEFAULT_CCLKS_NUM \
            | (uint32)((uint32)ADCInput_DEFAULT_DCLKS_NUM << ADCInput_SAMPLE_TIME13_OFFSET))


#endif /* End CY_ADC_SAR_SEQ_ADCInput_H */


/* [] END OF FILE */
