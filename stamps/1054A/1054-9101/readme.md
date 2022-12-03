## Overview

Sample program for the 1054A MIDI Input stamp

## Build Instructions

1. Set up the Pi Pico example programs and build system
2. Successfully build and deploy the "blink" example via SWD to ensure your enviroment is working
3. Check out this project
4. Create a "build" directory
5. Inside the build directory, run "cmake ../"
6. Make and install the built "1054A.elf" executable.

From inside the build directory, use the following command to make and load the program via SWD:

``make;openocd -f interface/raspberrypi-swd.cfg -f target/rp2040.cfg -c "program 1054A.elf verify reset exit"``

## Test Instructions

When wired up correctly, the module will listen for MIDI notes, and if a 1068A Intelligent Display stamp is also connected, show the MIDI note on the display. If a 1053A MIDI Output stamp is connected, notes transposed up by one octive will be sent out the MIDI output.