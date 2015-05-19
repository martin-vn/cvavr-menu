#include "screen_option.h"

#include "display.h"

void screen_option_select(TScreenItem FLASH * screen_item) {
    TScreenOption FLASH * var_item = (TScreenOption FLASH *)
            ((TScreenComposite FLASH *) screen_item)->elements[1];
    var_item->settings.next();
    screen_display();
}

void screen_option_item_print(TPrintable FLASH * printable) {
    TScreenOption FLASH * var_item = (TScreenOption FLASH *) printable;
    uint16_t current_value = var_item->settings.current();
    TScreenOptionItem FLASH * selected_item = var_item->option_items;

    for(; selected_item->value != 0; ++selected_item) {
        if (selected_item->key == current_value) break;
    }

    display_print_const_str(selected_item->value, var_item->pos);
}
