#ifndef SCREEN_OPTION_H
#define SCREEN_OPTION_H

#include "screen.h"
#include "screen_text.h"

#define SCREEN_OPTION(name, caption, settings, option_items, pos) \
    TScreenText FLASH name##_caption = caption; \
    TScreenOptionItem FLASH name##_option_items[] = option_items; \
    TScreenOptionVar FLASH name##_option = { \
        PRINTABLE_INIT(screen_option_item_print), \
        pos, \
        settings, \
        name##_option_items \
    }; \
    TScreenOption FLASH name = { \
        SCREEN_ITEM_INIT(screen_option_print, screen_option_select), \
        { \
            (TPrintable FLASH *) &name##_caption, \
            (TPrintable FLASH *) &name##_option \
        } \
    }

#define SCREEN_OPTION_ITEM_LIST(items) {items {0, 0}}

#define SCREEN_OPTION_ITEM(key, value) {key, value},

#define SCREEN_OPTION_SETTINGS(current, change) {current, change}

#define SCREEN_OPTION_VAR(settings, option_items, pos) { \
        PRINTABLE_INIT(screen_option_item_print), \
        pos, \
        settings, \
        option_items \
    } \

typedef FLASH struct {
    int16_t FLASH key;
    char FLASH * FLASH value;
} TScreenOptionItem;

typedef uint16_t (*TOptionGetter)();
typedef void (*TOptionAction)();

typedef FLASH struct {
    TOptionGetter current;
    TOptionAction next;
} TScreenValueSettings;

typedef FLASH struct {
    TPrintable FLASH _base;
    uint16_t FLASH pos;
    TScreenValueSettings FLASH settings;
    TScreenOptionItem FLASH * FLASH option_items;
} TScreenOptionVar;

typedef FLASH struct {
    TScreenItem FLASH _base;
    TPrintable FLASH * FLASH elements[];
} TScreenOption;

void screen_option_print(TPrintable FLASH *);
void screen_option_select(TScreenItem FLASH *);
void screen_option_item_print(TPrintable FLASH * printable);

#endif
