/* ========================================
 Quinton Cline
Mini Scope
 * ========================================
*/
#include "project.h"
#include <stdio.h>

    
    int xPos=0; 


   

    
int main(void)
{
    int joyX=0; 
    int freqRaw=50; 
    int freqPeriod=50;
    const int freqMin=50;
    const int freqMax=300; 
    char mystring[4];
  
     GLCD_Start();
     //A_Interrupt_ClearPending();
    Backlight_Write(1);
    GLCD_Clear(GLCD_BLACK);
    sprintf(mystring, "Rate: %4d Hz ",freqRaw); 
    GLCD_PrintString(mystring,110 , 10, GLCD_WHITE, GLCD_BLUE);
    ADCInput_Start(); 
    ADCInput_StartConvert();  //Starts the ADC
    Timer_1_Start(); 
     Timer_1_WriteCounter(0);
     A_Interrupt_Start();
     B_LED_Write(1);
     G_LED_Write(1);
     R_LED_Write(1);
     


CyGlobalIntEnable; /* Enable global interrupts. */
        while(1)
        {
     
            //For getting the X
            if(ADCInput_IsEndConversion(ADCInput_RETURN_STATUS))
            {
                
                joyX= ADCInput_GetResult16(0);  //Sample ADCInput channel 0 for X
                    if(joyX>1900 &&freqRaw<300)
                {
                    freqRaw++; //Increment the freq
                    //freqPeriod=(9000/freqRaw)-1; //map freq to period 
                    Timer_1_WritePeriod((10000/freqRaw)-1); //Set period 
                    sprintf(mystring, "Rate: %4d Hz ",freqRaw); //Format string 
                    CyGlobalIntDisable; //Disable interupt
                    GLCD_PrintString(mystring,110 , 10, GLCD_WHITE, GLCD_BLUE);
                    CyGlobalIntEnable; //enable interupt
                    Timer_1_WriteCounter(0); //Reset counter
                }
                //If pused to the left
                else if(joyX<100 &&freqRaw>50)
                {
                    freqRaw--;  //Decrement freq
                    //freqPeriod=(9000/freqRaw)-1; //Map freq to period
                    Timer_1_WritePeriod((10000/freqRaw)-1); //Write period 
                    sprintf(mystring, "Rate: %4d Hz ",freqRaw); //format freq
                    CyGlobalIntDisable; //Disable interupts
                    GLCD_PrintString(mystring,110 , 10, GLCD_WHITE, GLCD_BLUE); //print 
                    CyGlobalIntEnable; //Enabe interupts 
                   // Timer_1_WriteCounter(0); //Reset counter
                    
                }
                //if pushed to the right
           
            }
             if(xPos>=131) //If at the right of the screen clear screen and reset position xpos to 0
            {
                xPos=0; 
                 sprintf(mystring, "Rate: %4d Hz ",freqRaw);  //Print freq to screen
                 CyGlobalIntDisable;    //Disable interupts
                 GLCD_Clear(GLCD_BLACK);//Clear screen 
                 GLCD_PrintString(mystring,110 , 10, GLCD_WHITE, GLCD_BLUE);////Print
                CyGlobalIntEnable;//Enable interupts
            }

            
         }
}




/* [] END OF FILE */
