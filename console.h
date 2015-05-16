#ifndef CONSOLE_H
#define CONSOLE_H

#include "types.h"

#define CONSOLE(name, up_action, down_action, select_action, alt_action) \
    TConsole FLASH name = { \
        up_action, \
        down_action, \
        select_action, \
        alt_action \
    }

typedef void (*TConsoleAction)();

typedef FLASH struct {
    TConsoleAction up;
    TConsoleAction down;
    TConsoleAction select;
    TConsoleAction alt;
} TConsole;

void console_init();
void console_push(TConsole FLASH *);
void console_pop();
void console_up();
void console_down();
void console_select();
void console_alt();

void console_null_action();

#endif
