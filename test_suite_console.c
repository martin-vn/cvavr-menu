#include "utest.h"
#include "console.h"

static char * last_action = 0;

#define TEST_CONSOLE_ACTION(name, action) void con_##name##_##action() { \
    last_action = #name"_"#action; \
}

#define TEST_CONSOLE(name) \
    TEST_CONSOLE_ACTION(name, up) \
    TEST_CONSOLE_ACTION(name, down) \
    TEST_CONSOLE_ACTION(name, select) \
    TEST_CONSOLE_ACTION(name, alt) \
    CONSOLE( \
        name, \
        con_##name##_up, \
        con_##name##_down, \
        con_##name##_select, \
        con_##name##_alt \
    )

TEST_CONSOLE(console_1);
TEST_CONSOLE(console_2);
TEST_CONSOLE(console_3);
TEST_CONSOLE(console_4);

void test_no_console() {
    console_up();
    console_down();
    console_select();
    console_alt();
}

void test_console_actions() {
    last_action = "";
    console_init();
    console_push(&console_1);

    console_up();
    ASSERT_STR_EQUALS("console_1_up", last_action);

    console_down();
    ASSERT_STR_EQUALS("console_1_down", last_action);

    console_select();
    ASSERT_STR_EQUALS("console_1_select", last_action);

    console_alt();
    ASSERT_STR_EQUALS("console_1_alt", last_action);
}

void test_console_pop_on_one() {
    last_action = "";
    console_init();
    console_push(&console_1);
    console_pop();

    console_up();
    ASSERT_STR_EQUALS("console_1_up", last_action);
}

void test_console_push() {
    last_action = "";
    console_init();
    console_push(&console_1);

    console_push(&console_2);
    console_up();
    ASSERT_STR_EQUALS("console_2_up", last_action);

    console_push(&console_3);
    console_up();
    ASSERT_STR_EQUALS("console_3_up", last_action);

    console_push(&console_4);
    console_up();
    ASSERT_STR_EQUALS("console_4_up", last_action);

    console_push(&console_1);
    console_up();
    ASSERT_STR_EQUALS("console_4_up", last_action);

    console_pop();
    console_up();
    ASSERT_STR_EQUALS("console_3_up", last_action);

    console_pop();
    console_up();
    ASSERT_STR_EQUALS("console_2_up", last_action);

    console_push(&console_4);
    console_up();
    ASSERT_STR_EQUALS("console_4_up", last_action);
}

void console_test_suite() {
    test_no_console();
    test_console_actions();
    test_console_pop_on_one();
    test_console_push();
}
