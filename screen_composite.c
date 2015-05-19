#include "screen_composite.h"

void screen_composite_print(TPrintable FLASH * screen_item) {
    TScreenComposite FLASH * composite = (TScreenComposite FLASH *) screen_item;
    PRINTABLE_PRINT(composite->elements[0]);
    PRINTABLE_PRINT(composite->elements[1]);
}
