// ---------------------------------------------------------------------------------
// LM75 Temperature Sensor Utilities
// ---------------------------------------------------------------------------------
// These library routines allow you to read temperature values from an LM75
// tempreature sensor using I2C.
// ---------------------------------------------------------------------------------
// Source:  Own work (David Slik, https://github.com/dslik)
//          Routines based on datasheet: https://www.ti.com/lit/ds/symlink/tmp75.pdf
// License: CERN-OHL-S v2 (https://github.com/dslik/protonema/blob/main/license.md)
// ---------------------------------------------------------------------------------
// Standard Library Includes
#include <stdio.h>
#include <stdlib.h>

// Target Includes
#include "hardware/i2c.h"
#include "lm75.h"

// Initialize the temperature sensor
void lm75_init(uint8_t address)
{
    int ret;

    // Assume just powered on, so give a few ms to stablize
    sleep_ms(10);

    // Initialize the i2c subsystem
    i2c_init(i2c_default, 100 * 1000);
    gpio_set_function(I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA_PIN);
    gpio_pull_up(I2C_SCL_PIN);

    uint8_t txdata[2];
    
    // Set the configuration register
    txdata[0] = 0x01;
    txdata[1] = 0x60;
    ret = i2c_write_blocking (i2c_default, address, txdata, 2, false);

    // Set the pointer register
    txdata[0] = 0x00;
    ret = i2c_write_blocking (i2c_default, address, txdata, 1, false);
}

// Convert the digital temperature output into degrees C
// See section 7.3.1 of https://www.ti.com/lit/ds/symlink/tmp75.pdf
float lm75_reg_to_degrees(uint8_t low, uint8_t high)
{
    uint16_t  temp = 0;
    float     convertedTemp = 0.0;

    temp = ((low << 8) | high) >> 4;
    convertedTemp = (float) temp * 0.0625f; 

    return(convertedTemp);
}

// Read the temperature value and convert it into degrees
float lm75_read(uint8_t address)
{
    int ret;
    uint8_t rxdata[2];

    ret = i2c_read_blocking(i2c_default, address, (char*) &rxdata, 2, false);

    return(lm75_reg_to_degrees(rxdata[0], rxdata[1]));
}
