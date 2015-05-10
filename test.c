#include "utest.h"

void console_test_suite();
void display_test_suite();
void screen_test_suite();
void screen_action_test_suite();

int main() {
    utest_init();

    console_test_suite();
    display_test_suite();
    screen_test_suite();
    screen_action_test_suite();
    
    TEST_SUMMARY();
    return 0;
}
 
