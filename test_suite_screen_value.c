#include "mock_display.h"

#include "screen.h"
#include "screen_value.h"

static uint16_t test_value_value = 10;

uint16_t test_value_get() {
    return test_value_value;
}

void test_value_set(uint16_t value) {
    test_value_value = value;
}

uint16_t test_value_min() {
    return 10;
}

uint16_t test_value_max() {
    return 900;
}

static SCREEN_VALUE(
    test_value,
    SCREEN_TEXT("VALUE:", 0),
    SCREEN_VAR(
        4,
        1,
        SCREEN_VAR_SETTINGS(
            test_value_get,
            test_value_set,
            test_value_min,
            test_value_max
        ),
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
    console_up();
    ASSERT_DISPLAY(
        "VALUE:    2.2   ",
        "                "
    );

    console_select();
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
