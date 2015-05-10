#include "screen_text.h"

#include "display.h"

void screen_print_text(TPrintable FLASH * screen_item) {
    TScreenText FLASH * text_item = (TScreenText FLASH *) screen_item;
    display_print_const_str(text_item->text, text_item->pos);
}
