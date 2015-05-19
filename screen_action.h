#ifndef SCREEN_ACTION_H
#define SCREEN_ACTION_H

#include "types.h"
#include "screen.h"
#include "screen_text.h"

typedef struct {
    TScreenItem _base;
    TPrintable FLASH * elements[];
} TScreenAction;

#define SCREEN_ACTION(name, command, text) \
    TScreenText FLASH name##_text = text; \
    TScreenAction FLASH name = { \
        SCREEN_ITEM_INIT(screen_action_print, command), \
        { \
            (TPrintable FLASH *) &name##_text \
        } \
    }

void screen_action_print(TPrintable FLASH * screen_item);

#endif
