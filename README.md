# Daisy's Embedded Arduino Code
This repository contains the code and libraries necessary to execute basic movement operations for Daisey.

This repository contains the arduino embedded code for control logic and also a library that is meant to act as a wrapper for the Dual VNH5019 Motor Shield functions.

The main embedded code is called 408DaisyEmbedded.ino. The target for this code is a basic Arduino UNO board.

The code for the library is in the directory called Daisy. This code is meant to interface with the Pololu Dual VNH5019 Motor Shield. The GIT repository for the library associated with the motor shield can be found [here](https://github.com/pololu/dual-vnh5019-motor-shield).

## Setup
Before building and executing the code, make sure to include the Daisey directory/library in the Arduino's base libraries folder. To do this, create a symbolic link between the Daisey directory and a directory in the Arduino libraries folder. 

The command to do this can be found below (this only applies to Linux distributions):
```bash
ln -s ~/Arduino/408DaisyEmbedded/Daisy/ ~/Arduino/libraries/
```
From here, you will be able to import the library using the Sketch > Include Library function in the Arduino IDE.

Make sure to also import the library for the motor shield. Directions for how to do so can be found in the README of the motor shield's repository. The link to the repository can be found above.
