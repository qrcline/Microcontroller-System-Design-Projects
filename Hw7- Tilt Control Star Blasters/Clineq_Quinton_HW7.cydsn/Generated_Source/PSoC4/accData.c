/*******************************************************************************
* File Name: accData.c  
* Version 1.70
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/


#include <cydevice_trm.h>
#include <CyLib.h>
#include <accData.h>
#include "cyapicallbacks.h"

#if !defined(accData__REMOVED) /* Check for removal by optimization */

/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START accData_intc` */
#include "project.h"

#include "stdlib.h"
#include  "stdbool.h"
#include "stdio.h" 
   extern int16 stars[300]; 
   extern int16 twinkleStars;
   extern int16 i;
   extern int16 x;
   extern int16 y;
    extern int16 xOld;
   extern int16 yOld;
   extern uint32 counter;
   extern uint8 ReadBuffer[10];
   extern uint8 WriteBuffer[10];
//For accel setup
    extern uint8 PWR_CTL; 
   extern  uint8 DATA_FORMAT; 
   extern  uint8 TAP_AXES; 
    extern uint8 INT_ENABLE;
   extern  uint8 INT_MAP;
   extern  uint8 INT_SOURCE;
    extern uint8 DATAX0; 
   extern  uint8 DATAX1;
   extern  uint8 DATAY0; 
   extern  uint8 DATAY1;
   extern  uint8 DATAZ0; 
    extern uint8 DATAZ1;
    
    //For accel tap
   extern  uint8 THRESH_TAP;
   extern  uint8 DUR;    
   extern  uint8 Latent;
   extern  uint8 Window;
   extern void WriteSensor(uint8 *WriteBuffer, int numvals);
   extern void ReadSensor(uint8 *ReadBuffer, int numvals) ; 
   extern void  drawScope(int16 x,int16 y,int32 color); 
   extern void drawStars(int16 starArray[]);

    //For testing
    extern char stringX[10]; 
    extern char stringY[10]; 
    extern char stringZ[10]; 
/* `#END` */

extern cyisraddress CyRamVectors[CYINT_IRQ_BASE + CY_NUM_INTERRUPTS];

/* Declared in startup, used to set unused interrupts to. */
CY_ISR_PROTO(IntDefaultHandler);


/*******************************************************************************
* Function Name: accData_Start
********************************************************************************
*
* Summary:
*  Set up the interrupt and enable it. This function disables the interrupt, 
*  sets the default interrupt vector, sets the priority from the value in the
*  Design Wide Resources Interrupt Editor, then enables the interrupt to the 
*  interrupt controller.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void accData_Start(void)
{
    /* For all we know the interrupt is active. */
    accData_Disable();

    /* Set the ISR to point to the accData Interrupt. */
    accData_SetVector(&accData_Interrupt);

    /* Set the priority. */
    accData_SetPriority((uint8)accData_INTC_PRIOR_NUMBER);

    /* Enable it. */
    accData_Enable();
}


/*******************************************************************************
* Function Name: accData_StartEx
********************************************************************************
*
* Summary:
*  Sets up the interrupt and enables it. This function disables the interrupt,
*  sets the interrupt vector based on the address passed in, sets the priority 
*  from the value in the Design Wide Resources Interrupt Editor, then enables 
*  the interrupt to the interrupt controller.
*  
*  When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*  used to provide consistent definition across compilers:
*  
*  Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*   Function prototype example:
*   CY_ISR_PROTO(MyISR);
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void accData_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    accData_Disable();

    /* Set the ISR to point to the accData Interrupt. */
    accData_SetVector(address);

    /* Set the priority. */
    accData_SetPriority((uint8)accData_INTC_PRIOR_NUMBER);

    /* Enable it. */
    accData_Enable();
}


/*******************************************************************************
* Function Name: accData_Stop
********************************************************************************
*
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
void accData_Stop(void)
{
    /* Disable this interrupt. */
    accData_Disable();

    /* Set the ISR to point to the passive one. */
    accData_SetVector(&IntDefaultHandler);
}


