#include <RASLib/inc/common.h>
#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>
#include <RASLib/inc/servo.h>
#include <RASLib/inc/linesensor.h>
//#include <stdio.h>
/*******************************************
Pin_F3 & Pin_F2 are used for heartbeat
Pins F2, F3, B3, C4, C5, C6, C7, D6 used for lineSensor
Pin_B0 = left seivo
Pin_B1 = right servo
*******************************************/

// Blink the LED to show we're on
tBoolean blink_on = true;

void blink(void) {
    // PF1 = RED, PF2 = BLUE, PF3 = GREEN
   // SetPin(PIN_B0, blink_on); //This is being used by the servo now
    SetPin(PIN_F1, blink_on);    
    blink_on = !blink_on;
}


// The 'main' function is the entry point of the program
int main(void) {

    // Initialize the servos
    tServo *left;
    tServo *right;
    left= InitializeServo(PIN_B0);
    right= InitializeServo(PIN_B1);
    // Fire these hush-puppies up
    SetServo(left,.4);
    SetServo(right,.6);
    
    // Initialize Line-sensor ports
    tLineSensor *lineSensor;
    lineSensor = InitializeGPIOLineSensor(PIN_F2, PIN_F3, PIN_B3, PIN_C4, PIN_C5, PIN_C6, PIN_C7,
PIN_D6);
    float array[8] = {0};
    SetPin(PIN_F1, false);  // start with red led off
 
    if(LineSensorReadArray(lineSensor, array)){
       CallEvery(blink, 0, 0.5);       // alternate check for successful read
    }
    
    while(1){
        
    }
    // Heart beat to make sure program is running 
//    CallEvery(blink, 0, 0.5);   // Random heart beat
}
