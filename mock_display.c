#include "mock_display.h"

void mock_display_flush();
void mock_display_cursor_show();
void mock_display_cursor_hide();
void mock_display_cursor_to(uint8_t x, uint8_t y);

char mock_rows[DISPLAY_WIDTH * DISPLAY_HEIGHT];
uint8_t mock_display_flushed = 0;
uint8_t mock_display_cursor = MOCK_CURSOR_OFF;
uint8_t mock_display_cursor_x = 0;
uint8_t mock_display_cursor_y = 0;

TDisplayConfig FLASH mock_display_config = {
    {DISPLAY_WIDTH, DISPLAY_HEIGHT},
    mock_display_flush,
    mock_display_cursor_show,
    mock_display_cursor_hide,
    mock_display_cursor_to
};

void init_test_display() {
    display_init(&mock_display_config, mock_rows);
}

void mock_display_flush() {
    mock_display_flushed = 1;
}

void mock_display_cursor_show() {
    mock_display_cursor = MOCK_CURSOR_ON;
}

void mock_display_cursor_hide() {
    mock_display_cursor = MOCK_CURSOR_OFF;
}

void mock_display_cursor_to(uint8_t x, uint8_t y) {
    mock_display_cursor_x = x;
    mock_display_cursor_y = y;
}
