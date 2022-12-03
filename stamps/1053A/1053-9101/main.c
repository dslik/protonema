// ---------------------------------------------------------------------------------
// MIDI Output Test
// ---------------------------------------------------------------------------------
// This example program shows how to send MIDI messages.
// ---------------------------------------------------------------------------------
// Source:  Own work (David Slik, https://github.com/dslik)
// License: CERN-OHL-S v2 (https://github.com/dslik/protonema/blob/main/license.md)
// ---------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pico/stdlib.h"

// Constants
#define LED_PIN               25
#define PIN_MIDI_UART_TX      16

// Global Variables
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

    // Initialize the UART for MIDI
    uart_init(uart0, 31250);
    gpio_set_function(PIN_MIDI_UART_TX, GPIO_FUNC_UART);

    sleep_ms(500);

    uart_putc(uart0, 0x90);
    uart_putc(uart0, 0x3C);
    uart_putc(uart0, 0x7F);

    sleep_ms(500);

    uart_putc(uart0, 0x80);
    uart_putc(uart0, 0x3C);
    uart_putc(uart0, 0x00);

    while(true)
    {
        sleep_ms(250);
    }
}
