// ---------------------------------------------------------------------------------
// MIDI Input Test
// ---------------------------------------------------------------------------------
// This example program for a 1054A MIDI Input stamp that shows how to receive
// MIDI messages.
//
// If a 1068A Intelligent Display is connected, the note and octive is displayed.
//
// If a 1053A MIDI Output Stamp is connected, the note is also output transposed by
// on octive up.
// ---------------------------------------------------------------------------------
// Source:  Own work (David Slik, https://github.com/dslik)
// License: CERN-OHL-S v2 (https://github.com/dslik/protonema/blob/main/license.md)
// ---------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pico/stdlib.h"
#include "../../1068A/1068-9101/display.h"

// Constants
#define LED_PIN               25
#define PIN_MIDI_UART_TX      16
#define PIN_MIDI_UART_RX      17

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
    uint8_t midi_in_character;
    uint8_t midi_note;
    uint8_t midi_oct;
    uint64_t msg_data;
    char*   msg = (char*) &msg_data;

    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // Blink the on-board LED on the Pi Pico
    add_repeating_timer_ms(500, led_blink, NULL, &ledTimer);

    // Initialize the display
    display_init();

    // Initialize the UART for MIDI
    uart_init(uart0, 31250);
    gpio_set_function(PIN_MIDI_UART_TX, GPIO_FUNC_UART);
    gpio_set_function(PIN_MIDI_UART_RX, GPIO_FUNC_UART);

    // Display the string "MIDI"
    msg[0] = 'M';
    msg[1] = 'I';
    msg[2] = 'D';
    msg[3] = 'I';
    msg[4] = 0;
    display_send_string(msg);

    sleep_ms(1000);
    display_send_string("    ");

    while(true)
    {
        // Read the MIDI command
        midi_in_character = uart_getc(uart0);

        // Forward the MIDI command to MIDI out
        uart_putc(uart0, midi_in_character);

        if(midi_in_character == 0x90)
        {
            // Read the MIDI note
            midi_in_character = uart_getc(uart0);

            // Forward the MIDI note to MIDI out, transposing up by one octive
            uart_putc(uart0, midi_in_character + 12);

            midi_note = (midi_in_character - 21) % 12;
            midi_oct = (midi_in_character - 21) / 12 + '0';

            msg[2] = ' ';
            msg[3] = ' ';
            msg[4] = 0;

            if(midi_note == 0) { msg[0] = 'A'; msg[1] = midi_oct; }
            if(midi_note == 1) { msg[0] = 'A'; msg[1] = '#'; msg[2] = midi_oct; }
            if(midi_note == 2) { msg[0] = 'B'; msg[1] = midi_oct; }
            if(midi_note == 3) { msg[0] = 'C'; msg[1] = midi_oct; }
            if(midi_note == 4) { msg[0] = 'C'; msg[1] = '#'; msg[2] = midi_oct; }
            if(midi_note == 5) { msg[0] = 'D'; msg[1] = midi_oct; }
            if(midi_note == 6) { msg[0] = 'D'; msg[1] = '#'; msg[2] = midi_oct; }
            if(midi_note == 7) { msg[0] = 'E'; msg[1] = midi_oct; }
            if(midi_note == 8) { msg[0] = 'F'; msg[1] = midi_oct; }
            if(midi_note == 9) { msg[0] = 'F'; msg[1] = '#'; msg[2] = midi_oct; }
            if(midi_note == 10) { msg[0] = 'G'; msg[1] = midi_oct; }
            if(midi_note == 11) { msg[0] = 'G'; msg[1] = '#'; msg[2] = midi_oct; }

            //display_send_string(note);
            display_send_string(msg);
        
            // Read the MIDI velocity
            midi_in_character = uart_getc(uart0);

            // Forward the note velocity to MIDI out
            uart_putc(uart0, midi_in_character);
        }
        else
        {
            sprintf(msg, "0x%02X", midi_in_character);
            //display_send_string(msg);
        }
        
        sleep_ms(5);
    }
}
