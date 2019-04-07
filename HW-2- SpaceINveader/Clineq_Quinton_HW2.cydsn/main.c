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
#include  "stdbool.h"

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
void drawBlast(int16 x,int16 y,int16 size,int32 color,int16 starArray[])
{
   
    int16 i=0;
    for(i=0;i<(40+size);i++)
    {
     GLCD_DrawCircle(x,y,i,color);
    }
     for(i=0;i<(40+size);i++)
    {
     GLCD_DrawCircle(x,y,i,GLCD_BLACK);
    }
       drawStars(starArray);
    drawScope(x,y,GLCD_YELLOW);
 
}
void ledSet(int16 r,int16 g, int16 b)
{
    R_LED_Write(r);
    G_LED_Write(g);
    B_LED_Write(b);
}


int main(void)
{
    int16 stars [300]={0}; 
    int16 i=0;
    int16 x=62;
    int16 y=62;
    uint32 counter=0;
    bool blasterReady=true;
    bool hyperblasterReady=true;
    
    
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
    drawScope(x,y,GLCD_YELLOW);
    ledSet(1,1,0); //Set to blue

    


    while(1)
    {
//        if (counter % 100000 ==0)
//        {
//            drawBlast(62,62,0,stars);
//        }
        if(counter==500000)
        {
            blasterReady=true;
            ledSet(1,0,1);//Set to green
        }
         if(counter==1000000)
        {
            hyperblasterReady=true;
            ledSet(1,1,0); //Set to blue
        }
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
    {      if(hyperblasterReady==true)
            {
                drawBlast(x,y,0,GLCD_BLUE,stars);  
                blasterReady=false;
                hyperblasterReady=false;
                counter=0;
                ledSet(0,1,1); //Set to red
            }
        
            else if(blasterReady==true)
            {
                drawBlast(x,y,0,GLCD_GREEN,stars);  
                blasterReady=false;
                counter=0;
                ledSet(0,1,1); //Set to red
            }
        
    }   
            
            
     counter++;
    }

}

/* [] END OF FILE */
