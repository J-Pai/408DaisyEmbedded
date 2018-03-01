#include <Daisy.h>

#define THRESHOLD 5L

Daisy daisy;

void setup() {
  // put your setup code here, to run once:
  daisy = Daisy(3,5,11);
  // PRINTLN("Daisy initialized!");
}

void loop() {
  int inByte = ' ';
  unsigned long leftPing = daisy.leftPingIN();
  unsigned long rightPing = daisy.rightPingIN();
  unsigned long middlePing = daisy.middlePingIN();

  while (!Serial.available()) {
  }
  inByte = Serial.read(); // read the incoming data
  Serial.print("INPUT: ");
  Serial.println(inByte); // send the data back in a new line so that it is not all one long line


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
