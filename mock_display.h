#ifndef MOCK_DISPLAY_H
#define MOCK_DISPLAY_H

#include "utest.h"
#include "display.h"

#define DISPLAY_WIDTH 16
#define DISPLAY_HEIGHT 2

extern char mock_rows[DISPLAY_WIDTH * DISPLAY_HEIGHT];

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

#endif
