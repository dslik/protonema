// ---------------------------------------------------------------------------------
// 1037A Demo Program - Pi Pico ST7789 LCD Test
// ---------------------------------------------------------------------------------
// This demonstrates displaying images on an ST7789 LCD, and reading and using
// fonts from a GT20L16 font IC.
// ---------------------------------------------------------------------------------
// Source:  Own work (David Slik, https://github.com/dslik)
// License: CERN-OHL-S v2 (https://github.com/dslik/protonema/blob/main/license.md)
// ---------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/i2c.h"

#include "pico-utils/ws2812.h"
#include "st7789_lcd.h"
#include "gt20l16.h"

// Constants
#define WS2812_GPIO         22  // GPIO for the stamp LED

// Demo program
int main()
{
    stdio_init_all();

    printf("\n\n");
    printf("---------------------------------------------------------------------------------\n");
    printf("Protonema 1037A LCD Display Test, Firmware 0.2.0-alpha.1\n");
    printf("CERN-OHL-S v2 (https://github.com/dslik/nanomia/blob/main/license.md)\n");
    printf("---------------------------------------------------------------------------------\n");
    printf("PIO init...\n");

    // Choose PIO instance (0 or 1)
    PIO pio = pio1;

    // Get first free state machine in PIO 1
    uint sm = pio_claim_unused_sm(pio, true);
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm, offset, WS2812_GPIO, 800000, false);
    put_pixel(urgb_u32(10,0,10));

    printf("PIO test: LED should be purple\n");

    printf("LCD init...\n");

    // Turn off backlight
    gpio_init(PIN_BL);
    gpio_set_dir(PIN_BL, GPIO_OUT);
    gpio_put(PIN_BL, 0);

    // Initialize the LCD
    st7789_init();
    st7789_init_lcd(PIN_CS);

    // Clear the LED to a green background
    st7789_start_pixels(PIN_CS);
    for (int y = 0; y < SCREEN_HEIGHT; ++y) {
        for (int x = 0; x < SCREEN_WIDTH; ++x) {
            uint16_t colour = (uint16_t) (0x0F00);
            st7789_set_pixel(colour);
        }
    }
    st7789_end_pixels();

    // Turn on backlight
    gpio_put(PIN_BL, 1);

    printf("LCD initialized...\n");

    printf("Displaying characters from font chip...\n");
    gt20l16_init();

    gt20l16_draw_string("Hello World!", 0, 224, 1);
    gt20l16_draw_string("Actual size of the font.", 0, 208, 1);

    gt20l16_draw_string("Hello World!", 0, 84, 2);
    gt20l16_draw_string("Doubled font.", 0, 68, 2);

    st7789_set_fgcolor(0xFFFF);
    st7789_set_bgcolor(0x0000);

    gt20l16_draw_string("Hello", 0, 16, 4);
    gt20l16_draw_string("World!", 0, 0, 4);

    // Do nothing
    while (true) {
        sleep_ms(1000);
    }
}
