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
#include "stdlib.h"

void drawStars(int16 starArray[])
{
   int16 i=0;
    for(i=0;i<300;i++)
    {
        GLCD_DrawLine(starArray[i],starArray[i+1],starArray[i],starArray[i+1],GLCD_WHITE);
    }
}

void  drawScope(int16 x,int16 y,int32 color)
{
    GLCD_DrawCircle(x,y,8,color);
    GLCD_DrawLine((x-15),(y),(x+15),y,color);
    GLCD_DrawLine(x,(y-15),x,(y+15),color);
     
}

//Draws the blast 
//X and Y is the center of the circle
//Size for normal is 0 and bigger is a greater specified number
void drawBlast(int16 x,int16 y,int16 size,int16 starArray[])
{
   
    int16 i=0;
    for(i=0;i<(25+size);i++)
    {
     GLCD_DrawCircle(x,y,i,GLCD_BLUE);
    }
     for(i=0;i<(25+size);i++)
    {
     GLCD_DrawCircle(x,y,i,GLCD_BLACK);
    }
    
    drawScope(x,y,GLCD_YELLOW);
    drawStars(starArray);
}


int main(void)
{
    int16 stars [300]={0}; 
    int16 i=0;
    int16 x=62;
    int16 y=62;
    for(i=0;i<300;i++)
    {
        stars[i]=rand()%132;
    }
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    GLCD_Start();
    GLCD_Clear(GLCD_BLACK);
    Backlight_Write(1);
    drawStars(stars);
    drawScope(62,62,GLCD_YELLOW);
    //drawBlast(62,62,0,stars);

    int16 counter=0;
    while(1)
    {
//        if (counter % 100000 ==0)
//        {
//            drawBlast(62,62,0,stars);
//        }
        
        
        // If A pressed, move up
     while (A_Button_Read()==0)
    {

        drawScope(x,y,GLCD_BLACK);
        drawStars(stars); 
        x--;
        drawScope(x,y,GLCD_YELLOW);
    }
    
    // If B pressed, move right
    while (B_Button_Read()==0) 
    {
        drawScope(x,y,GLCD_BLACK);
        drawStars(stars); 
        y++;
        drawScope(x,y,GLCD_YELLOW);
    }
    
    // If C pressed, move down
    while (C_Button_Read()==0) 
    {
        drawScope(x,y,GLCD_BLACK);
        drawStars(stars); 
        x++;
        drawScope(x,y,GLCD_YELLOW);
    }
    
    // If D pressed, move left
    while (D_Button_Read()==0) 
    {
        drawScope(x,y,GLCD_BLACK);
        drawStars(stars); 
        y--;
        drawScope(x,y,GLCD_YELLOW);
    }
        

    
    // If joystick center pushed, turn on Blue and Red LEDs and draw lines in White
    if (Joystick_button_Read()==0) 
    {
           drawBlast(x,y,0,stars);  
    }   
            
            
     counter++;
    }

}

/* [] END OF FILE */
