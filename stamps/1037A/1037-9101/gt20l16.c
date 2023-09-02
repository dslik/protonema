// ---------------------------------------------------------------------------------
// GT20L16 Font IC Utility Routines
// ---------------------------------------------------------------------------------
// Routines for initializing and reading characters from a GT20L16 font IC
// Requires st7789 LCD library
// ---------------------------------------------------------------------------------
// Source:  Own work (David Slik, https://github.com/dslik)
// License: CERN-OHL-S v2 (https://github.com/dslik/protonema/blob/main/license.md)
// ---------------------------------------------------------------------------------
#include <string.h>

#include "pico/stdlib.h"

#include "gt20l16.h"
#include "st7789_lcd.h"

void gt20l16_init(void)
{
    // Init Font IC Select
    gpio_init(PIN_FC_SO);
    gpio_pull_up(PIN_FC_SO);
    gpio_set_dir(PIN_FC_SO, GPIO_IN);

    gpio_init(PIN_FC_CS);
    gpio_set_dir(PIN_FC_CS, GPIO_OUT);
    gpio_put(PIN_FC_CS, 1);
    sleep_us(1);
}

void gt20l16_start_data(void)
{
    sleep_us(5); // Wait for the PIO to finish
    gpio_put(PIN_FC_CS, 0);
    sleep_us(1);
}

// Font IC utility routines
void gt20l16_set_address(uint32_t address)
{
    pio_gpio_init(pio0, PIN_FC_CL);

    st7789_set_halfpixel(0b00000011);
    st7789_set_halfpixel(address >> 16);
    st7789_set_halfpixel(address >> 8);
    st7789_set_halfpixel(address);

    sleep_us(5); // Wait for the PIO to finish

    gpio_init(PIN_FC_CL);
    gpio_set_dir(PIN_FC_CL, GPIO_OUT);
}

uint8_t gt20l16_read_byte(void)
{
    uint8_t value = 0;
    uint8_t count = 0;

    while(count != 8)
    {
        gpio_put(PIN_FC_CL, 1);
        value = value << 1;
        value = value + (gpio_get(PIN_FC_SO) != 0);
        sleep_us(1);
        gpio_put(PIN_FC_CL, 0);
        sleep_us(1);
        
        count = count + 1;
    }

    return(value);
}

uint8_t gt20l16_read_character(uint8_t* glyph)
{
    uint8_t count = 0;
    uint8_t width = 0;

    while(count != 32)
    {
        glyph[count] = gt20l16_read_byte();
        count = count + 1;
    }

    return width;
}

uint32_t gt20l16_unicode_to_address(uint16_t codepoint)
{
    uint32_t address = 0;

    // Basic Latin
    if(codepoint >= 0x20 && codepoint <= 0x7F)
    {
        address = 16 * (codepoint - 0x20);
    }

    // Latin-1 Supplement
    if(codepoint >= 0xA0 && codepoint <= 0xFF)
    {
        address = 16 * (codepoint - 0xA0 + 96);
    }

    // Latin-1 Extended A
    if(codepoint >= 0x100 && codepoint <= 0x17F)
    {
        address = 16 * (codepoint - 0x100 + 192);
    }

    // Subset of Latin-1 Extended B
    if(codepoint >= 0x1A0 && codepoint <= 0x1CF)
    {
        address = 16 * (codepoint - 0x1A0 + 320);
    }

    // Another subset of Latin-1 Extended B
    if(codepoint >= 0x1F0 && codepoint <= 0x1FF)
    {
        address = 16 * (codepoint - 0x1F0 + 368);
    }

    // Test
    if(codepoint >= 0xA1A1 && codepoint <= 0xF7FE)
    {
        address = 16 * (codepoint - 0xA1A1 + 368);
    }

    return address;
}

void gt20l16_end_data(void)
{
    gpio_put(PIN_FC_CS, 1);
    sleep_us(1);
    pio_gpio_init(pio0, PIN_FC_CL);
}

void gt20l16_draw_character(uint16_t character, uint16_t x, uint16_t y, uint8_t scale)
{
    uint8_t glyph[34];
    int pX      = 0;
    int pY      = 0;
    uint16_t color   = 0;

    gt20l16_start_data();
    gt20l16_set_address(gt20l16_unicode_to_address(character));
    gt20l16_read_character((uint8_t*) glyph);
    gt20l16_end_data();

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < (16 / 2); j++) {

            if (glyph[(j)] & (0x01 << (7 - i))) {
                color = st7789_get_fgcolor();
            } else {
                color = st7789_get_bgcolor();
            }

            pX = x + j;
            pY = y + 8 + i;

            st7789_set_pixel_xy(color, pX, pY, scale);
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < (16 / 2); j++) {

            if (glyph[(j) + (16 / 2)] & (0x01 << (7 - i))) {
                color = st7789_get_fgcolor();
            } else {
                color = st7789_get_bgcolor();
            }

            pX = x + j;
            pY = y + i;

            st7789_set_pixel_xy(color, pX, pY, scale);
        }
    }

    sleep_us(5); // Wait for the PIO to finish

    st7789_end_pixels();

}

void gt20l16_draw_string(char* string, uint16_t x, uint16_t y, uint8_t scale)
{
    uint16_t    string_length = strlen(string);
    uint16_t    counter = 0;
    uint16_t    x_position = x;

    while(counter != string_length)
    {
        gt20l16_draw_character(string[counter], x_position, y, scale);

        x_position = x_position + 8;
        counter = counter + 1;
    }
}

