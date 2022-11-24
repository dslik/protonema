// ---------------------------------------------------------------------------------
// Four-digit seven-segment driver for RP2040
// ---------------------------------------------------------------------------------
// These library routines allow you to control a multiplexed seven segement display
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
#define SEG_BASE 0  // Eight sequential GPIO lines corresponding to LED segments
#define DIG_BASE 8  // Four sequential GPIO lines corresponding to LED digits

// Prototypes
void led_display_init(void);
bool led_display_refresh(struct repeating_timer *t);
void led_display_set_value(uint16_t value);
uint16_t led_display_get_value(void);
void led_display_set_dp(uint8_t value);
