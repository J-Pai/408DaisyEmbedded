#include <Daisy.h>

#define THRESHOLD 5L

Daisy daisy;

void setup() {
  daisy = Daisy(3,5,11);
}

void loop() {
  int inByte = ' ';
  
  /*
  unsigned long leftPing = daisy.leftPingIN();
  unsigned long rightPing = daisy.rightPingIN();
  unsigned long middlePing = daisy.middlePingIN();
  */
  
  while (!Serial.available()) {
  }
  inByte = Serial.read();
  Serial.print("INPUT: ");
  Serial.println(inByte);


  switch (inByte) {
    case 0: daisy.halt(); break;
    case 1: daisy.forward(100); break;
    case 2: daisy.turn(CW,100); break;
    case 3: daisy.turn(CCW,100); break;
    case 4: daisy.backward(100); break;
    default: daisy.halt(); break;

  }


  delay(100);
}
