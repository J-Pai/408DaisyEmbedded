#include <Daisy.h>

#define THRESHOLD 5L
#define MOVE_TIMEOUT 1000.0F //Milliseconds

Daisy daisy;

float currTime = 0.0F;
float lastMoveCmd = 0.0F;

int serialReadInt() {
  int ret = 0;
  for (int i = 1; i >= 0; i--) {
    while (!Serial.available()) {
    }
    int b = Serial.read();
    ret |= b << (i * 8);
  }
  return ret;
}

void moveDaisy() {
  int leftSpeed = serialReadInt();
  int rightSpeed = serialReadInt();
  daisy.move(leftSpeed, rightSpeed);
  PRINT("(passed_data=[%d,%d])", leftSpeed, rightSpeed); 
}

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
  }

  if (inByte < 200) {
    PRINT("(move_code=%d)", inByte);
    switch (inByte) {
      case 0: daisy.halt(); break;
      case 1: daisy.forward(80); break;
      case 2: daisy.turn(CW,50); break;
      case 3: daisy.turn(CCW,50); break;
      case 4: daisy.backward(80); break;
      case 5: moveDaisy(); break;
      default: daisy.halt(); break;
    }
    PRINTLN("(END)");
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
