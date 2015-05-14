#include "screen.h"
#include "display.h"
#include "stack.h"

static TScreen FLASH * screen_current = 0;
static uint8_t screen_cursor_row = 0;
static uint8_t screen_offset = 0;
STACK(screen_stack, 3);

#define CURRENT_ITEM_INDEX (screen_cursor_row + screen_offset)

void screen_init() {
    screen_current = 0;
    screen_cursor_row = 0;
    screen_offset = 0;
    stack_reset(&screen_stack);
}

void screen_push(TScreen FLASH * screen) {
    if (screen_current != 0) {
        if (stack_push(&screen_stack, (void *) screen_current) == -1) return;
    }
    screen_current = screen;
    console_push(screen->console);
    screen_display();
}

void screen_pop() {
    TScreen FLASH * top_screen = (TScreen FLASH *) stack_pop(&screen_stack);
    if (top_screen == 0) return;
    screen_current = top_screen;
    screen_display();
}

void screen_display() {
    TScreenItem FLASH ** current_item = &screen_current->items[screen_offset];
    uint8_t row_index;

    if (screen_current == 0) return;

    display_clear();

    for (row_index = 0; *current_item != 0 && row_index < 2; ++current_item, ++row_index) {
        display_goto_row(row_index);
        if (screen_cursor_row == row_index) {
            display_print_const_str(screen_current->cursor, 0);
        }
        PRINTABLE_PRINT(*current_item);
    }
}

void screen_cursor_up() {
    if (screen_cursor_row > 0) {
        --screen_cursor_row;
    } else if (screen_offset > 0) {
        --screen_offset;
    }
    screen_display();
}

void screen_cursor_down() {
    if (screen_cursor_row < 1) {
        ++screen_cursor_row;
    } else {
        if (screen_current->items[CURRENT_ITEM_INDEX + 1] == 0) return;
        ++screen_offset;
    }
    screen_display();
}

void screen_select() {
    TScreenItem FLASH * current_item = screen_current->items[CURRENT_ITEM_INDEX];

    if (screen_current == 0) return;
    SCREEN_ITEM_SELECT(current_item);
}

void screen_alt_action() {
}
