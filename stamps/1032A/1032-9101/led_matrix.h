// ---------------------------------------------------------------------------------
// 8x8 LED matrix driver for RP2040
// ---------------------------------------------------------------------------------
// These library routines allow you to control a multiplexed 8x8 LED matrix display
// using GPIO lines.
//
// This file contains prototype and constants.
// 
// Notes:
// * Modify the pin constants to correspond to the pins you wire up
// * If the RP2040 is halted, the current digit will display with full brightness
//   Make sure this is within safe current limits. 
// ---------------------------------------------------------------------------------
// Source:  Own work (David Slik, https://github.com/dslik)
// License: CERN-OHL-S v2 (https://github.com/dslik/protonema/blob/main/license.md)
// ---------------------------------------------------------------------------------
#include <stdlib.h>
#include "pico/stdlib.h"

// Pin Constants
#define ROW_BASE 0  // Eight sequential GPIO lines corresponding to LED rows
#define COL_BASE 8  // Eight sequential GPIO lines corresponding to LED columns

// Prototypes
void led_matrix_init(void);
bool led_matrix_refresh(struct repeating_timer *t);
void led_matrix_set_row(uint8_t row, uint8_t value);
