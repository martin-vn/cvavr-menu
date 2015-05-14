#ifndef SCREEN_H
#define SCREEN_H

#include "types.h"
#include "console.h"
#include "printable.h"

#define SCREEN_ITEM_INIT(print_action, select_action) {{print_action}, select_action}
#define SCREEN_ITEM_SELECT(obj) ((TScreenItem FLASH *) obj)->select((TScreenItem FLASH *) obj)

#define SCREEN_ITEM(item_name) (TScreenItem FLASH * FLASH) &item_name,

#define SCREEN(name, cursor, console, items) \
    TScreen FLASH name = { \
        cursor, \
        &console, \
        {items 0} \
    }

FLASH struct _TScreenItem;

typedef void (*TScreenSelectAction)(FLASH struct _TScreenItem FLASH *);

typedef FLASH struct _TScreenItem {
    TPrintable _base;
    TScreenSelectAction select;
} TScreenItem;

typedef FLASH struct {
    const char * cursor;
    TConsole FLASH * FLASH console;
    TScreenItem FLASH * FLASH items[];
} TScreen;

void screen_init();
void screen_push(TScreen FLASH *);
void screen_pop();
void screen_display();
void screen_cursor_up();
void screen_cursor_down();
void screen_select();
void screen_alt_action();
void screen_cursor_show();
void screen_cursor_hide();
void screen_cursor_to_col(uint8_t x);

#endif