/*******************************************************************************
* Function Name: accData_Interrupt
********************************************************************************
*
* Summary:
*   The default Interrupt Service Routine for accData.
*
*   Add custom code between the START and END comments to keep the next version
*   of this file from over-writing your code.
*
*   Note You may use either the default ISR by using this API, or you may define
*   your own separate ISR through ISR_StartEx().
*
* Parameters:  
*   None
*
* Return:
*   None
*
*******************************************************************************/
CY_ISR(accData_Interrupt)
{
    #ifdef accData_INTERRUPT_INTERRUPT_CALLBACK
        accData_Interrupt_InterruptCallback();
    #endif /* accData_INTERRUPT_INTERRUPT_CALLBACK */ 

    /*  Place your Interrupt code here. */
    /* `#START accData_Interrupt` */
     //CyGlobalIntDisable;
    //Black out the previous crosshairs
     //drawScope(x,y,GLCD_BLACK);
    
    //Read acc data
      WriteBuffer[0] = 0x32;
      WriteSensor(WriteBuffer,1); // Write register number
      ReadSensor(ReadBuffer,6);   // Reads DataX0 through Data Z1
    
    //Get the data for x,y,z by shifting and or the readbuffers
       int16 xData= -((ReadBuffer[1]<<8 )| ReadBuffer[0]);
       int16 yData= ((ReadBuffer[3]<<8) | ReadBuffer[2]);
       int16 zData= ((ReadBuffer[5]<<8 )| ReadBuffer[4]);
       
        //format the data for testing 
       //CyGlobalIntDisable; 
//        sprintf(stringX, "X:    %5d",xData);
//        GLCD_PrintString(stringX,30,30,GLCD_BLUE,GLCD_BLACK);
//        sprintf(stringY, "Y:    %5d",yData);
//        GLCD_PrintString(stringY,50,30,GLCD_BLUE,GLCD_BLACK);
      // sprintf(stringZ, "Z:    %5d",zData);
       //GLCD_PrintString(stringZ,70,30,GLCD_BLUE,GLCD_BLACK);
       // CyGlobalIntEnable; 
        
        
      
       



        
         if((xData>2) &&xData !=xOld ||yData!=yOld) //Move up 
        {
            
            drawScope(x,y,GLCD_BLACK);//Draw over old scope
            drawStars(stars); //draw stars back 
            if(x<10) //keep from going off screen 
            {
                 x=10;
            }  
            else
            {
                x=x-(xData/2); // moves in proportion to the tilt
            }
           
            
              //These two if statments help with going at an angle
            // Move on the y axis 
            if(yData>0&&yData!=yOld)
            {
                if(y>120) // keeps from going off screen 
                {
                     y=120;
                }  
                else
                { 
                    y=y+(yData/2); //moves in proportion to the tilt
                    
                }
               
            }
            else if(yData<0&&yData!=yOld)
            {
                if(y<10) //keeps from going off screen
                {
                     y=10;
                }  
                else
                { 
                    y=y+(yData/2); //move in proportion to the tilt
                    
                }
            }
          
            drawScope(x,y,GLCD_YELLOW); //draw the scope
        }
        
        
         if((xData<2) &&xData !=xOld||yData!=yOld) //Move down
        {
            
            drawScope(x,y,GLCD_BLACK);
            drawStars(stars); 
           
            if(x>120) //Keeps from going off screen
            {
                 x=120;
            }  
            else
            {
                x=x-(xData/2); // Move in proportion to the tilt
            }
            
            
            
          
            //These two if statments help with going at an angle
            // Move on the y axis 
            if(yData>0&&yData!=yOld)
            {
                if(y>120) //Keep from going off screen 
                {
                     y=120;
                }  
                else
                { 
                    y=y+(yData/2);// Move in proportion to the tilt
                    
                }
               
            }
            else if(yData<0&&yData!=yOld)
            {
                if(y<10)// Keep from going off screen 
                {
                     y=10;
                }  
                else
                { 
                    y=y+(yData/2);// Move in proportion to the tilt
                    
                }
            }
            drawScope(x,y,GLCD_YELLOW);// Draw scope 
        }
            //Store last value to be used to check if it has moved 
            yOld=yData; 
            xOld=xData; 
//        
        // drawScope(x,y,GLCD_YELLOW);
        CyGlobalIntEnable; 
        Timer_ClearInterrupt(Timer_INTR_MASK_TC);

    /* `#END` */
}


/*******************************************************************************
* Function Name: accData_SetVector
********************************************************************************
*
* Summary:
*   Change the ISR vector for the Interrupt. Note calling accData_Start
*   will override any effect this method would have had. To set the vector 
*   before the component has been started use accData_StartEx instead.
* 
*   When defining ISR functions, the CY_ISR and CY_ISR_PROTO macros should be 
*   used to provide consistent definition across compilers:
*
*   Function definition example:
*   CY_ISR(MyISR)
*   {
*   }
*
*   Function prototype example:
*     CY_ISR_PROTO(MyISR);
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
* Return:
*   None
*
*******************************************************************************/
void accData_SetVector(cyisraddress address)
{
    CyRamVectors[CYINT_IRQ_BASE + accData__INTC_NUMBER] = address;
}


