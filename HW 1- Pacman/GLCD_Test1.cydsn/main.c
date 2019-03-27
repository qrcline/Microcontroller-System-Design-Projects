
// Test program to confirm operation of PSoC 4 Pioneer Board and Graphical LCD
// For documentation on the GLCD Library: Click on the Datasheets tab in the Workspace Explorer and open SF_ColorShield_v0_3.
//        API documentation is at the bottom of the Datasheet

#include <device.h>
#include <header01.h>
#include <math.h>


void pretty_lines(int color){
    // make some decorations around the edges by drawing lines
    int i;
    for (i = 0; i < 126; i+=5){
        GLCD_DrawLine(2+i,2,126,2+i, color);
        GLCD_DrawLine(126-i,126,2,126-i, color);
    }
}

 void GLCD_Draw_Line_Polar(int centerX, int centerY, int angle, int length, int color)
{
    GLCD_DrawLine(centerX,centerY,(length*cos(((angle*M_PI))/180))+centerX,(length*sin(((angle*M_PI))/180))+centerY, color);
  
}

int main()
{
    int16 i;       // counter variable -- int16 will take up less room than int32
    int16 x = CENTER;  // x and y coordinates for center of circle--- This is defined in the header file
    int16 y = 62;
    int16 count1;
    int16 count2;
    int16 count3;
	
	// Initialize LCD
    GLCD_Start();  
    Backlight_Write(1);       // turn on backlight
    
    LED_Blue_Write(1); LED_Green_Write(1); LED_Red_Write(1); // turn off all LEDs (1 means off)
 
    
    // clear LCD to crimson color
    GLCD_Clear(GLCD_CRIMSON);
        
    // Draw a filled circle in maroon by drawing a series of circles of increasing radius 
    for (i = 50; i<52; i++) {
        GLCD_DrawCircle (x,y,i, GLCD_MAROON);
    }
    
     for( count1=0; count1<360;count1++)
    {
         GLCD_Draw_Line_Polar(CENTER, CENTER,count1 , 50,  GLCD_YELLOW);   //Thins draws the original yellow circle
    }
    while(1)
    {
   
    for(count2=0;count2<=30;count2++)
    {
         GLCD_Draw_Line_Polar(CENTER, CENTER,-count2 , 50,  GLCD_BLACK);  //Draws the black mouth
         GLCD_Draw_Line_Polar(CENTER, CENTER,count2 , 50,  GLCD_BLACK);  //Draws the black mouth
    }
     for( count3=30;count3>=0;count3--)
    {
         GLCD_Draw_Line_Polar(CENTER, CENTER,-count3 , 50,  GLCD_YELLOW);
         GLCD_Draw_Line_Polar(CENTER, CENTER,count3 , 50,  GLCD_YELLOW);
    }
    }
    
   
    
    
    
    
    
    
     
        
	
}

