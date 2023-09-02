// ---------------------------------------------------------------------------------
// ST7789 Utility Routines - Header
// ---------------------------------------------------------------------------------
// Library routines to assist in programming with ST7789-style LCDs.
// ---------------------------------------------------------------------------------
// SPDX-FileCopyrightText: Copyright 2023 David Slik (VE7FIM)
// SPDX-FileAttributionText: https://github.com/dslik/protonema/
// SPDX-License-Identifier: CERN-OHL-S-2.0
// ---------------------------------------------------------------------------------
#include <stdio.h>
#include <stdbool.h>

#include "pico/stdlib.h"
#include "hardware/pio.h"

#include "st7789_lcd.pio.h"

// Constants
#define PIN_DIN 12
#define PIN_CLK 13
#define PIN_CS 9
#define PIN_DC 10
#define PIN_RESET 11
#define PIN_BL 8

#define SCREEN_WIDTH        240
#define SCREEN_HEIGHT       240

// Prototypes
void st7789_init(void);
void st7789_init_lcd(uint8_t display_cs_pin);
extern void lcd_init(uint8_t display_cs_pin, const uint8_t *init_seq);
extern void st7789_start_pixels(uint8_t display_cs_pin);
extern void st7789_set_pixel(uint16_t colour);
extern void st7789_set_pixel_xy(uint16_t colour, uint16_t x, uint16_t y, uint8_t scale);
extern void st7789_set_window(uint16_t x1, uint16_t x2, uint16_t y1, uint16_t y2);
extern void st7789_set_halfpixel(uint8_t value);
extern void st7789_end_pixels(void);
extern void st7789_set_bgcolor(uint16_t colour);
extern uint16_t st7789_get_bgcolor(void);
extern void st7789_set_fgcolor(uint16_t colour);
extern uint16_t st7789_get_fgcolor(void);



