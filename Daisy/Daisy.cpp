#include "Arduino.h"
#include "Daisy.h"

/**
 * PUBLIC FUNCTIONS
 */
Daisy::Daisy() {
  Serial.begin(115200);
  Serial.println("Initializing Daisy!");
#if ENABLE_DEBUG == 1
  Serial.println("Daisy's Debugging has been ENABLED!");
#else
  Serial.println("Daisy's Debugging has been DISABLED!");
#endif
  md.init();
}

Daisy::Daisy(int leftPingPin, int rightPingPin, int middlePingPin) : Daisy() {
  //Serial.begin(115200);
  Serial.println("Initializing Daisy with Ping pins:");
  Serial.print("    Left:");
  Serial.println(leftPingPin);
  Serial.print("    Right:");
  Serial.println(rightPingPin);
  pingL = NewPing(leftPingPin, leftPingPin);
  pingR = NewPing(rightPingPin, rightPingPin);
  pingM = NewPing(middlePingPin, middlePingPin);
}


void Daisy::forward(int speed) {
  if (!validSpeed(speed)) {
    return;
  }
  DEBUGLN("Moving forward at %d speed", speed)
    motorL(speed);
  motorR(speed);
}

void Daisy::backward(int speed) {
  if (!validSpeed(speed)) {
    return;
  }
  DEBUGLN("Moving backward at %d speed", speed)
    motorL(-speed);
  motorR(-speed);
}

void Daisy::halt() {
  DEBUGLN("Daisy is stopping.")
    md.setBrakes(400,400);
}

void Daisy::turn(Dir dir, int speed) {
  if (!validSpeed(speed)) {
    return;
  }
  int left = 1;
  int right = 1;
  if (dir == CW) {
    DEBUGLN("Daisy is turning CW at %d speed", speed)
      left = 1;
    right = -1;
  } else {
    DEBUGLN("Daisy is turning CCW at %d speed", speed)
      left = -1;
    right = 1;
  }
  motorL(speed * left);
  motorR(speed * right);
}

void Daisy::turn(Dir dir, int speed, unsigned long time) {
  if (!validSpeed(speed)) {
    return;
  }
  int left = 1;
  int right = 1;
  if (dir == CW) {
    DEBUGLN("Daisy is turning CW at %d speed for %lu time", speed, time)
      left = 1;
    right = -1;
  } else {
    DEBUGLN("Daisy is turning CCW at %d speed for %lu time", speed, time)
      left = -1;
    right = 1;
  }
  for (int i = 0; i < time; i++) {
    motorL(speed * left);
    motorR(speed * right);
    delay(1);
  }
  halt();
}

unsigned long Daisy::leftPingIN() {
  return pingL.ping_in();
}

unsigned long Daisy::rightPingIN() {
  return pingR.ping_in();
}

unsigned long Daisy::middlePingIN() {
  return pingM.ping_in();
}

unsigned long Daisy::leftPingCM() {
  return pingL.ping_cm();
}

unsigned long Daisy::rightPingCM() {
  return pingR.ping_cm();
}

unsigned long Daisy::middlePingCM() {
  return pingM.ping_cm();
}

unsigned long Daisy::leftPingRAW() {
  return pingL.ping_median();
}

unsigned long Daisy::rightPingRAW() {
  return pingR.ping_median();
}

unsigned long Daisy::middlePingRAW() {
  return pingM.ping_median();
}

/**
 * PRIVATE FUNCTIONS
 */
void Daisy::stopIfFault() {
  if (md.getM1Fault()) {
    Serial.println("M1 FAULT");
    while(1);
  }
  if (md.getM2Fault()) {
    Serial.println("M2 FAULT");
    while(1);
  }
}
void Daisy::motorL(int speed) {
  int modifiedSpeed = speed < 0 ?
    (speed - (LMOTOR_COMP_BACK)) :
    (speed + (LMOTOR_COMP_FOR));
#if LMOTOR == 1
  DEBUGLN("Left motor 1")
    md.setM1Speed(modifiedSpeed);
#elif LMOTOR == 2
  DEBUGLN("Left motor 2")
    md.setM2Speed(modifiedSpeed);
#else
  DEBUGLN("Unknown Left Motor Number %d," LMOTOR)
#endif
}

void Daisy::motorR(int speed) {
  int modifiedSpeed = speed < 0 ?
    (speed - (RMOTOR_COMP_BACK)) :
    (speed + (RMOTOR_COMP_FOR));
#if RMOTOR == 1
  DEBUGLN("Right motor 1")
    md.setM1Speed(modifiedSpeed);
#elif RMOTOR == 2
  DEBUGLN("Right motor 2")
    md.setM2Speed(modifiedSpeed);
#else
  DEBUGLN("Unknown Right Motor Number %d," RMOTOR)
#endif
}

bool Daisy::validSpeed(int speed) {
  if (speed >= 0 && speed <= 350) {
    DEBUGLN("Speed of %d is valid", speed)
      return true;
  } else {
    DEBUGLN("Speed of %d is invalid", speed)
      return false;
  }
}

