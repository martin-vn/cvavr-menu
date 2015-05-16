#include "mock_display.h"

#include "screen.h"
#include "screen_value.h"
#include "value_factory.h"

VALUE_DEFINE(test_value_value, 10, 900);

static SCREEN_VALUE(
    test_value,
    SCREEN_TEXT("VALUE:", 0),
    SCREEN_VAR(
        4,
        1,
        VALUE_SETTINGS(test_value_value),
        8
    )
);

static CONSOLE(
    screen_actions,
    screen_cursor_up,
    screen_cursor_down,
    screen_select,
    screen_alt_action
);

static SCREEN(
    value_screen,
    "",
    screen_actions,
    SCREEN_ITEM(test_value)
);

void test_value_print() {
    test_value_value = 10;

    init_test_display();
    screen_init();
    screen_push(&value_screen);

    ASSERT_DISPLAY(
        "VALUE:    1.0   ",
        "                "
    );
}

void test_value_increase() {
    test_value_value = 10;

    init_test_display();
    console_init();
    screen_init();
    screen_push(&value_screen);

    console_select();
    ASSERT_DISPLAY_CURSOR(MOCK_CURSOR_ON);
    ASSERT_DISPLAY_CURSOR_AT(12, 0);

    console_up();
    ASSERT_DISPLAY(
        "VALUE:    1.1   ",
        "                "
    );

    console_up();
    ASSERT_DISPLAY(
        "VALUE:    1.2   ",
        "                "
    );

    console_select();
    ASSERT_DISPLAY_CURSOR_AT(10, 0);

    console_up();
    ASSERT_DISPLAY(
        "VALUE:    2.2   ",
        "                "
    );

    console_select();
    ASSERT_DISPLAY_CURSOR_AT(9, 0);

    console_up();
    ASSERT_DISPLAY(
        "VALUE:   12.2   ",
        "                "
    );

    console_up();
    console_up();
    console_up();
    console_up();
    console_up();
    console_up();
    console_up();
    console_up();
    ASSERT_DISPLAY(
        "VALUE:   90.0   ",
        "                "
    );
}

void test_value_complete() {
    test_value_value = 10;

    init_test_display();
    console_init();
    screen_init();
    screen_push(&value_screen);

    console_select();
    console_up();

    console_select();
    console_up();

    console_select();
    console_up();

    ASSERT_DISPLAY(
        "VALUE:   12.1   ",
        "                "
    );

    console_select();
    ASSERT_DISPLAY_CURSOR(MOCK_CURSOR_OFF);

    console_up();

    ASSERT_DISPLAY(
        "VALUE:   12.1   ",
        "                "
    );
}

void test_value_decrease() {
    test_value_value = 200;

    init_test_display();
    console_init();
    screen_init();
    screen_push(&value_screen);

    console_select();
    console_down();
    ASSERT_DISPLAY(
        "VALUE:   19.9   ",
        "                "
    );

    console_select();
    console_down();
    ASSERT_DISPLAY(
        "VALUE:   18.9   ",
        "                "
    );

    console_select();
    console_down();
    ASSERT_DISPLAY(
        "VALUE:    8.9   ",
        "                "
    );

    console_down();
    ASSERT_DISPLAY(
        "VALUE:    1.0   ",
        "                "
    );
}

void test_value_exit() {
    test_value_value = 10;

    init_test_display();
    console_init();
    screen_init();
    screen_push(&value_screen);

    console_select();
    console_up();

    ASSERT_DISPLAY(
        "VALUE:    1.1   ",
        "                "
    );

    console_alt();
    console_up();

    ASSERT_DISPLAY(
        "VALUE:    1.1   ",
        "                "
    );
}

void screen_value_test_suit() {
    test_value_print();
    test_value_increase();
    test_value_decrease();
    test_value_complete();
    test_value_exit();
}
