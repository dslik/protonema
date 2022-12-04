// ---------------------------------------------------------------------------------
// 8x8 LED matrix driver for RP2040
// ---------------------------------------------------------------------------------
// These library routines allow you to control a multiplexed 8x8 LED matrix display
// using GPIO lines.
// ---------------------------------------------------------------------------------
// Source:  Own work (David Slik, https://github.com/dslik)
// License: CERN-OHL-S v2 (https://github.com/dslik/protonema/blob/main/license.md)
// ---------------------------------------------------------------------------------
#include "led_matrix.h"

// Global variables
volatile uint8_t matrix_frame_buffer[8];
volatile uint8_t matrix_current_row; 

// Initialize global variables and GPIO pins to send data to the display
void led_matrix_init(void)
{
    int gpio = 0;
    int row = 0;

    matrix_current_row = 0;

    // Initialize frame buffer
    while(row < 8)
    {
        matrix_frame_buffer[row] = 0;
        row = row + 1;
    }

    // Initialize GPIO for display rows as output
    gpio = ROW_BASE;
    while(gpio != ROW_BASE + 8)
    {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
        gpio_put(gpio, 0);

        gpio = gpio + 1;
    }

    // Initialize GPIO for display columns as output
    gpio = COL_BASE;
    while(gpio != COL_BASE + 8)
    {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
        gpio_put(gpio, 0);

        gpio = gpio + 1;
    }
}

// Refresh the display. This function is called periodically by a timer.
// Each time it is called, it displays the next row of the display
bool led_matrix_refresh(struct repeating_timer *t)
{
    int gpio = 0;
    int col = 0;

    // Turn everything off
    gpio = ROW_BASE;
    while(gpio != ROW_BASE + 8)
    {
        gpio_init(gpio);
        gpio_set_dir(gpio, GPIO_OUT);
        gpio_put(gpio, 0);

        gpio = gpio + 1;
    }

    if(matrix_current_row >= 7)
    {
        matrix_current_row = 0;
    }
    else
    {
        matrix_current_row = matrix_current_row + 1;
    }


    // Set the segment values
    while(col != 8)
    {
        gpio_put(COL_BASE + col, (matrix_frame_buffer[matrix_current_row] & (0x01 << col)));
        col = col + 1;
    }

    // Enable the row
    gpio_put(ROW_BASE + matrix_current_row, 1);

    return true;
}

// Set the current value of the display
void led_matrix_set_row(uint8_t row, uint8_t value)
{
    if(row < 8)
    {
    	matrix_frame_buffer[row] = value;
    }
}
