#include "mock_display.h"

#include "screen_action.h"

void test_action_command() {
}

static CONSOLE(
    screen_actions,
    screen_cursor_up,
    screen_cursor_down,
    screen_select,
    screen_alt_action
);

static SCREEN_ACTION(
    test_action,
    test_action_command,
    SCREEN_TEXT("DO SMTH", 2)
);

static SCREEN(
    main_screen,
    ">>",
    screen_actions,
    SCREEN_ITEM(test_action)
);

void test_action_display() {
    init_test_display();

    screen_init();
    screen_push(&main_screen);
    ASSERT_DISPLAY(
        ">>DO SMTH       ",
        "                "
    );
}

void screen_action_test_suite() {
    test_action_display();
}
