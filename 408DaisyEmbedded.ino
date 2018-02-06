#include <Daisy.h>

#define THRESHOLD 5

Daisy daisy;

void setup() {
  // put your setup code here, to run once:
  Serial.println("Setting up Daisy");
  daisy = Daisy(3,5);
}

void loop() {
  // put your main code here, to run repeatedly:

    if(daisy.leftPingIN() <= THRESHOLD || daisy.rightPingIN() <= THRESHOLD){
      daisy.halt();
    } else {
      daisy.forward(100);
    }
}
