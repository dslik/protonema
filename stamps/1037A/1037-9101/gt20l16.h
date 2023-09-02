// ---------------------------------------------------------------------------------
// GT20L16 Font IC Utility Routines - Header
// ---------------------------------------------------------------------------------
// Routines for initializing and reading characters from a GT20L16 font IC
// ---------------------------------------------------------------------------------
// Source:  Own work (David Slik, https://github.com/dslik)
// License: CERN-OHL-S v2 (https://github.com/dslik/protonema/blob/main/license.md)
// ---------------------------------------------------------------------------------
#define PIN_FC_CS           15  // Font IC Chip Select
#define PIN_FC_SO           14  // Font IC Serial Output
#define PIN_FC_CL           13  // Font IC Clock

void gt20l16_init(void);
void gt20l16_start_data(void);
uint32_t gt20l16_unicode_to_address(uint16_t codepoint);
void gt20l16_set_address(uint32_t address);
uint8_t gt20l16_read_byte(void);
uint8_t gt20l16_read_character(uint8_t* glyph);
void gt20l16_end_data(void);

void gt20l16_draw_character(uint16_t character, uint16_t x, uint16_t y, uint8_t scale);
void gt20l16_draw_string(char* string, uint16_t x, uint16_t y, uint8_t scale);


