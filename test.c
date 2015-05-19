#include "utest.h"

void console_test_suite();
void display_test_suite();
void screen_test_suite();
void screen_action_test_suite();

void value_to_str_test_suite();
void screen_value_test_suit();
void screen_option_test_suite();
void screen_monitor_test_suite();

int main() {
    utest_init();

    console_test_suite();
    display_test_suite();
    screen_test_suite();
    screen_action_test_suite();

    value_to_str_test_suite();
    screen_value_test_suit();
    screen_option_test_suite();

    screen_monitor_test_suite();

    TEST_SUMMARY();
    return 0;
}
