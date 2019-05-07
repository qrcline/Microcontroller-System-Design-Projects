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
     Backlight_Write(1); 
     B_LED_Write(1);
     G_LED_Write(1);
     PWM_1_Start(); 
     Timer_1_Start(); 
     Timer_1_WriteCounter(0);
   
       //Prints the ms ending for the time
       GLCD_PrintString("ms", 10, 50, GLCD_WHITE, GLCD_BLACK);
        
        //Draw the outer circle and min and max lines
        //This is just for looks
       GLCD_DrawCircle(80,65,45,GLCD_RED); 
       GLCD_Draw_Line_Polar(80,65,270,45,GLCD_RED);
       GLCD_Draw_Line_Polar(80,65,90,45,GLCD_RED);
       GLCD_Draw_Line_Polar(80,65,180,45,GLCD_YELLOW);
       GLCD_DrawCircle(80,65,5,GLCD_YELLOW); 
        while(1)
        {
            //This updates the display with the current count number
	        sprintf(mystring, "%5d", countDisplay);
            GLCD_PrintString(mystring, 10, 10, GLCD_WHITE, GLCD_BLACK);


            if(count != countFollow)
            {
                
                //Takes the count variable and sets to countdisplay
                countDisplay=count;
                //Draws black over the previous line
                GLCD_Draw_Line_Polar(80,65,angle,40,GLCD_BLACK);
                //calculate the angle that the line should be set at
                //This is also known as mapping on arduino platform map() is used
                angle=(((countDisplay +500) * (-180)) / (1000)) + 270;
                //Draw the line to indicat the time before or after
                GLCD_Draw_Line_Polar(80,65,angle,40,GLCD_YELLOW);
                
                //Sets the counter follower to check if the count has changed
                countFollow=count; 
                
                //Draws the small center circle
                GLCD_DrawCircle(80,65,5,GLCD_YELLOW); 
            
                //Draws the red lines back if the yellow line is not on them
                if(angle !=270)
                GLCD_Draw_Line_Polar(80,65,270,45,GLCD_RED);
                if(angle !=90)
                GLCD_Draw_Line_Polar(80,65,90,45,GLCD_RED);
                if(angle !=180)
                GLCD_Draw_Line_Polar(80,65,180,45,GLCD_RED);
            }

         }
}




/* [] END OF FILE */
