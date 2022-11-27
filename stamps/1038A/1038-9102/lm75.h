// ---------------------------------------------------------------------------------
// LM75 Temperature Sensor Utilities
// ---------------------------------------------------------------------------------
// These library routines allow you to read temperature values from an LM75
// tempreature sensor using I2C.
//
// This file contains prototypes and constants.
// 
// Notes:
// * Modify the pin constants to correspond to the pins you wire up
// * The temperature sensor will read 0.2 - 0.5 degrees low for the first
//   200-500 ms after being powered up.
// ---------------------------------------------------------------------------------
// Source:  Own work (David Slik, https://github.com/dslik)
//          Routines based on datasheet: https://www.ti.com/lit/ds/symlink/tmp75.pdf
// License: CERN-OHL-S v2 (https://github.com/dslik/protonema/blob/main/license.md)
// ---------------------------------------------------------------------------------
#pragma once
#ifndef LM75_H
#define LM75_H

#include <stdlib.h>
#include "pico/stdlib.h"

// Pin Constants
#define I2C_LM75_ADDR   0x77	// I2C address of the LM75
#define I2C_SDA_PIN     16		// GPIO line to use for SDA
#define I2C_SCL_PIN     17		// GPIO line to use for SCL

// Prototypes
void lm75_init(uint8_t address);
float lm75_read(uint8_t address);

#endif // LM75_H
