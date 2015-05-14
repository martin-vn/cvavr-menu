#include "display.h"

static uint8_t display_width;
static uint8_t display_height;
static char * display_rows;
static char * display_current_row;
static TDisplayConfig FLASH * display_config;

void display_init(TDisplayConfig FLASH * config, char * rows) {
    display_width = config->size.width;
    display_height = config->size.height;
    display_config = config;
    display_rows = rows;
    display_clear();
    display_goto_row(0);
}

void display_clear() {
    uint8_t i;
    char * buffer = display_rows;
    for (i = 0; i < display_width * display_height; ++i, ++buffer) {
        *buffer = ' ';
    }
}

void display_goto_row(uint8_t row_index) {
    if (row_index >= display_height) return;
    display_current_row = &display_rows[row_index * display_width];
}

void display_print_str(char * str, uint8_t pos) {
    char * buffer = display_current_row + pos;
    if (str == 0) return;
    for (; *str != 0; ++buffer, ++str) {
        *buffer = *str;
    }
}

void display_print_const_str(const char * str, uint8_t pos) {
    char * buffer = display_current_row + pos;
    if (str == 0) return;
    for (; *str != 0; ++buffer, ++str) {
        *buffer = *str;
    }
}

void display_flush() {
    if (!display_config) return;
    display_config->flush();
}

void display_cursor_show() {
    if (!display_config) return;
    display_config->show_cursor();
}

void display_cursor_hide() {
    if (!display_config) return;
    display_config->hide_cursor();
}

void display_cursor_to(uint8_t x, uint8_t y) {
    display_config->cursor_to(x, y);
}
