// ---------------------------------------------------------------------------------
// Seven Segment Temperature Display Demo
// ---------------------------------------------------------------------------------
// This example program shows how to drive a four-digit seven-segment display using
// multiplexing. The value displayed is read from an I2C temperature sensor.
// ---------------------------------------------------------------------------------
// Source:  Own work (David Slik, https://github.com/dslik)
// License: CERN-OHL-S v2 (https://github.com/dslik/protonema/blob/main/license.md)
// ---------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "led_display.h"
#include "lm75.h"

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
    float   temp;

    stdio_init_all();
    led_display_init();
    led_display_set_dp(1);

    lm75_init(I2C_LM75_ADDR);

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Blink the LED on the Pi Pico
    add_repeating_timer_ms(500, led_blink, NULL, &ledTimer);
    add_repeating_timer_ms(2, led_display_refresh, NULL, &displayTimer);

    while (true)
    {
        temp = lm75_reg_read(I2C_LM75_ADDR);
        led_display_set_value(temp * 10);
        sleep_ms(100);
    }
}
