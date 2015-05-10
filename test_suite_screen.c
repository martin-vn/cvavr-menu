#include "mock_display.h"

#include "console.h"
#include "screen.h"
#include "screen_action.h"

#define SCREEN_NULL_ITEM 0,

static CONSOLE(
    screen_actions,
    screen_cursor_up,
    screen_cursor_down,
    screen_select,
    screen_alt_action
);

void test_display_empty_screen() {
    static SCREEN(
        screen,
        "",
        screen_actions,
        SCREEN_NULL_ITEM
    );

    init_test_display();

    screen_push(&screen);
    ASSERT_DISPLAY(
        "                ",
        "                "
    );
}

static SCREEN_ACTION(
    test_action_1,
    0,
    SCREEN_TEXT("ITEM1", 2)
);

static SCREEN_ACTION(
    test_action_2,
    0,
    SCREEN_TEXT("ITEM2", 2)
);

static SCREEN_ACTION(
    test_action_3,
    0,
    SCREEN_TEXT("ITEM3", 2)
);

void test_display_screen() {
    static SCREEN(
        screen,
        ">>>>>>>><<<<<<<<",
        screen_actions,
        SCREEN_ITEM(test_action_1)
    );

    init_test_display();
    screen_init();

    screen_push(&screen);
    ASSERT_DISPLAY(
        ">>ITEM1><<<<<<<<",
        "                "
    );
}

void test_screen_scroll() {
    static SCREEN(
        screen,
        ">>",
        screen_actions,
        SCREEN_ITEM(test_action_1)
        SCREEN_ITEM(test_action_2)
        SCREEN_ITEM(test_action_3)
    );

    init_test_display();
    screen_init();

    screen_push(&screen);
    ASSERT_DISPLAY(
        ">>ITEM1         ",
        "  ITEM2         "
    );

    console_down();
    ASSERT_DISPLAY(
        "  ITEM1         ",
        ">>ITEM2         "
    );

    console_down();
    ASSERT_DISPLAY(
        "  ITEM2         ",
        ">>ITEM3         "
    );

    console_down();
    ASSERT_DISPLAY(
        "  ITEM2         ",
        ">>ITEM3         "
    );

    console_up();
    ASSERT_DISPLAY(
        ">>ITEM2         ",
        "  ITEM3         "
    );

    console_up();
    ASSERT_DISPLAY(
        ">>ITEM1         ",
        "  ITEM2         "
    );

    console_up();
    ASSERT_DISPLAY(
        ">>ITEM1         ",
        "  ITEM2         "
    );
}

void test_screen_push_pop() {
    static SCREEN(
        screen_1,
        ">>",
        screen_actions,
        SCREEN_ITEM(test_action_1)
        SCREEN_ITEM(test_action_2)
    );

    static SCREEN(
        screen_2,
        ">>",
        screen_actions,
        SCREEN_ITEM(test_action_3)
        SCREEN_ITEM(test_action_1)
    );

    init_test_display();
    screen_init();

    screen_push(&screen_1);
    ASSERT_DISPLAY(
        ">>ITEM1         ",
        "  ITEM2         "
    );

    screen_push(&screen_2);
    ASSERT_DISPLAY(
        ">>ITEM3         ",
        "  ITEM1         "
    );

    screen_pop();
    ASSERT_DISPLAY(
        ">>ITEM1         ",
        "  ITEM2         "
    );

    display_clear();
    screen_pop();
    screen_display();
    ASSERT_DISPLAY(
        ">>ITEM1         ",
        "  ITEM2         "
    );
}

void screen_test_suite() {
    test_display_empty_screen();
    test_display_screen();
    test_screen_scroll();
    test_screen_push_pop();
}
