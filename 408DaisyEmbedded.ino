#include <Daisy.h>


#define THRESHOLD 5L

Daisy daisy;

void setup() {
  // put your setup code here, to run once:
  daisy = Daisy();

  unsigned long leftPing = daisy.leftPingIN();
  unsigned long rightPing = daisy.rightPingIN();
  unsigned long middlePing = daisy.middlePingIN();
  
}

void loop() {
  
  if(middlePing <= THRESHOLD && (leftPing > THRESHOLD && rightPing > THRESHOLD)){ // if center ping see obstacle and others dont then Stop
    halt();
      }
  else if(leftPing <= THRESHOLD && rightPing <= THRESHOLD){ // if both sides have obstacles in front of them turn until 
    turn(CW,100);
      }
  else if(leftPing <= THRESHOLD && rightPing >= THRESHOLD){ // avoid obstacle on the left and turn 
    turn(CW,50);
      }
  else if(rightPing <= THRESHOLD && leftPing >= THRESHOLD){ // avoid obstacle on the right and turn 
    turn(CCW,50);
      }
  else{
    daisy.forward(100);
    }
    
}
