# LCD Display Stamp

An SPI-attached st7789 LCD module

Initial features include:
- 240x240 pixel colour LCD
- Unicode font IC (GT20L16P1Y)

# Build Journal

_Feel free to ask questions by opening an issue!_

## 2023-07-25

The parts for the latest revision of this stamp have been sitting on my bench for too long, so it was time to assemble it and start working on the ehnahcements to the software:

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
