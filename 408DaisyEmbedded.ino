#include <Daisy.h>

Daisy daisy;

void setup() {
  // put your setup code here, to run once:
  daisy = Daisy(3,5);
}

void loop() {
  // put your main code here, to run repeatedly:

    if(daisy.leftPingIN() <= 5 || daisy.rightPingIN() <= 5){
      daisy.halt();
    } else {
      daisy.forward(100);
    }
}
