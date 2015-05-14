#include "mock_display.h"
#include "console.h"
#include "screen.h"
#include "screen_option.h"

static CONSOLE(
    screen_actions,
    screen_cursor_up,
    screen_cursor_down,
    screen_select,
    screen_alt_action
);

static uint16_t test_value_value = 0;

uint16_t test_option_current() {
    return test_value_value;
}

void test_option_next() {
    ++test_value_value;
    if (test_value_value > 2) test_value_value = 0;
}

static SCREEN_OPTION(
    test_option,
    SCREEN_TEXT("Option:", 0),
    SCREEN_OPTION_SETTINGS(test_option_current, test_option_next),
    SCREEN_OPTION_ITEM_LIST(
        SCREEN_OPTION_ITEM("NULL", 0)
        SCREEN_OPTION_ITEM("YES", 1)
        SCREEN_OPTION_ITEM("NO", 2)
    ),
    8
);

static SCREEN(
    option_screen,
    "",
    screen_actions,
    SCREEN_ITEM(test_option)
);

void test_option_display() {
    test_value_value = 0;

    init_test_display();
    console_init();
    screen_init();
    screen_push(&option_screen);

    ASSERT_DISPLAY(
        "Option: NULL    ",
        "                "
    );
}

void test_option_next_value() {
    test_value_value = 0;

    init_test_display();
    console_init();
    screen_init();
    screen_push(&option_screen);

    screen_select();

    ASSERT_DISPLAY(
        "Option: YES     ",
        "                "
    );

    screen_select();

    ASSERT_DISPLAY(
        "Option: NO      ",
        "                "
    );

    screen_select();

    ASSERT_DISPLAY(
        "Option: NULL    ",
        "                "
    );
}

void screen_option_test_suite() {
    test_option_display();
    test_option_next_value();
}
