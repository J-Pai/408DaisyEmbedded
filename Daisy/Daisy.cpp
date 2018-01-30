#include "Arduino.h"
#include "Daisy.h"

/**
 * PUBLIC FUNCTIONS
 */
/**
 * Note md is a private variable that represents the motor shield object.
 * Documentation for functions associated with the object DualVNH5019MotorShield
 * can be found 
 */
Daisy::Daisy() {
    Serial.begin(115200);
    #if ENABLE_DEBUG == 1
    Serial.println("Daisy's Debugging has been ENABLED!");
    #else
    Serial.println("Daisy's Debugging has been DISABLED!");
    #endif
    md.init();
}

/**
 * Speed should be between 0 and 400
 */
void Daisy::forward(int speed) {
    if (!validSpeed(speed)) {
        return;
    }
    DEBUGLN("Moving forward at %d speed", speed)
    motorL(speed);
    motorR(speed);
}

/**
 * Speed should be between 0 and 400
 */
void Daisy::backward(int speed) {
    if (!validSpeed(speed)) {
        return;
    }
    DEBUGLN("Moving backward at %d speed", speed)
    motorL(-speed);
    motorR(-speed);
}

/**
 * Halts Daisey T.T
 */
void Daisy::halt() {
    DEBUGLN("Daisey is stopping.")
    motorL(0);
    motorR(0);
}

/**
 * Specify direction clockwise (CW) or counter-clockwise (CCW).
 * Speed should be between 0 and 400.
 * Time is in milliseconds.
 */
void Daisy::turn(Dir dir, int speed, unsigned long time) {
    if (!validSpeed(speed)) {
        return;
    }
    int left = 1;
    int right = 1;
    if (dir == CW) {
        DEBUGLN("Daisey is turning CW at %d speed for %lu time", speed, time)
        left = 1;
        right = -1;
    } else {
        DEBUGLN("Daisey is turning CCW at %d speed for %lu time", speed, time)
        left = -1;
        right = 1;
    }
    motorL(speed * left);
    motorR(speed * right);
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
}

void Daisy::motorR(int speed) {
}

bool Daisy::validSpeed(int speed) {
    if (speed >= 0 && speed <= 400) {
        DEBUGLN("Speed of %d is valid", speed)
        return true;
    } else {
        DEBUGLN("Speed of %d is invalid", speed)
        return false;
    }
}

