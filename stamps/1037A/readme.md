# LCD Display Stamp

An SPI-attached st7789 LCD module

Initial features include:
- 240x240 pixel colour LCD
- Unicode font IC (GT20L16P1Y)

# Build Journal

_Feel free to ask questions by opening an issue!_

## 2023-09-02

Finally figured out why there was some data corruption, and fixed it.

The software now lets you display strings with different scaling and different foreground and background colours:

![image](https://github.com/dslik/protonema/assets/5757591/d4798480-8aaf-4485-833a-ca12fb5a2925)

The source code is now checked in under [1037-9101](./1037-9101).

Next steps are to implement UTF-8 handling, and write some additional drawing routines.

## 2023-08-06

After much struggle, I have characters being displayed on the screen! These are being read via SPI from the font IC, which turned out to be pretty challenging since it has shared I/O lines with the SPI display which is being driven by the Pi Pico PIO. So I had to figure out a reliable way to switch between pins being driven by the PIO (to write to the display) and being directly bit-banged (to read from the font IC).

Here's the current output:

![image](https://github.com/dslik/protonema/assets/5757591/6f736e88-d2f7-4584-aa38-c520da5b28d8)

There are a few unexpected pixels set for some characters on the top-left (always in bit positions 1, 2, 3, 4) for which I have not yet been able to track down the cause. It's not consistent either, note the four extra pixels set on the first and third "l", but only three extra pixels set on the second "l". And this changes from run to run.

After getting this far, I'm tempted to create my own font IC using an SPI EEPROM. That way I can have different typeface sizes, and do anti-aliasing using alpha channels.

Next steps are to figure out the character corruption problem, and clean up the software routines. Then I can upload an early version of the test software.

## 2023-07-25

The parts for the latest revision of this stamp have been sitting on my bench for too long, so it was time to assemble it and start working on the enhancements to the software:

![image](https://github.com/dslik/protonema/assets/5757591/fc11dbb1-885f-42f4-8c07-aecac35c140e)

The spacer on the top right goes on top of the LCD module, with both being screwed to the front panel (top left). This is then mounted to the stamp board using standoffs.

![image](https://github.com/dslik/protonema/assets/5757591/348592f4-c34d-495d-9bee-022e43be5e7d)

Once assembled, I made good progress bit-banging reading data back from the font IC:

![image](https://github.com/dslik/protonema/assets/5757591/33d3d820-54aa-448a-9f4b-10f83a9796b2)

The yellow trace is chip select, red is the serial clock, blue is the serial data in, and green is the serial data out.

Under the hood, it's just a standard memory device, pre-programmed with font data:

https://github.com/dslik/protonema/assets/5757591/b46b6114-92f2-47eb-8311-5f25a8a3e7f1

As the read address is incremented (blue trace), the data read (green trace) slides across the screen, showing us that we're just reading from a linear address space.

Next steps will be writing some utility routines for reading in glyphs, and handling some of the bit order conversion required.

Once that is working, the next step is to write some string rendering routines for the LCD.