/*******************************************************************************
* Function Name: accData_GetVector
********************************************************************************
*
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*******************************************************************************/
cyisraddress accData_GetVector(void)
{
    return CyRamVectors[CYINT_IRQ_BASE + accData__INTC_NUMBER];
}


/*******************************************************************************
* Function Name: accData_SetPriority
********************************************************************************
*
* Summary:
*   Sets the Priority of the Interrupt. 
*
*   Note calling accData_Start or accData_StartEx will 
*   override any effect this API would have had. This API should only be called
*   after accData_Start or accData_StartEx has been called. 
*   To set the initial priority for the component, use the Design-Wide Resources
*   Interrupt Editor.
*
*   Note This API has no effect on Non-maskable interrupt NMI).
*
* Parameters:
*   priority: Priority of the interrupt, 0 being the highest priority
*             PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*             PSoC 4: Priority is from 0 to 3.
*
* Return:
*   None
*
*******************************************************************************/
void accData_SetPriority(uint8 priority)
{
	uint8 interruptState;
    uint32 priorityOffset = ((accData__INTC_NUMBER % 4u) * 8u) + 6u;
    
	interruptState = CyEnterCriticalSection();
    *accData_INTC_PRIOR = (*accData_INTC_PRIOR & (uint32)(~accData__INTC_PRIOR_MASK)) |
                                    ((uint32)priority << priorityOffset);
	CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: accData_GetPriority
********************************************************************************
*
* Summary:
*   Gets the Priority of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   Priority of the interrupt, 0 being the highest priority
*    PSoC 3 and PSoC 5LP: Priority is from 0 to 7.
*    PSoC 4: Priority is from 0 to 3.
*
*******************************************************************************/
uint8 accData_GetPriority(void)
{
    uint32 priority;
	uint32 priorityOffset = ((accData__INTC_NUMBER % 4u) * 8u) + 6u;

    priority = (*accData_INTC_PRIOR & accData__INTC_PRIOR_MASK) >> priorityOffset;

    return (uint8)priority;
}


/*******************************************************************************
* Function Name: accData_Enable
********************************************************************************
*
* Summary:
*   Enables the interrupt to the interrupt controller. Do not call this function
*   unless ISR_Start() has been called or the functionality of the ISR_Start() 
*   function, which sets the vector and the priority, has been called.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void accData_Enable(void)
{
    /* Enable the general interrupt. */
    *accData_INTC_SET_EN = accData__INTC_MASK;
}


/*******************************************************************************
* Function Name: accData_GetState
********************************************************************************
*
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
* Parameters:
*   None
*
* Return:
*   1 if enabled, 0 if disabled.
*
*******************************************************************************/
uint8 accData_GetState(void)
{
    /* Get the state of the general interrupt. */
    return ((*accData_INTC_SET_EN & (uint32)accData__INTC_MASK) != 0u) ? 1u:0u;
}


/*******************************************************************************
* Function Name: accData_Disable
********************************************************************************
*
* Summary:
*   Disables the Interrupt in the interrupt controller.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void accData_Disable(void)
{
    /* Disable the general interrupt. */
    *accData_INTC_CLR_EN = accData__INTC_MASK;
}


/*******************************************************************************
* Function Name: accData_SetPending
********************************************************************************
*
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
* Parameters:
*   None
*
* Return:
*   None
*
* Side Effects:
*   If interrupts are enabled and the interrupt is set up properly, the ISR is
*   entered (depending on the priority of this interrupt and other pending 
*   interrupts).
*
*******************************************************************************/
void accData_SetPending(void)
{
    *accData_INTC_SET_PD = accData__INTC_MASK;
}


/*******************************************************************************
* Function Name: accData_ClearPending
********************************************************************************
*
* Summary:
*   Clears a pending interrupt in the interrupt controller.
*
*   Note Some interrupt sources are clear-on-read and require the block 
*   interrupt/status register to be read/cleared with the appropriate block API 
*   (GPIO, UART, and so on). Otherwise the ISR will continue to remain in 
*   pending state even though the interrupt itself is cleared using this API.
*
* Parameters:
*   None
*
* Return:
*   None
*
*******************************************************************************/
void accData_ClearPending(void)
{
    *accData_INTC_CLR_PD = accData__INTC_MASK;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
