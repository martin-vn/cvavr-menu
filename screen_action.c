#include "screen_action.h"

void screen_action_print(TPrintable FLASH * screen_item) {
    TScreenAction FLASH * action = (TScreenAction FLASH *) screen_item;
    PRINTABLE_PRINT(action->elements[0]);
}
