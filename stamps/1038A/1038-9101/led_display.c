// ---------------------------------------------------------------------------------
// Four-digit seven-segment driver for RP2040
// ---------------------------------------------------------------------------------
// These library routines allow you to control a multiplexed seven segement display
// using GPIO lines.
// ---------------------------------------------------------------------------------
// Source:  Own work (David Slik, https://github.com/dslik)
// License: CERN-OHL-S v2 (https://github.com/dslik/protonema/blob/main/license.md)
// ---------------------------------------------------------------------------------
#include "led_display.h"

// Global variables
volatile uint8_t current_digit = 0;
volatile uint16_t current_display_value = 0;
volatile uint8_t current_display_decimal = 0;

// Seven-segment display lookup table
//                  Segment: A  B  C  D  E  F  G  .
const uint8_t seven_seg[] = {1, 1, 1, 1, 1, 1, 0, 0,  // 0
                             0, 1, 1, 0, 0, 0, 0, 0,  // 1
                             1, 1, 0, 1, 1, 0, 1, 0,  // 2
                             1, 1, 1, 1, 0, 0, 1, 0,  // 3
                             0, 1, 1, 0, 0, 1, 1, 0,  // 4
                             1, 0, 1, 1, 0, 1, 1, 0,  // 5
                             1, 0, 1, 1, 1, 1, 1, 0,  // 6
                             1, 1, 1, 0, 0, 0, 0, 0,  // 7
                             1, 1, 1, 1, 1, 1, 1, 0,  // 8
                             1, 1, 1, 1, 0, 1, 1, 0}; // 9

// Initialize global variables and GPIO pins to send data to the display
void led_display_init(void)
{
    int gpio = 0;

    // Initialize globals
    current_display_value = 0;
    current_digit = 0;
    current_display_decimal = 0;

    // Initialize GPIO as output
    while(gpio != 13)
    {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
        gpio_put(gpio, 0);

        gpio = gpio + 1;
    }
}

// Refresh the display. This function is called periodically by a timer.
// Each time it is called, it displays the value of the next digit.
bool led_display_refresh(struct repeating_timer *t)
{
    int gpio = 0;
    uint8_t value = 0;
    uint8_t display_digit = true;

    // Disable the digit
    gpio_put(DIG_BASE + current_digit, 0);

    // Process the next digit
    current_digit = current_digit + 1;

    if(current_digit == 1 && current_display_value < 10 && current_display_decimal < 1) display_digit = false; 
    if(current_digit == 2 && current_display_value < 100 && current_display_decimal < 2) display_digit = false; 
    if(current_digit == 3 && current_display_value < 1000 && current_display_decimal < 3) display_digit = false; 
    else if(current_digit > 3) current_digit = 0;

    if(current_digit == 0) value = (current_display_value) % 10;
    if(current_digit == 1) value = (current_display_value / 10) % 10;
    if(current_digit == 2) value = (current_display_value / 100) % 10;
    if(current_digit == 3) value = (current_display_value / 1000) % 10;

    if(value > 9) value = 0;

    // Set the segment values
    while(gpio != 8)
    {
        gpio_put(SEG_BASE + 7 - gpio, (((seven_seg[(value * 8) + gpio]) & display_digit) != 0));
        gpio = gpio + 1;
    }

    // Set the decimal place
    if(current_display_decimal > 0)
    {
        gpio_put(SEG_BASE, current_display_decimal == current_digit);
    }

    // Enable the digit
    gpio_put(DIG_BASE + current_digit, 1);

    return true;
}

// Set the current value of the display
void led_display_set_value(uint16_t value)
{
    current_display_value = value;
}

// Get the current value of the display
uint16_t led_display_get_value(void)
{
    return(current_display_value);
}

// Set the location of the decimal point for fixed point display
void led_display_set_dp(uint8_t value)
{
    if(value < 4)
    {
        current_display_decimal = value;
    }
}
