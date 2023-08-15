# ALU Trainer

A learning board for gaining a hands-on understanding of arithmetic-logic unit operation.

Initial features include:
- A and B inputs
- F output
- Control signals for ALU function selection
- Manual clock

Full assembly instructions will be uploaded soon.

# Build Journal

_Feel free to ask questions by opening an issue!_

## 2023-08-15

The updated boards came in, and are ready to assemble:

![image](https://github.com/dslik/protonema/assets/5757591/8ec55101-aabc-4297-9cef-391744230868)

Here's hoping that I didn't make any additional mistakes, and this project is ready for production.

Here's the board all assmebled, and ready for the ALU to be inserted into the PGA socket:

![image](https://github.com/dslik/protonema/assets/5757591/427d0c4e-95dc-45a7-827d-b29c4214f94e)

The LEDs aren't as bright as the previous revision, but they still are really bright. 

And, it's all working!

![image](https://github.com/dslik/protonema/assets/5757591/6403cbda-b191-4f45-af59-830f0d770a98)

I do have one change I will need to make when I put together a production run... I shouldn't have increased the pull-down resistors along with the LED resistors, so I'll have to change those back. And I need to add tooling holes in places I want, rather than the ones they choose.

But other than that, this project is done!

## 2023-08-02

The updated PCB with all the changes applied is done, and ready to order as part of the next PCB batch.

![image](https://github.com/dslik/protonema/assets/5757591/b78dfacc-2ac7-499c-ae0d-2d7fe5468e16)

Turned out that I didn't mess up the logic for the OSA/OSB displays, but rather I had the wrong part (NAND instead of NOR) that I messed up when copying and pasting the part number.

## 2023-07-31

The assembled PCBs have arrived! After soldering in the through-hole components, and testing everyting before pluggin in the ALU IC, almost everything is working.

![image](https://github.com/dslik/protonema/assets/5757591/bfd7f0f2-4fc1-4f6f-b871-feb2e840938d)

Here is the ALU trainer showing that 1 + 1 = 2.

Lots of little changes needed for the next revision of the PCB (V0.2):

- Increase resistance beyond 4.3K to further reduce LED brightness. These newer high-efficiency LEDs are so bright that the emitted light can bloom when viewed, and make it hard to tell which LED is lit.
- Rotate DIP switches by 180 degrees. This will make it easier to change the input values.
- Spread out A/B input LEDs and F output LEDs to match DIP switches. This will make it easier to read the values, and make them match up better.
- Move the switch LEDs for the right and left switches from the outside edge of the board to the inside position. This will make it so that your hand does not cover up the LEDs when throwing a switch.
- Fix OSA/OSB LED display logic
- Swap around S truth table to match the position of the switches.
- Increase size of LOGIC L4C381GC40 label
- Fix traces to "F" output LEDs
- Move ENA/ENB, OSA/OSB and S0/S1/S2 switches slightly apart so that the switches do not tilt
- Fix control signal voltage level

## 2023-07-24

The first draft of the ALU trainer PCB is now checked in. The PCBs have manufactured and shipped, so hopefully I will be able to assemble and test this design later this week.

![image](https://github.com/dslik/protonema/assets/5757591/0b3c2193-0d05-4bc8-82e5-b252ea84a457)

