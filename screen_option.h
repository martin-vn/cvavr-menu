#ifndef SCREEN_OPTION_H
#define SCREEN_OPTION_H

#include "screen.h"
#include "screen_composite.h"
#include "screen_text.h"

#define SCREEN_OPTION(name, caption, settings, option_items, pos) \
    TScreenText FLASH _##name##_caption = caption; \
    TScreenOptionItem FLASH _##name##_option_items[] = option_items; \
    TScreenOption FLASH _##name##_option = { \
        PRINTABLE_INIT(screen_option_item_print), \
        pos, \
        settings, \
        _##name##_option_items \
    }; \
    SCREEN_COMPOSITE( \
        name, \
        _##name##_caption, \
        _##name##_option, \
        screen_option_select \
    )

#define SCREEN_OPTION_ITEM_LIST(items) {items {0, 0}}

#define SCREEN_OPTION_ITEM(key, value) {key, value},

#define SCREEN_OPTION_SETTINGS(current, change) {current, change}

#define SCREEN_OPTION_VAR(settings, option_items, pos) { \
        PRINTABLE_INIT(screen_option_item_print), \
        pos, \
        settings, \
        option_items \
    } \

typedef struct {
    int16_t key;
    char FLASH * value;
} TScreenOptionItem;

typedef uint16_t (*TOptionGetter)();
typedef void (*TOptionAction)();

typedef struct {
    TOptionGetter current;
    TOptionAction next;
} TScreenValueSettings;

typedef struct {
    TPrintable _base;
    uint16_t pos;
    TScreenValueSettings settings;
    TScreenOptionItem FLASH * option_items;
} TScreenOption;

void screen_option_print(TPrintable FLASH *);
void screen_option_select(TScreenItem FLASH *);
void screen_option_item_print(TPrintable FLASH * printable);

#endif
