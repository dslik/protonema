// ---------------------------------------------------------------------------------
// LED Matrix Demo
// ---------------------------------------------------------------------------------
// This example program shows how to drive a LED matrix. Values are read from a
// global memory buffer.
// ---------------------------------------------------------------------------------
// Source:  Own work (David Slik, https://github.com/dslik)
// License: CERN-OHL-S v2 (https://github.com/dslik/protonema/blob/main/license.md)
// ---------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "led_matrix.h"

// Constants
#define LED_PIN 25

// Global Variables
volatile uint8_t current_led_value = 0;


static bool led_blink(struct repeating_timer *t)
{
    if(current_led_value == 0) current_led_value = 1;
    else current_led_value = 0;

    gpio_put(LED_PIN, current_led_value);
}



int main() {
    uint8_t row_count = 0;
    uint8_t col_count = 0;
    struct  repeating_timer ledTimer;
    struct  repeating_timer displayTimer;

    stdio_init_all();
    led_matrix_init();

    gpio_init(LED_PIN);

    add_repeating_timer_ms(2, led_matrix_refresh, NULL, &displayTimer);
    add_repeating_timer_ms(500, led_blink, NULL, &ledTimer);

    // Sequentially turn on all LEDs
    while (true) {
        sleep_ms(100);

        if(row_count < 8)
        {
            led_matrix_set_row(row_count, 0xFF >> (7 - col_count));
            col_count = col_count + 1;

            if(col_count >= 8)
            {
                row_count = row_count + 1;
                col_count = 0;
            }
        }
    }
}

