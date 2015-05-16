#include "console.h"
#include "stack.h"

STACK(console_stack, 3);
static TConsole FLASH * console_current = 0;

void console_init() {
    console_current = 0;
    stack_reset(&console_stack);
}

void console_push(TConsole FLASH * console) {
    if (console_current != 0) {
        if (stack_push(&console_stack, (void FLASH *) console_current) == -1) return;
    }
    console_current = console;
}

void console_pop() {
    TConsole FLASH * top_console = (TConsole FLASH * ) stack_pop(&console_stack);

    if (top_console == 0) return;
    console_current = top_console;
}

void console_up() {
    if (!console_current) return;
    console_current->up();
}

void console_down() {
    if (!console_current) return;
    console_current->down();
}

void console_select() {
    if (!console_current) return;
    console_current->select();
}

void console_alt() {
    if (!console_current) return;
    console_current->alt();
}

void console_null_action() {}
