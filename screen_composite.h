#ifndef SCREEN_COMPOSITE_H
#define SCREEN_COMPOSITE_H

#include "screen.h"

#define SCREEN_COMPOSITE(name, element1, element2, select) \
    TScreenComposite FLASH name = { \
        SCREEN_ITEM_INIT(screen_composite_print, select), \
        { \
            (TPrintable FLASH *) &element1, \
            (TPrintable FLASH *) &element2 \
        } \
    }

typedef struct {
    TScreenItem _base;
    TPrintable FLASH * elements[];
} TScreenComposite;

void screen_composite_print(TPrintable FLASH * screen_item);

#endif
