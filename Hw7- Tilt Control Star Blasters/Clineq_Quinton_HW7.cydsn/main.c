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
#include "stdio.h"



//Function that is used to draw the stars from the array
void drawStars(int16 starArray[])
{
    CyGlobalIntDisable; 
   int16 i=0;
    for(i=0;i<300;i++)
    {
        GLCD_DrawLine(starArray[i],starArray[i+1],starArray[i],starArray[i+1],GLCD_WHITE);
    }
    CyGlobalIntEnable; 
}

//Draws the scope 
//X and Y is the center of the circle
//Color is the color of the scope
void  drawScope(int16 x,int16 y,int32 color)
{
    CyGlobalIntDisable; 
    GLCD_DrawCircle(x,y,8,color);
    GLCD_DrawLine((x-15),(y),(x+15),y,color);
    GLCD_DrawLine(x,(y-15),x,(y+15),color);
    CyGlobalIntEnable; 
     
}

//Draws the blast 
//X and Y is the center of the circle
//Size for normal is 0 and bigger is a greater specified number
void drawBlast(int16 x,int16 y,int16 size,int32 color,int16 starArray[])
{
   CyGlobalIntDisable; 
    //Draws the disired color blast
    int16 i=0;
    for(i=0;i<(40+size);i++)
    {
     GLCD_DrawCircle(x,y,i,color);
    }
    //Draws over in black
     for(i=0;i<(40+size);i++)
    {
     GLCD_DrawCircle(x,y,i,GLCD_BLACK);
    }
    //Put stars back
       drawStars(starArray);
    //Put back the scope
    drawScope(x,y,GLCD_YELLOW);
    CyGlobalIntEnable; 
 
}

//Function to set the led color with r,g,b values
void ledSet(int16 r,int16 g, int16 b)
{
    R_LED_Write(r);
    G_LED_Write(g);
    B_LED_Write(b);
}

void WriteSensor(uint8 *WriteBuffer, int numvals)
{
    I2C_I2CMasterClearStatus(); 
    I2C_I2CMasterWriteBuf(0x53,WriteBuffer,numvals,I2C_I2C_WRITE_XFER_MODE);
    while(!(I2C_I2CMasterStatus()&I2C_I2C_MSTAT_WR_CMPLT));
   
}

void ReadSensor(uint8 *ReadBuffer, int numvals)  
{
  I2C_I2CMasterClearStatus(); 
I2C_I2CMasterReadBuf(0x53,ReadBuffer,numvals,I2C_I2C_READ_XFER_MODE);
while(!(I2C_I2CMasterStatus()&I2C_I2C_MSTAT_RD_CMPLT));
    
}
    int16 stars [300]={0}; 
    int16 twinkleStars=0;
    int16 i=0;
    int16 x=62;
    int16 y=62;
    int16 xOld=62;
    int16 yOld=62;
    uint32 counter=0;
    bool blasterReady=true;
    bool hyperblasterReady=true;
    
    //For accel setup
    uint8 PWR_CTL=0x2D; 
    uint8 DATA_FORMAT=0x31; 
    uint8 TAP_AXES=0x2A; 
    uint8 INT_ENABLE=0x2E;
    uint8 INT_MAP=0x2F;
    uint8 INT_SOURCE=0x30;
    uint8 DATAX0=0x32; 
    uint8 DATAX1=0x33;
    uint8 DATAY0=0x34; 
    uint8 DATAY1=0x35;
    uint8 DATAZ0=0x36; 
    uint8 DATAZ1=0x37;
    
    //For accel tap
    uint8 THRESH_TAP=0x1D;
    uint8 DUR=0x21;    
    uint8 Latent=0x22;
    uint8 Window=0x23;
    
    
    //Buffers for i2C
    uint8 ReadBuffer[10];
    uint8 WriteBuffer[10];
    
    //Variables for the strings for testing
    char stringX[10]; 
    char stringY[10]; 
    char stringZ[10]; 

int main(void)
{
    CyGlobalIntEnable;
    //Turn stuff on 
       Timer_Start(); 
       I2C_Start(); 
       Clock_1_Start(); 
     GLCD_Start(); 
     Backlight_Write(1);
    GLCD_Clear(GLCD_BLACK);

    //Draw the startup screen 
    drawStars(stars);
    drawScope(x,y,GLCD_YELLOW);
    ledSet(1,1,0); //Set to blue
 
    
   //Turns on the accel
    WriteBuffer[0] = PWR_CTL;
    WriteBuffer[1] = 0b00001000;
    WriteSensor(WriteBuffer,2); //Write two bytes of data
    
    //Set data format
    WriteBuffer[0] = DATA_FORMAT;
    WriteBuffer[1] = 0b00000011; 
    WriteSensor(WriteBuffer,2); //Write two bytes of data

    //Enable
    WriteBuffer[0] = INT_ENABLE;
    WriteBuffer[1] = 0b01110000;
    WriteSensor(WriteBuffer,2); //Write two bytes of data
    
    //map values
    WriteBuffer[0] = INT_MAP;
    WriteBuffer[1] = 0b00000000;
    WriteSensor(WriteBuffer,2); //Write two bytes of data
    

    //Set the tap threshold
     WriteBuffer[0] = THRESH_TAP;
    WriteBuffer[1] = 0xc0;
    WriteSensor(WriteBuffer,2); //Write two bytes of data
    
    //Sets the tap threshold 
    WriteBuffer[0] = TAP_AXES;
    WriteBuffer[1] = 0b00000111;
    WriteSensor(WriteBuffer,2); //Write two bytes of data
    
    //Sets the tap duration 
    WriteBuffer[0] = DUR;
    WriteBuffer[1] = 0x20;
    WriteSensor(WriteBuffer,2); //Write two bytes of data
    
    //Set the latency
    WriteBuffer[0] = Latent;
    WriteBuffer[1] = 0x20;
    WriteSensor(WriteBuffer,2); //Write two bytes of data
    
    //Setup window
    WriteBuffer[0] = Window;
    WriteBuffer[1] = 0x80;
    WriteSensor(WriteBuffer,2); //Write two bytes of data
    
    //Start interupts
    accData_Start(); 
    tapInterrupt_Start();
    accData_ClearPending(); 

    //Loads the array with x,y for the stars
    for(i=0;i<300;i++)
    {
        stars[i]=rand()%132;  
    }
    
   

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
   


    
 //Draws the stars
          drawStars(stars);
 CyGlobalIntEnable; /* Enable global interrupts. */
    while(1)
    {

    }

}

/* [] END OF FILE */
