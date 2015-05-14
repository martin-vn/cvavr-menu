#include "screen_value.h"

#include "display.h"
#include "screen.h"
#include "utils.h"

void screen_value_up();
void screen_value_down();
void screen_value_shift();
void screen_value_back();

static CONSOLE(
    screen_value_console,
    screen_value_up,
    screen_value_down,
    screen_value_shift,
    screen_value_back
);

static TScreenValueSettings FLASH * current_value_setting = 0;
static uint16_t value_step = 0;

void screen_value_print(TPrintable FLASH * screen_item) {
    TScreenValue FLASH * screen_value = (TScreenValue FLASH *) screen_item;
    PRINTABLE_PRINT(screen_value->elements[0]);
    PRINTABLE_PRINT(screen_value->elements[1]);
}

void screen_print_var(TPrintable FLASH * screen_item) {
    TScreenVar FLASH * var_item = (TScreenVar FLASH *) screen_item;
    char value_str[6] = {0};

    val_to_str(
        var_item->settings.current(),
        var_item->digits,
        var_item->decimals,
        (char *) &value_str
    );
    display_print_str(value_str, var_item->pos);
}

void screen_value_select(TScreenItem FLASH * screen_item) {
    TScreenValue FLASH * value_item = (TScreenValue FLASH *) screen_item;
    current_value_setting = &((TScreenVar FLASH *) value_item->elements[1])->settings;
    value_step = 1;
    console_push(&screen_value_console);
    /* TODO show cursor */
}

void screen_value_up() {
    uint16_t value;
    uint16_t max;

    if (!current_value_setting) return;

    value = current_value_setting->current();
    max = current_value_setting->max();
    if (value > max - value_step) {
        value = max;
    } else {
        value += value_step;
    }
    current_value_setting->change(value);
    screen_display();
}

void screen_value_down() {
    uint16_t value;
    uint16_t min;

    if (!current_value_setting) return;

    value = current_value_setting->current();;
    min = current_value_setting->min();

    if (value < min + value_step) {
        value = min;
    } else {
        value -= value_step;
    }
    current_value_setting->change(value);
    screen_display();
}

void screen_value_shift() {
    if (!current_value_setting) return;
    value_step *= 10;
    if (value_step > current_value_setting->max()) {
        screen_value_back();
    } else {
    /* TODO move cursor */
    }
}

void screen_value_back() {
    if (!current_value_setting) return;
    /* TODO hide cursor */
    console_pop();
}
