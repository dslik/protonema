# USB-C Power Supply

A USB-C 5V and 3.3V power supply stamp, with over-current protection.

# Build Journal

_Feel free to ask questions by opening an issue!_

## 2023-08-26

The new PCBs arrived, and are ready to test:

![image](https://github.com/dslik/protonema/assets/5757591/09aaa341-b52e-4143-b082-3fd70e74b09a)

Here's what it looks like all assembled:

![image](https://github.com/dslik/protonema/assets/5757591/06b3544c-5bff-4384-bee2-8c8b604449d5)

When I manually trigger dead shorts to various parts of the power supply, here's what it looks like on the oscilloscope:

![image](https://github.com/dslik/protonema/assets/5757591/26852d25-74d5-4dfb-9a71-e4458e3c229e)

The left-most trace shows what happens when the 3V3 rail (purple trace) is shorted to ground. OCP is provided here by a LPW5209. This results in a small drop in the 5V rail.

The second left-most trace shows what happens when the 5V rail (yellow trace) is shorted to ground. OCP is provided here by a LPW5209. This results in a bit more noise on the 3V3 rail, but no drop in voltage.

The second right-most trace shows what happens when the output of the 3V3 LDO is shorted to ground. This is before the LPW5209, so the LDO's OCP kicks in. This results in a much larger drop in the 5V rail voltage, down to 4V.

Finally, the right-most trace shows what happens when the 5V input to the 3V3 LDO is shorted to ground. This results in the PTC going into thermal disconnect.

Here's a trace of the input USB voltage and current when the 5V and 3V3 rails are shorted to ground:

![image](https://github.com/dslik/protonema/assets/5757591/2a1b6868-0922-494a-b956-6a285f3d4c59)

The OCP kicks in at 0.5 amps (as configured), and trys to restore power after a delay.

The trace on the left is the 5V rail being shorted to ground, and the trace on the right is the 3V3 rail being shorted to ground.

This is much better than before:

![image](https://github.com/dslik/protonema/assets/5757591/0d46269c-e03d-4e90-add2-f34d87ded33e)

The trace on the left is when the 3V3 LDO is shorted out, and we see that current draw jumps to 1 amp.

The trace on the right is when the 5V input to the 3V3 LDO is shorted to ground, and we see it spike to almost 3.6 amps before the PTC kicks in.

I think this design is good to go!

## 2023-08-07

Additional testing of the protection circuitry has demonstrated that while it works well for dead shorts, sustained overcurrents (e.g. 1A) will cause the voltage on the 5V rail to drop down to a steady-state 2V.

Here's a chart of the behaviour:

![image](https://github.com/dslik/protonema/assets/5757591/37e12876-3b95-4afc-b41c-3a27d70e69e1)

The current starts to drop as the PTC warms up, then at time 15 seconds, it transitions into a second state where current is limited to 500 mA.

Since I want something that completely cuts power to the supply rail during an over-current situation, I am going to investigate a few other options to add to the board. The LPW5209 was recommended, so I'm going to try using that, since I will only be switching 3.3V and 5V.

Here is revision 0.4, which will test separate OCP on each of the two output rails:

![image](https://github.com/dslik/protonema/assets/5757591/32500efa-d8a5-4d2d-bd16-98b148ab7c92)

This board will be included in the next PCB batch.

## 2023-08-02

The latest revision has arrived, and passes the power-up and 5V over-current tests:

![image](https://github.com/dslik/protonema/assets/5757591/a93a1b95-2cbc-4cef-8af1-b42eaed5637a)

When the 5V rail is shorted to ground, the PTC trips, and the red LED illuminates:

![image](https://github.com/dslik/protonema/assets/5757591/03633d1c-7f02-492d-a048-a12910beda90)

However, when the 3V3 rail is shorted to ground, the regulator goes into thermal overload, and the 5V PTC does not trip, even though it is rated at 500 ma and the regulator is rated at 800 ma.

This means I may need to have a second over-current protection block for the 3V3 rail.

Two other minor issues that will need to be fixed for the next revision:

- Missing circle for QC stamp on bottom
- R7 should be R6
