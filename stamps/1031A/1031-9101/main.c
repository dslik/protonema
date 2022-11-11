// ---------------------------------------------------------------------------------
// Raspberry Pi Pico Test Program
// ---------------------------------------------------------------------------------
// This example program blinks the on-board LED on the Raspberry Pi Pico.
// ---------------------------------------------------------------------------------
// Source:  Own work (David Slik, https://github.com/dslik)
// License: CERN-OHL-S v2 (https://github.com/dslik/protonema/blob/main/license.md)
// ---------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"

// Constants
#define LED_PIN 25

// Prototypes
volatile uint8_t current_led_value = 0;

// Blink the on-board LED on the 1031A Pi Pico stamp
// This allows for easy verificaiton of successful download of the program, and
// makes it obvious when the processor has crashed. 
static bool led_blink(struct repeating_timer *t)
{
    if(current_led_value == 0) current_led_value = 1;
    else current_led_value = 0;

    gpio_put(LED_PIN, current_led_value);
}

// Demo program
int main() {
    struct  repeating_timer ledTimer;

    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Blink the on-board LED on the Pi Pico
    add_repeating_timer_ms(500, led_blink, NULL, &ledTimer);

    while (true)
    {
        sleep_ms(100);
    }
}
