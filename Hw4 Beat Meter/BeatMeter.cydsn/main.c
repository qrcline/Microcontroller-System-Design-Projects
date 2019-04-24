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

    char mystring[20];
    int count=0;
    int countFollow=0; 
    int countDisplay=0;
    int angle=0;
   

//This converts the polar cordinates given to the point to point used for the DrawLine
 void GLCD_Draw_Line_Polar(int centerX, int centerY, int angle, int length, int color)
{
    GLCD_DrawLine(centerX,centerY,(length*cos(((angle*M_PI))/180))+centerX,(length*sin(((angle*M_PI))/180))+centerY, color);
  
}
    
int main(void)
{

    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
     GLCD_Start();
     A_Interrupt_ClearPending();
     A_Interrupt_Start();
     B_Interrupt_ClearPending();
     B_Interrupt_Start();
     C_Interrupt_ClearPending();
     C_Interrupt_Start();
     D_Interrupt_ClearPending();
     D_Interrupt_Start();
     StickButton_Interrupt_ClearPending();
     StickButton_Interrupt_Start();
    Backlight_Write(1); 
    B_LED_Write(1);
    G_LED_Write(1);
    PWM_1_Start(); 
    Timer_1_Start(); 
    Timer_1_WriteCounter(0);
   
     
        while(1)
        {
            //This updates the display with the current count number
	        sprintf(mystring, "%5d", countDisplay);
            GLCD_PrintString(mystring, 10, 10, GLCD_WHITE, GLCD_BLACK);
                GLCD_PrintString("ms", 10, 50, GLCD_WHITE, GLCD_BLACK);

            if(count != countFollow)
            {
                
                if(count>500)
                {
                 
                  //countDisplay=(count);
                  countDisplay=(count-500);
                    countDisplay=countDisplay*(-1); 
                
                 GLCD_Draw_Line_Polar(80,65,angle,40,GLCD_BLACK);
               //NewValue = (((OldValue - OldMin) * (NewMax - NewMin)) / (OldMax - OldMin)) + NewMin
                angle=(((count - 0) * (270 - 90)) / (1000 - 0)) + 90;
                GLCD_Draw_Line_Polar(80,65,angle,40,GLCD_YELLOW);
                   
                }
                else
                {
                 countDisplay=count;
                GLCD_Draw_Line_Polar(80,65,angle,40,GLCD_BLACK);
                 angle=(((count - 500) * (180 - 90)) / (1000 - 500)) + 90;
                GLCD_Draw_Line_Polar(80,65,angle,40,GLCD_YELLOW);
                }
                countFollow=count; 
                GLCD_DrawCircle(80,65,5,GLCD_YELLOW); 
            }

         }
}




/* [] END OF FILE */
