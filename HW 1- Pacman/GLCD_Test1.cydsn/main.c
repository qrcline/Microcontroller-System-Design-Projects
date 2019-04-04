
// Test program to confirm operation of PSoC 4 Pioneer Board and Graphical LCD
// For documentation on the GLCD Library: Click on the Datasheets tab in the Workspace Explorer and open SF_ColorShield_v0_3.
//        API documentation is at the bottom of the Datasheet

#include <device.h>
#include <header01.h>
#include <math.h>



//This converts the polar cordinates given to the point to point used for the DrawLine
 void GLCD_Draw_Line_Polar(int centerX, int centerY, int angle, int length, int color)
{
    GLCD_DrawLine(centerX,centerY,(length*cos(((angle*M_PI))/180))+centerX,(length*sin(((angle*M_PI))/180))+centerY, color);
  
}

//Function that has loops to draw pacman
void PACMAN(int centerAngle)
{
    int16 count1;
    int16 count2;
    int16 count3;
    //Draws the original yellow circle
     for( count1=0; count1<360;count1++)
    {
         GLCD_Draw_Line_Polar(CENTER, CENTER,count1 , 50,  GLCD_YELLOW);   //Thins draws the original yellow circle
    }
    
    while(1)
    {
        //Draws black mouth open
    for(count2=centerAngle;count2<=centerAngle+30;count2++)
    {
         GLCD_Draw_Line_Polar(CENTER, CENTER,-count2 , 50,  GLCD_BLACK);  //Draws the black mouth
         GLCD_Draw_Line_Polar(CENTER, CENTER,count2 , 50,  GLCD_BLACK);  //Draws the black mouth
    }
    //Draws mouth closed by drawing yellow lines
     for( count3=centerAngle+30;count3>=centerAngle;count3--)
    {
         GLCD_Draw_Line_Polar(CENTER, CENTER,-count3 , 50,  GLCD_YELLOW);
         GLCD_Draw_Line_Polar(CENTER, CENTER,count3 , 50,  GLCD_YELLOW);
    }
    }
    
}

int main()
{
    int16 i;       // counter variable -- int16 will take up less room than int32
    int16 x = CENTER;  // x and y coordinates for center of circle--- This is defined in the header file
    int16 y = 62;

	
	// Initialize LCD
    GLCD_Start();  
    Backlight_Write(1);       // turn on backlight
    
    LED_Blue_Write(1); LED_Green_Write(1); LED_Red_Write(1); // turn off all LEDs (1 means off)
 
    
    // clear LCD to crimson color
    GLCD_Clear(GLCD_BLACK);
    //Call pacman function
     PACMAN(0);
     //PACMAN(90);
     //PACMAN(180);
     //PACMAN(270);
    
    
    
    
    
   
    
    
    
    
    
    
     
        
	
}

