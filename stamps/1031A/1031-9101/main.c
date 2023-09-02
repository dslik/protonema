// ---------------------------------------------------------------------------------
// Raspberry Pi Pico Test Program
// ---------------------------------------------------------------------------------
// This example program blinks the on-board LED on the Raspberry Pi Pico, and turns
// the smart LED to purple.
// ---------------------------------------------------------------------------------
// Source:  Own work (David Slik, https://github.com/dslik)
// License: CERN-OHL-S v2 (https://github.com/dslik/protonema/blob/main/license.md)
// ---------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"

#include "pico-utils/ws2812.h"

// Constants
#define WS2812_GPIO     22  // GPIO for the stamp LED
#define PICO_LED_GPIO   25  // GPIO for the Pi Pico LED

// Prototypes
volatile uint8_t current_led_value = 0;

// Blink the on-board LED on the 1031A Pi Pico stamp
// This allows for easy verification of successful loading of the program, and
// makes it obvious when the processor has crashed. 
static bool led_blink(struct repeating_timer *t)
{
    if(current_led_value == 0) current_led_value = 1;
    else current_led_value = 0;

    gpio_put(PICO_LED_GPIO, current_led_value);
}

// Demo program
int main() {
    struct  repeating_timer ledTimer;

    stdio_init_all();

    printf("\n\n");
    printf("---------------------------------------------------------------------------------\n");
    printf("Protonema 1031A Pi Pico Stamp Test, Firmware 0.2.0-alpha.1\n");
    printf("CERN-OHL-S v2 (https://github.com/dslik/nanomia/blob/main/license.md)\n");
    printf("---------------------------------------------------------------------------------\n");
    printf("PIO init...\n");

    // Choose PIO instance (0 or 1)
    PIO pio = pio1;

    // Get first free state machine in PIO 1
    uint sm = pio_claim_unused_sm(pio, true);
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, WS2812_GPIO, 800000, false);

    printf("PIO test: LED should illuminate purple\n");

    gpio_init(PICO_LED_GPIO);
    gpio_set_dir(PICO_LED_GPIO, GPIO_OUT);

    // Blink the on-board LED on the Pi Pico
    add_repeating_timer_ms(500, led_blink, NULL, &ledTimer);

    while (true)
    {
        sleep_ms(100);
    }
}
