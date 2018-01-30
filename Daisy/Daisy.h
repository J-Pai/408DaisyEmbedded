#ifndef Daisey_h
#define Daisey_h

#include "Arduino.h"
#include "DualVNH5019MotorShield.h"

#define LMOTOR_OFF 0
#define RMOTOR_OFF 0
#define EN_DEBUG 1

#if ENABLE_DEBUG == 1
#define DEBUG(args...) Serial.print(args);
#define DEBUGLN(args...) Serial.println(args);
#else
#define DEBUG(args...)
#define DEBUGLN(args...)
#endif

enum Dir {CW, CCW};

class Daisy {
  public:
    Daisy();
    void forward(int speed);
    void backward(int speed);
    void halt();
    void turn(Dir dir, int speed, unsigned long time);
  private:
    DualVNH5019MotorShield md;
    void stopIfFault();
    void motorL(int speed);
    void motorR(int speed);
    bool validSpeed(int speed);
};

#endif
