#include "screen_value.h"

#include "display.h"
#include "screen.h"
#include "utils.h"

void screen_value_up();
void screen_value_down();
void screen_value_shift();
void screen_value_back();

CONSOLE(
    screen_value_console,
    screen_value_up,
    screen_value_down,
    screen_value_shift,
    screen_value_back
);

static TScreenValue FLASH * current_value = 0;

static uint16_t value_step = 0;
static uint8_t value_cursor_col = 0;

#define LAST_DIGIT_POS(current_value) current_value->pos + current_value->digits - 1
#define DOT_POS(current_value) current_value->pos + current_value->digits - current_value->decimals

void screen_print_var(TPrintable FLASH * screen_item) {
    TScreenValue FLASH * var_item = (TScreenValue FLASH *) screen_item;
    char value_str[6] = {0};

    val_to_str(
        var_item->settings.current(),
        var_item->digits,
        var_item->decimals,
        value_str
    );
    display_print_str(value_str, var_item->pos);
}

void screen_value_select(TScreenItem FLASH * screen_item) {
    TScreenComposite FLASH * value_item = (TScreenComposite FLASH *) screen_item;

    current_value = (TScreenValue FLASH *) value_item->elements[1];
    value_step = 1;
    value_cursor_col = LAST_DIGIT_POS(current_value);
    if (current_value->decimals) ++value_cursor_col;

    console_push(&screen_value_console);
    screen_cursor_to_col(value_cursor_col);
    screen_cursor_show();
    screen_display();
}

void screen_value_up() {
    uint16_t value;
    uint16_t max;

    if (!current_value) return;

    value = current_value->settings.current();
    max = current_value->settings.max();
    if (value > max - value_step) {
        value = max;
    } else {
        value += value_step;
    }
    current_value->settings.change(value);
    screen_display();
}

void screen_value_down() {
    uint16_t value;
    uint16_t min;

    if (!current_value) return;

    value = current_value->settings.current();
    min = current_value->settings.min();

    if (value < min + value_step) {
        value = min;
    } else {
        value -= value_step;
    }
    current_value->settings.change(value);
    screen_display();
}

void screen_value_shift() {
    if (!current_value) return;

    value_step *= 10;
    if (value_step > current_value->settings.max()) {
        screen_value_back();
    } else {
        --value_cursor_col;
        if (value_cursor_col == DOT_POS(current_value)) {
            --value_cursor_col;
        }
        screen_cursor_to_col(value_cursor_col);
        screen_display();
    }
}

void screen_value_back() {
    screen_cursor_hide();
    console_pop();
}
