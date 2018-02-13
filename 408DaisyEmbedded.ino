#include <Daisy.h>

/** 
 * This is being used to compared against an
 * unsigned long. Make sure to add an L behind
 * the constant.
 */
#define THRESHOLD 5L

Daisy daisy;

void setup() {
    // put your setup code here, to run once:
    daisy = Daisy(3,5,11);
    PRINTLN("Daisy has been initialized!")
}



    
void loop(){

    unsigned long distR = daisy.rightPingIN();
    unsigned long distL = daisy.leftPingIN();
    
    if(distR <= 5){
      daisy.turn(CCW, 100);
    }
    if(distL <= 5){
      daisy.turn(CW, 100);
    }
    else{
       daisy.forward(100);
    }
}

