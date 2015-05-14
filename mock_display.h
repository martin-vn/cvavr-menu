#ifndef MOCK_DISPLAY_H
#define MOCK_DISPLAY_H

#include "utest.h"
#include "display.h"

#define DISPLAY_WIDTH 16
#define DISPLAY_HEIGHT 2

#define MOCK_CURSOR_ON 1
#define MOCK_CURSOR_OFF 0

extern char mock_rows[DISPLAY_WIDTH * DISPLAY_HEIGHT];
extern uint8_t mock_display_flushed;
extern uint8_t mock_display_cursor;
extern uint8_t mock_display_cursor_x;
extern uint8_t mock_display_cursor_y;

void init_test_display();

#define ASSERT_DISPLAY(row1, row2) \
    ASSERT_STRN_EQUALS(row1, mock_rows, DISPLAY_WIDTH); \
    ASSERT_STRN_EQUALS(row2, &mock_rows[DISPLAY_WIDTH], DISPLAY_WIDTH)

#define ASSERT_DISPLAY_SHOW(row1, row2) \
    ASSERT_DISPLAY(row1, row2); \
    printf("+================+\n"); \
    printf(\
        "|%.*s|\n|%.*s|\n", \
        DISPLAY_WIDTH, (char *) mock_rows, \
        DISPLAY_WIDTH, (char *) &mock_rows[DISPLAY_WIDTH] \
    ); \
    printf("+================+\n\n")

#define ASSERT_DISPLAY_FLUSHED() ASSERT_INT_EQUALS(1, mock_display_flushed)
#define ASSERT_DISPLAY_CURSOR(state) ASSERT_INT_EQUALS(state, mock_display_cursor)
#define ASSERT_DISPLAY_CURSOR_AT(x, y) \
    ASSERT_INT_EQUALS(x, mock_display_cursor_x); \
    ASSERT_INT_EQUALS(y, mock_display_cursor_y)

#endif
