#include "stack.h"

void stack_reset(TStack * stack) {
    stack->top = 0;
}

int stack_push(TStack * stack, void FLASH * item) {
    if (stack->top == stack->size) return -1;
    stack->items[stack->top] = item;
    ++stack->top;
    return 0;
}

void FLASH * stack_pop(TStack * stack) {
    if (stack->top == 0) return 0;
    --stack->top;
    return stack->items[stack->top];
}
