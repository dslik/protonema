// ---------------------------------------------------------------------------------
// Seven Segment Display Demo
// ---------------------------------------------------------------------------------
// This example program shows how to drive a four-digit seven-segment display using
// multiplexing. The display_refresh function is called on a timer to sequentially
// illuminate each digit.
// ---------------------------------------------------------------------------------
// Source:  Own work (David Slik, https://github.com/dslik)
// License: CERN-OHL-S v2 (https://github.com/dslik/protonema/blob/main/license.md)
// ---------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "led_display.h"

// Constants
#define LED_PIN 25

// Global Variables
volatile uint8_t current_led_value = 0;

// Blink the on-board LED on the 1031A Pi Pico stamp
// This allows for easy verificaiton of successful download of the program, and
// makes it obvious when the processor has crashed. 
bool led_blink(struct repeating_timer *t)
{
    if(current_led_value == 0) current_led_value = 1;
    else current_led_value = 0;

    gpio_put(LED_PIN, current_led_value);
}

int main() {
    struct  repeating_timer ledTimer;
    struct  repeating_timer displayTimer;

    stdio_init_all();
    led_display_init();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Blink the LED on the Pi Pico
    add_repeating_timer_ms(500, led_blink, NULL, &ledTimer);
    add_repeating_timer_ms(2, led_display_refresh, NULL, &displayTimer);

    // Count upwards starting from zero
    led_display_set_value(0);

    // Uncomment to use a fixed point representation 
    //led_display_set_dp(1);

    while (true)
    {
        sleep_ms(100);
        led_display_set_value(led_display_get_value() + 1);
    }
}
