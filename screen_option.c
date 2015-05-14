#include "screen_option.h"

#include "display.h"

void screen_option_print(TPrintable FLASH * printable) {
    TScreenOption FLASH * screen_option = (TScreenOption FLASH *) printable;
    PRINTABLE_PRINT(screen_option->elements[0]);
    PRINTABLE_PRINT(screen_option->elements[1]);
}

void screen_option_select(TScreenItem FLASH * screen_item) {
    TScreenOptionVar FLASH * var_item = (TScreenOptionVar FLASH *)
            ((TScreenOption FLASH *) screen_item)->elements[1];
    var_item->settings.next();
    screen_display();
}

void screen_option_item_print(TPrintable FLASH * printable) {
    TScreenOptionVar FLASH * var_item = (TScreenOptionVar FLASH *) printable;
    uint16_t current_value = var_item->settings.current();
    TScreenOptionItem FLASH * selected_item = var_item->option_items;

    for(; selected_item->key != 0; ++selected_item) {
        if (selected_item->value == current_value) break;
    }

    display_print_const_str(selected_item->key, var_item->pos);
}
