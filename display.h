#ifndef DISPLAY_H
#define DISPLAY_H

#include "types.h"

typedef void (*TDisplayFlushAction)();
typedef void (*TDisplayCursorShow)();
typedef void (*TDisplayCursorHide)();
typedef void (*TDisplayCursorTo)(uint8_t x, uint8_t y);

typedef struct {
    uint16_t width;
    uint16_t height;
} TDisplaySize;

typedef struct {
    TDisplaySize size;
    TDisplayFlushAction flush;
    TDisplayCursorShow show_cursor;
    TDisplayCursorHide hide_cursor;
    TDisplayCursorTo cursor_to;
} TDisplayConfig;

void display_init(TDisplayConfig FLASH * display_config, char * display_rows);
void display_clear();
void display_goto_row(uint8_t row_index);
void display_print_str(char * str, uint16_t pos);
void display_print_const_str(char FLASH * str, uint16_t pos);

void display_flush();
void display_cursor_show();
void display_cursor_hide();
void display_cursor_to(uint8_t x, uint8_t y);

#endif
