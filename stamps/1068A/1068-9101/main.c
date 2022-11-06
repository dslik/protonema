// ---------------------------------------------------------------------------------
// OSRAM SCF5742 bit-bang driver for SC2040
// ---------------------------------------------------------------------------------
// This example program shows how to display characters and strings on the OSRAM
// SCF5742 display on the Protonema 1068A Intelligent Display stamp.
// ---------------------------------------------------------------------------------
// Source:  Own work (David Slik, https://github.com/dslik)
// License: CERN-OHL-S v2 (https://github.com/dslik/protonema/blob/main/license.md)
// ---------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "display.h"

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
    uint8_t character = 0;

    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Blink the on-board LED on the Pi Pico
    add_repeating_timer_ms(500, led_blink, NULL, &ledTimer);

    // Initialize the display
    display_init();

    // Display the string "Yay"
    display_send_string("Yay");

    sleep_ms(1000);

    // Set the fourth digit to "!" 
    display_send_digit(3, characters['!']);

    sleep_ms(1000);

    // Set the fourth digit to a custom character 
    display_send_digit(3, 0x000103070F070301);

    sleep_ms(3000);

    // Loop through all of the characters in the typeface
    display_reset();
    character = 'A';

    while (true)
    {
        display_send_digit(0, characters[character]);
        display_send_digit(1, characters[character + 1]);
        display_send_digit(2, characters[character + 2]);
        display_send_digit(3, characters[character + 3]);

        character = character + 1;

        if(character == 124) character = 32;

        sleep_ms(100);
    }
}
