/* ========================================
 Quinton Cline
Motor Controll
 * ========================================
*/
#include "project.h"
#include <stdio.h>



///////////////////////
//// DC Motor  ///////
//////////////////////
//DC Motor Constants
#define motorReverse 0b00000100
#define motorForward 0b00001000


//DC motor Variables  
int ADC=0;
int BDC=1; 
int direction=0; //Stors the current diretion
int reverseDirection=0; //

void dcMotorControll()
{
  //Changes the direction forward ->reverse
    if (reverseDirection == 0){
        direction = motorReverse;
        //Writes the bytes to the 
        SPIM_WriteTxData(motorReverse);
        //Change the variable for direction 
        reverseDirection = 1;
    }
    //Changes reverse->forward
    else{
        direction = motorForward;
        //Writes the bytes to 
        SPIM_WriteTxData(motorForward);
        //Change the variable for direction
        reverseDirection = 0;
    } 
    //Loop tell transmit is done
    while(!(SPIM_ReadTxStatus() & SPIM_STS_BYTE_COMPLETE)){}
    
    Latch_Write(0); //rising edge to the transfer latch
    Latch_Write(1); //Reset the latch 
    Enable_Write(0); //write low to enable

}

//////////////////////
//// STEPPER     ////
////////////////////
//Stepper Motor wire constants
#define Blue    0b10000000
#define Pink    0b00000001
#define Yellow  0b00100000
#define Orange  0b01000000
//The stepper order 
const int steps[4] = {Blue,Pink,Yellow,Orange};
//Variable for the current step 
int step=0; 

//This is the function that is called by the intterupt when the button is pushed
void stepperMotorControl(){
    
    //Set enable to high
    Enable_Write(1); 
    //Send step to SPI to be written to the motor
    SPIM_WriteTxData(steps[step] | direction);
    //Remain in while loop until the data is done being transmitted
    while(!(SPIM_ReadTxStatus() & SPIM_STS_BYTE_COMPLETE)){}
    //rising edge to the transfer latch
    Latch_Write(0); 
    Latch_Write(1);
    Enable_Write(0); //write low to enable
   
}


    
int main(void)
{
    
    //Variables   
    int capPos=0; 
  
CyGlobalIntEnable; /* Enable global interrupts. */
    
    //Start stuff up 
    CapSense_Start(); 
     LED_PWM_Start();
    DC_PWM_Start(); 
    SERVO_PWM_Start();
    SPIM_Start(); 
    DirectionInt_Start();
    Stepper_Timer_Start(); 
    StepperInterrupt_Start();
    StepperInterrupt_ClearPending(); 
    CapSense_InitializeAllBaselines();

    SERVO_PWM_WriteCompare(700); // Start the servo on the left
        while(1)
        {
            //Checks to see if it is busy
             if(CapSense_NOT_BUSY==CapSense_IsBusy())
            {
                //scan all widgets
                CapSense_ScanAllWidgets();
                CapSense_ProcessAllWidgets();
                //If it is touched go into if statement
                if(CapSense_GetCentroidPos(CapSense_LINEARSLIDER0_WDGT_ID) != CapSense_SLIDER_NO_TOUCH )
                {
                    //Grab the calue 
                    capPos=CapSense_GetCentroidPos(CapSense_LINEARSLIDER0_WDGT_ID); 
                    //Set LED PWM 
                    LED_PWM_WriteCompare(capPos );
                    //Set DC PWM 
                    DC_PWM_WriteCompare(capPos);
                    //Re-map servo and write servo pwm 
                   int servoPos = ((1600*(capPos))/(100)) + 700;
                    SERVO_PWM_WriteCompare(servoPos );
                    //Re-map stepper and write to stepper timer
                   int stepperScaled=12000-(capPos*100); 
                    Stepper_Timer_WritePeriod(stepperScaled); 
                }
                else
                {
                 capPos=0;    
                }
                CapSense_ScanAllWidgets();
            }
            
            
            
            
     
        }
}

