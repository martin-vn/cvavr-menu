#ifndef SCREEN_TEXT_H
#define SCREEN_TEXT_H

#include "types.h"
#include "printable.h"

#define SCREEN_TEXT(text, pos) { \
        PRINTABLE_INIT(screen_print_text), \
        text, \
        pos \
    }

typedef struct {
    TPrintable _base;
    char FLASH * text;
    uint16_t pos;
} TScreenText;

void screen_print_text(TPrintable FLASH * screen_item);

#endif
