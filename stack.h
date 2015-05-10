#ifndef STACK_H
#define STACK_H

#include "types.h"

#define STACK(name, size) \
    void FLASH * name##_items[size] = {0}; \
    TStack name = { \
        size, \
        0, \
        name##_items \
    };

typedef FLASH struct {
    uint8_t size;
    uint8_t top;
    void FLASH ** items;
} TStack;

void stack_reset(TStack * stack);
int stack_push(TStack * stack, void FLASH * item);
void FLASH * stack_pop(TStack * stack);

#endif
