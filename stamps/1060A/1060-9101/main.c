// ---------------------------------------------------------------------------------
// Test program for the 1060A Dual potentiometer stamp
// ---------------------------------------------------------------------------------
// This example program shows how to read analog values from the dual potentiometers
// and display the voltage levels on the display on the Protonema 1068A Intelligent
// Display stamp.
// ---------------------------------------------------------------------------------
// Source:  Own work (David Slik, https://github.com/dslik)
// License: CERN-OHL-S v2 (https://github.com/dslik/protonema/blob/main/license.md)
// ---------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/adc.h"

#include "display.h"

// Constants
#define LED_PIN 25

// Globals
volatile uint8_t current_led_value = 0;
const float conversion_factor = 3.0f / (1 << 12);

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
    uint8_t adc_channel = 0;
    uint32_t counter = 0;
    float voltage = 0;
    char buffer[] = "0xxxxxxxx1xxxxxxxxx2";

    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Blink the on-board LED on the Pi Pico
    add_repeating_timer_ms(500, led_blink, NULL, &ledTimer);

    // Initialize the display
    display_init();

    // Initialize the ADCs
    adc_init();
    adc_gpio_init(26);
    adc_gpio_init(27);

    while (true)
    {
        adc_select_input(adc_channel);
        voltage = adc_read() * conversion_factor;

        sprintf(buffer, "%f", voltage);
        display_send_string(buffer);

        sleep_ms(25);
        counter = counter + 1;

        if(counter > 20)
        {
            adc_channel = !adc_channel;
            counter = 0;
        }
    }
}
