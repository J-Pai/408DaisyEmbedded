#ifndef Daisey_h
#define Daisey_h

// Following three lines enables DEBUG and PRINT macro operations. Make sure
// to include Daisy_Print.h header file.
#define ENABLE_DEBUG 0 // Set to 1 to enable debugging print statements
#define ENABLE_C_PRINT 1 // Set to 1 to enable C like print statements

#include "Daisy_Print.h"
#include "Arduino.h"
#include "DualVNH5019MotorShield.h"
#include "NewPing.h"

#define LMOTOR 1
#define RMOTOR 2

// Please keep compensation between 0 and 50
#define LMOTOR_COMP_FOR 0
#define LMOTOR_COMP_BACK 0
#define RMOTOR_COMP_FOR 0
#define RMOTOR_COMP_BACK 0

enum Dir {CW, CCW};

class Daisy {
  public:
    /**
     * Note md is a private variable that represents the motor shield object.
     * Documentation for functions associated with the object DualVNH5019MotorShield
     * can be found
     *
     * Another note: Serial port communication will not work until Daisy has been
     * initialized. No print statements (Serial, DEBUG, PRINT) will work if placed
     * before Daisy intialization code unless the user does Serial.begin manually.
     */
    Daisy();
    Daisy(int leftPingPin, int rightPingPin, int middlePingPin);

    /**
     * Speed should be between 0 and 350
     */
    void forward(int speed);

    /**
     * Speed should be between 0 and 350
     */
    void backward(int speed);

    /**
     * Halts Daisy T.T
     */
    void halt();

    /**
     * Specify direction clockwise (CW) or counter-clockwise (CCW).
     * Speed should be between 0 and 350.
     * Need to keep calling this function if you want to keep turning.
     */
    void turn(Dir dir, int speed);

    /**
     * Specify direction clockwise (CW) or counter-clockwise (CCW).
     * Speed should be between 0 and 350.
     * Time is in milliseconds.
     * Function will keep turning Daisy for duration time.
     */
    void turn(Dir dir, int speed, unsigned long time);

    /**
     * Following functions provide the interface necessary to obtain distance data
     * for the left and right ping sensors. User can obtain either inches, cm, or
     * raw data from the left and right ping sensors in order to determine distance.
     * Offsets/calibration can be set in the Daisy's header file.
     */
    unsigned long leftPingIN();
    unsigned long rightPingIN();
    unsigned long middlePingIN();
    unsigned long leftPingCM();
    unsigned long rightPingCM();
    unsigned long middlePingCM();
    unsigned long leftPingRAW();
    unsigned long rightPingRAW();
    unsigned long middlePingRAW();

    /*
     * Following are private functions. Do not attempt to call.
     */
  private:
    DualVNH5019MotorShield md;
    NewPing pingL;
    NewPing pingR;
    NewPing pingM;

    Daisy(int baudRate);
    void stopIfFault();
    void motorL(int speed);
    void motorR(int speed);
    bool validSpeed(int speed);
};

#endif
