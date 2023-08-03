# USB-C Power Supply

A USB-C 5V and 3.3V power supply stamp, with over-current protection.

# Build Journal

_Feel free to ask questions by opening an issue!_

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
