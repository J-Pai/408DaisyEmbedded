# Daisy's Embedded Arduino Code
This repository contains the code and libraries necessary to execute basic movement operations for Daisey.

This repository contains the Arduino embedded code for control logic and also a library that is meant to act as a wrapper for the Dual VNH5019 Motor Shield functions.

The main embedded code is called 408DaisyEmbedded.ino. The target for this code is a basic Arduino UNO board.

The code for the library is in the directory called Daisy. This code is meant to interface with the Pololu Dual VNH5019 Motor Shield. The GIT repository for the library associated with the motor shield can be found [here](https://github.com/pololu/dual-vnh5019-motor-shield). This library also contains the functions necessary to obtain relative distance data from the two Ping sensors mounted on the front of Daisy. In order to use these functions, be sure to initialize Daisy with the second constructor and specify the pins used to connect the ping sensors to the Arduino.

Code for the ping sensors was pulled from the following resource found [here](https://playground.arduino.cc/Code/NewPing). This code was modified to include a default constructor.

When initializing left and right ping sensor pins, make sure to provide a value larger than or equal to 2 (pretty much, don't use pins 0 and 1 on the arduino).
With the motor shield connected, the only two pins that appear to be available are pins 3 and 5.

## Setup
Before building and executing the code, make sure to include the Daisey directory/library in the Arduino's base libraries folder. To do this, create a symbolic link between the Daisey directory and a directory in the Arduino libraries folder.

The command to do this can be found below (this only applies to Linux distributions, might be possible if you have git bash on windows):
```bash
ln -s ~/Arduino/DaisyEmbedded/Daisy/ ~/Arduino/libraries/
```
You should not need to use the Arduino IDE's import library function in order to import Daisy's library. The header file for Daisy's library has already been included.

Make sure to also import the library for the motor shield. Directions for how to do so can be found in the README of the motor shield's repository. The link to the repository can be found above.

NEW 02/28/2018: The folder that contains the source for the motor shield library has now been included. If you are using an older IDE, make sure to create a symbolic link in the Arduino libraries folder for the motor shield library. The directory/library name is called DualVNH5019MotorShield.

Command to create symbolic link for motor shield library is as follows:
```bash
ln -s ~/Arduino/DaisyEmbedded/DualVNH5019MotorShield ~/Arduino/libraries
```
