#include <Daisy.h>

#define THRESHOLD 5L
#define MOVE_TIMEOUT 1000.0F //Milliseconds

Daisy daisy;
int prevByte = 0;
int prevParam = 0;
float currTime = 0.0F;
float lastMoveCmd = 0.0F;
int newData = 0;

void setup() {
  daisy = Daisy(3,5,11);
}

void loop() {

  currTime = millis();

  while (!Serial.available() && currTime - lastMoveCmd < MOVE_TIMEOUT) {
    currTime = millis();
  }

  int inByte = 0;

  if (Serial.available()) {
    inByte = Serial.read();
    newData = true;
  }

  if (newData) {
    PRINTLN("InputByte: %d, PrevByte: %d", inByte, prevByte);
    newData = false;
  }

  if (inByte < 200 && inByte != prevByte ) {
    switch (inByte) {
      case 0: daisy.halt(); break;
      case 1: daisy.forward(100); break;
      case 2: daisy.turn(CW,100); break;
      case 3: daisy.turn(CCW,100); break;
      case 4: daisy.backward(100); break;
      default: daisy.halt(); break;
    }

    prevByte = inByte;
    lastMoveCmd = millis();
  } else {
    switch(inByte) {
      case 253: PRINTLN("LEFT_DIST: %d", daisy.leftPingIN()); break;
      case 254: PRINTLN("RIGHT_DIST: %d", daisy.rightPingIN()); break;
      case 255: PRINTLN("MID_DIST: %d", daisy.middlePingIN()); break;
      default: break;
    }

  }

  delay(100);
}
