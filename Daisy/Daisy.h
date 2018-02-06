#ifndef Daisey_h
#define Daisey_h

// Following three lines enables DEBUG and PRINT macro operations. Make sure 
// to include Daisy_Print.h header file.
#define ENABLE_DEBUG 1 // Set to 1 to enable debugging print statements
#define ENABLE_C_PRINT 1 // Set to 1 to enable C like print statements

#include "Daisy_Print.h"
#include "Arduino.h"
#include "DualVNH5019MotorShield.h"
#include "Ping.h"

#define LMOTOR 1
#define RMOTOR 2

// Please keep compensation between 0 and 50
#define LMOTOR_COMP_FOR 0
#define LMOTOR_COMP_BACK 0
#define RMOTOR_COMP_FOR 0
#define RMOTOR_COMP_BACK 0

// Used to provide compensation for left and right ping cm and in measurements.
#define L_IN_MOD 0.0
#define L_CM_MOD 0.0

#define R_IN_MOD 0.0
#define R_CM_MOD 0.0

enum Dir {CW, CCW};

class Daisy {
  public:
    Daisy();
    Daisy(int leftPingPin, int rightPingPin);
    void forward(int speed);
    void backward(int speed);
    void halt();
    void turn(Dir dir, int speed);
    void turn(Dir dir, int speed, unsigned long time);
    double leftPingIN();
    double rightPingIN();
    double leftPingCM();
    double rightPingCM();
    int leftPingRAW();
    int rightPingRAW();
  private:
    DualVNH5019MotorShield md;
    Ping pingL;
    Ping pingR;

    void stopIfFault();
    void motorL(int speed);
    void motorR(int speed);
    bool validSpeed(int speed);
};

#endif
