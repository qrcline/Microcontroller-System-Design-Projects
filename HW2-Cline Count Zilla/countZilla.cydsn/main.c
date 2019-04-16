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
    char mystring[20];
    int count=0;
    int Acount = 0;


    
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
   
     
        while(1) {
	       // sprintf(mystring, "%5d", count);
            //GLCD_PrintString(mystring, 10, 10, GLCD_WHITE, GLCD_BLACK);
          

         }
}




/* [] END OF FILE */
