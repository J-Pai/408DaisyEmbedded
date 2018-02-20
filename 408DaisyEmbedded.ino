#include <Daisy.h>

#define THRESHOLD 5L

Daisy daisy;

void setup() {
  // put your setup code here, to run once:
  daisy = Daisy(3,5,11);
 // PRINTLN("Daisy initialized!");
}

void loop() {

  unsigned long leftPing = daisy.leftPingIN();
  unsigned long rightPing = daisy.rightPingIN();
  unsigned long middlePing = daisy.middlePingIN();
 
  if(middlePing <= THRESHOLD){ // if center ping see obstacle and others dont then Stop
    daisy.halt();
  }
  else if(leftPing <= THRESHOLD && rightPing <= THRESHOLD){ // if both sides have obstacles in front of them turn until 
    daisy.turn(CW,100);
  }
  else if(leftPing <= THRESHOLD && rightPing >= THRESHOLD){ // avoid obstacle on the left and turn 
    daisy.turn(CW,100);
  }
  else if(rightPing <= THRESHOLD && leftPing >= THRESHOLD){ // avoid obstacle on the right and turn 
    daisy.turn(CCW,100);
  }
  else{
    daisy.forward(100);
  }
  
    
}
