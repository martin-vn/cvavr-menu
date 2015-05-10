#ifndef DISPLAY_H
#define DISPLAY_H

#include "types.h"

void display_init(uint8_t width, uint8_t height, char * display_rows);
void display_clear();
void display_goto_row(uint8_t row_index);
void display_print_str(char * str, uint8_t pos);
void display_print_const_str(const char * str, uint8_t pos);

#endif
