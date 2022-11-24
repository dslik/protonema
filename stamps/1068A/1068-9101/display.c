// ---------------------------------------------------------------------------------
// OSRAM SCF5742 bit-bang driver for RP2040
// ---------------------------------------------------------------------------------
// These library routines allow you to control an OSRAM SC5742 intelligent serial
// display using four GPIO lines.
// 
// Notes:
// * Modify the pin constants in the header to correspond to the pins you wire up
// * The reset line is optional, and can be left unconnected
// * The data and clock lines can be shared with other devices that have a CS line
//   They are ignored by the SCF5742 while LOAD is left high.
// ---------------------------------------------------------------------------------
// Source:  Own work (David Slik, https://github.com/dslik)
// License: CERN-OHL-S v2 (https://github.com/dslik/protonema/blob/main/license.md)
// ---------------------------------------------------------------------------------
#include "display.h"

// Initialize I/O for talking to the display
void display_init(void)
{
    // Initialize output lines
    gpio_init(LOAD_PIN);
    gpio_set_dir(LOAD_PIN, GPIO_OUT);
    gpio_put(LOAD_PIN, 1);

    gpio_init(DATA_PIN);
    gpio_set_dir(DATA_PIN, GPIO_OUT);
    gpio_put(DATA_PIN, 1);

    gpio_init(CLK_PIN);
    gpio_set_dir(CLK_PIN, GPIO_OUT);
    gpio_put(CLK_PIN, 1);

    gpio_init(RESET_PIN);
    gpio_set_dir(RESET_PIN, GPIO_OUT);
    gpio_put(RESET_PIN, 1);

    // These are required to ensure that the timing is
    // consistent for all bits of first byte sent
    sleep_us(10);
    sleep_us(10);
}

// Reset the display
void display_reset(void)
{
    gpio_put(RESET_PIN, 0);
    sleep_us(100);
    gpio_put(RESET_PIN, 1);
    sleep_us(100);
}

// Send a single byte to the display
// This should not be called directly by program code.
void display_send_byte(uint8_t data)
{
    gpio_put(CLK_PIN, 0);
    gpio_put(LOAD_PIN, 0);
    gpio_put(DATA_PIN, (data & 0x01) != 0);
    sleep_us(1);
    gpio_put(CLK_PIN, 1);
    sleep_us(1);

    gpio_put(CLK_PIN, 0);
    gpio_put(DATA_PIN, (data & 0x02) != 0);
    sleep_us(1);
    gpio_put(CLK_PIN, 1);
    sleep_us(1);

    gpio_put(CLK_PIN, 0);
    gpio_put(DATA_PIN, (data & 0x04) != 0);
    sleep_us(1);
    gpio_put(CLK_PIN, 1);
    sleep_us(1);

    gpio_put(CLK_PIN, 0);
    gpio_put(DATA_PIN, (data & 0x08) != 0);
    sleep_us(1);
    gpio_put(CLK_PIN, 1);
    sleep_us(1);

    gpio_put(CLK_PIN, 0);
    gpio_put(DATA_PIN, (data & 0x10) != 0);
    sleep_us(1);
    gpio_put(CLK_PIN, 1);
    sleep_us(1);

    gpio_put(CLK_PIN, 0);
    gpio_put(DATA_PIN, (data & 0x20) != 0);
    sleep_us(1);
    gpio_put(CLK_PIN, 1);
    sleep_us(1);

    gpio_put(CLK_PIN, 0);
    gpio_put(DATA_PIN, (data & 0x40) != 0);
    sleep_us(1);
    gpio_put(CLK_PIN, 1);
    sleep_us(1);

    gpio_put(CLK_PIN, 0);
    gpio_put(DATA_PIN, (data & 0x80) != 0);
    sleep_us(1);
    gpio_put(CLK_PIN, 1);
    sleep_us(1);

    gpio_put(LOAD_PIN, 1);
    sleep_us(1);
}

// Set a specific digit to a bit pattern
void display_send_digit(uint8_t digit, uint64_t pattern)
{
    if(digit <= 3)
    {
        display_send_byte(0xA0 + digit);
        display_send_byte(pattern >> 0 & 0x1F);
        display_send_byte(pattern >> 8 & 0x1F);
        display_send_byte(pattern >> 16 & 0x1F);
        display_send_byte(pattern >> 24 & 0x1F);
        display_send_byte(pattern >> 32 & 0x1F);
        display_send_byte(pattern >> 40 & 0x1F);
        display_send_byte(pattern >> 48 & 0x1F);
    }
}

// Display a string of up to four characters
void display_send_string(char* string)
{
    if(string[0] != 0x00)
    {
        display_send_digit(0, characters[string[0]]);
        if(string[1] != 0x00)
        {
            display_send_digit(1, characters[string[1]]);
            if(string[2] != 0x00)
            {
                display_send_digit(2, characters[string[2]]);
                if(string[3] != 0x00)
                {
                    display_send_digit(3, characters[string[3]]);
                }
            }
        }
    }
}
