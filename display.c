#include "display.h"

static uint8_t display_width;
static uint8_t display_height;
static char * display_rows;
static char * display_current_row;

void display_init(uint8_t width, uint8_t height, char * rows) {
    display_width = width;
    display_height = height;
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
