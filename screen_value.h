#ifndef SCREEN_VALUE_H
#define SCREEN_VALUE_H

#include "screen.h"
#include "screen_text.h"

#define SCREEN_VALUE(value_name, caption, var) \
    TScreenText FLASH value_name##_caption = caption; \
    TScreenValueVar FLASH value_name##_var = var; \
    TScreenValue FLASH value_name = { \
        SCREEN_ITEM_INIT(screen_value_print, screen_value_select), \
        { \
            (TPrintable FLASH *) &value_name##_caption, \
            (TPrintable FLASH *) &value_name##_var \
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

typedef struct {
    TScreenItem _base;
    TPrintable FLASH * elements[];
} TScreenValue;

typedef uint16_t (*TValueGetter)();
typedef void (*TValueSetter)(uint16_t);

typedef struct {
    TValueGetter current;
    TValueSetter change;
    TValueGetter min;
    TValueGetter max;
} TScreenValueSettings;

typedef struct {
    TPrintable _base;
    TScreenValueSettings settings;
    uint16_t digits;
    uint16_t decimals;
    uint16_t pos;
} TScreenValueVar;

void screen_value_print(TPrintable FLASH * screen_item);
void screen_print_var(TPrintable FLASH * screen_item);
void screen_value_select(TScreenItem FLASH *);

#endif
