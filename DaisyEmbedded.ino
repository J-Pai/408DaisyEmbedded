#include <Daisy.h>

#define THRESHOLD 5L

Daisy daisy;
int prevMoveByte = 0;
int prevParam = 0;

void setup() {
  daisy = Daisy(3,5,11);
}

void loop() {

  
  while (!Serial.available()) {
  }
  
  int inByte = Serial.read();
  if (inByte < 200 && inByte != prevMoveByte) {
    switch (inByte) {
      case 0: daisy.halt(); break;
      case 1: daisy.forward(100); break;
      case 2: daisy.turn(CW,100); break;
      case 3: daisy.turn(CCW,100); break;
      case 4: daisy.backward(100); break;
      default: daisy.halt(); break;
    }
    
    if (inByte >= 0) {
      PRINTLN("InputByte: %d, PrevByte: %d", inByte, prevByte);
    }
    prevMoveyte;
  } else {
    switch(inByte) {
      case 253: PRINTLN("LEFT_DIST: %d", daisy.leftPingIN()); break;
      case 254: PRINTLN("RIGHT_DIST: %d", daisy.rightPingIN()); break;
      case 255: PRINTLN("MID_DIST: %d", daisy.middlePingIN()); break;
      default: break;
    }
    if (inByte >= 0) {
      PRINTLN("InputByte: %d, PrevByte: %d", inByte, prevByte);
    }
  }
  
  delay(100);
}
