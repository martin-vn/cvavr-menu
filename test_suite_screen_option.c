#include "mock_display.h"
#include "console.h"
#include "screen.h"
#include "screen_option.h"
#include "value_factory.h"

static CONSOLE(
    screen_actions,
    screen_cursor_up,
    screen_cursor_down,
    screen_select,
    screen_alt_action
);

OPTION_DEFINE(test_option_value, 3);

SCREEN_OPTION(
    test_option,
    SCREEN_TEXT("Option:", 0),
    OPTION_SETTINGS(test_option_value),
    SCREEN_OPTION_ITEM_LIST(
        SCREEN_OPTION_ITEM(0, "NULL")
        SCREEN_OPTION_ITEM(1, "YES")
        SCREEN_OPTION_ITEM(2, "NO")
    ),
    8
);

SCREEN(
    option_screen,
    "",
    screen_actions,
    SCREEN_ITEM(test_option)
);

void test_option_display() {
    test_option_value = 0;

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
    test_option_value = 0;

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
