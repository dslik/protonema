## Overview

Sample program for the 1031A Pi Pico stamp

## Build Instructions

1. Set up the Pi Pico example programs and build system
2. Check out this project
3. Create a "build" directory
4. Inside the build directory, run "cmake ../"
5. Make and install the built "1031A.elf" executable.

From inside the build directory, use the following command to make and load the program via SWD:

``make;openocd -f interface/raspberrypi-swd.cfg -f target/rp2040.cfg -c "program 1031A.elf verify reset exit"``

## Test Instructions

When programmed successfully, the on-board LED will blink.
