#ifndef SCREEN_VALUE_H
#define SCREEN_VALUE_H

#include "screen.h"
#include "screen_composite.h"
#include "screen_text.h"

#define SCREEN_VALUE(name, caption, value) \
    TScreenText FLASH _##name##_caption = caption; \
    TScreenValue FLASH _##name##_value = value; \
    SCREEN_COMPOSITE( \
        name, \
        _##name##_caption, \
        _##name##_value, \
        screen_value_select \
    )

#define SCREEN_VAR(digits, decimals, settings, pos) { \
        PRINTABLE_INIT(screen_print_var), \
        settings, \
        digits, \
        decimals, \
        pos \
    }

#define SCREEN_VAR_SETTINGS(set, get, min, max) {set, get, min, max}

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
} TScreenValue;

void screen_print_var(TPrintable FLASH * screen_item);
void screen_value_select(TScreenItem FLASH *);

#endif
