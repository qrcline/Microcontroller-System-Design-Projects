
// Test program to confirm operation of PSoC 4 Pioneer Board and Graphical LCD
// For documentation on the GLCD Library: Click on the Datasheets tab in the Workspace Explorer and open SF_ColorShield_v0_3.
//        API documentation is at the bottom of the Datasheet

#include <device.h>
#include <header01.h>

void pretty_lines(int color){
    // make some decorations around the edges by drawing lines
    int i;
    for (i = 0; i < 126; i+=5){
        GLCD_DrawLine(2+i,2,126,2+i, color);
        GLCD_DrawLine(126-i,126,2,126-i, color);
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
    GLCD_Clear(GLCD_CRIMSON);
        
    // Draw a filled circle in maroon by drawing a series of circles of increasing radius 
    for (i = 0; i<40; i++) {
        GLCD_DrawCircle (x,y,i, GLCD_MAROON);
    }
    
    // Draw a thick white circle by drawing several white circles of increasing radius
    for (i = 35; i< 38; i++) {
        GLCD_DrawCircle (x,y,i, GLCD_WHITE);
    }
    
    // Display the words "SPU" and "ECS"
    GLCD_PrintString("Quinton", x-20, y-27, GLCD_WHITE, GLCD_MAROON);
    GLCD_PrintString("Cline", x, y-20, GLCD_WHITE, GLCD_MAROON);
    
    // Draw some decorative lines in white
    pretty_lines(GLCD_WHITE);
    
    // endless loop - there is nothing to return to, so better to just loop forever
    while(1) {
    LED_Blue_Write(1); LED_Green_Write(1); LED_Red_Write(1);   // make sure all LEDs are off
    
    // If A pressed, turn on Green LED and draw lines in Green
     if (A_Read()==0) {
         LED_Green_Write(0);   
        pretty_lines(GLCD_GREEN);
        }
    
    // If B pressed, turn on Green and Red LEDs (Yellow) and draw lines in Yellow
    if (B_Read()==0) {
         LED_Green_Write(0);  
         LED_Red_Write(0);
        pretty_lines(GLCD_YELLOW);
        }
    
    // If C pressed, turn on Blue LED and draw lines in Blue
    if (C_Read()==0) {
         LED_Blue_Write(0); 
        pretty_lines(GLCD_BLUE);
        }
    
    // If D pressed, turn on Red LED and draw lines in Red
    if (D_Read()==0) {
         LED_Red_Write(0);  
        pretty_lines(GLCD_RED);        
        }
        

    
    // If joystick center pushed, turn on Blue and Red LEDs and draw lines in White
    if (Joy_Center_Read()==0) {
         LED_Blue_Write(0); 
         LED_Red_Write(0);
        LED_Green_Write(0);
        pretty_lines(GLCD_WHITE);
        }
       
    }
     
        
	
}

