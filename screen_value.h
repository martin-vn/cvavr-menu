#ifndef SCREEN_VALUE_H
#define SCREEN_VALUE_H

#include "screen.h"
#include "screen_text.h"

/* TODO Remove after tests */
#define TOREMOVE static

#define SCREEN_VALUE(value_name, caption, var) \
    FLASH TScreenText value_name##_caption = caption; \
    TOREMOVE FLASH TScreenValueVar value_name##_var = var; \
    TOREMOVE FLASH TScreenValue value_name = { \
        SCREEN_ITEM_INIT(screen_value_print, screen_value_select), \
        { \
            (TPrintable FLASH * FLASH) &value_name##_caption, \
            (TPrintable FLASH * FLASH) &value_name##_var \
        } \
    }

#define SCREEN_VAR(digits, decimals, settings, pos) { \
        PRINTABLE_INIT(screen_print_var), \
        settings, \
        digits, \
        decimals, \
        pos \
    }

#define SCREEN_VAR_SETTINGS(set, get, min, max) {set, get, min, max}

typedef FLASH struct {
    TScreenItem FLASH _base;
    TPrintable FLASH * FLASH elements[];
} TScreenValue;

typedef uint16_t (*TValueGetter)();
typedef void (*TValueSetter)(uint16_t);

typedef FLASH struct {
    TValueGetter current;
    TValueSetter change;
    TValueGetter min;
    TValueGetter max;
} TScreenValueSettings;

typedef FLASH struct {
    TPrintable FLASH _base;
    TScreenValueSettings FLASH settings;
    uint16_t FLASH digits;
    uint16_t FLASH decimals;
    uint16_t FLASH pos;
} TScreenValueVar;

void screen_value_print(TPrintable FLASH * screen_item);
void screen_print_var(TPrintable FLASH * screen_item);
void screen_value_select(TScreenItem FLASH *);

#endif
