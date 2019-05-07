/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <stdio.h>
#define PUSHED 0


#include "stdlib.h"
#include <math.h>
#include <string.h>

    
    int xPos=0; 
    int yPos=0; 


   

    
int main(void)
{
    int freq=0; 
    int freqCapture=0; 
    char mystring[20];
  
     GLCD_Start();
     //A_Interrupt_ClearPending();
    Backlight_Write(1);
    GLCD_Clear(GLCD_BLACK);
    ADCInput_Start(); 
    ADCInput_StartConvert();  //Starts the ADC
    Timer_1_Start(); 
     Timer_1_WriteCounter(0);
     A_Interrupt_Start();
     B_LED_Write(1);
     G_LED_Write(1);
     
CyGlobalIntEnable; /* Enable global interrupts. */
       
        while(1)
        {
            
           
            
            CyGlobalIntDisable;
            sprintf(mystring, "Rate: %4d Hz ",freq); 
            GLCD_PrintString(mystring,110 , 10, GLCD_WHITE, GLCD_BLUE);
            


            CyGlobalIntEnable;

         }
}




/* [] END OF FILE */
