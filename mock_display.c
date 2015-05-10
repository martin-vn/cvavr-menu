#include "mock_display.h"

char mock_rows[DISPLAY_WIDTH * DISPLAY_HEIGHT];

void init_test_display() {
    display_init(DISPLAY_WIDTH, DISPLAY_HEIGHT, mock_rows);
}
