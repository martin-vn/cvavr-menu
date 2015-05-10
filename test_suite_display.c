#include "mock_display.h"

void test_empty_display() {
    init_test_display();
    ASSERT_DISPLAY(
        "                ",
        "                "
    );
}

void test_first_row_print() {
    init_test_display();
    display_print_str("test", 0);
    ASSERT_DISPLAY(
        "test            ",
        "                "
    );

    display_print_str("test", 5);
    ASSERT_DISPLAY(
        "test test       ",
        "                "
    );
}

void test_second_row_print() {
    init_test_display();
    display_goto_row(1);
    display_print_str("test", 0);
    ASSERT_DISPLAY(
        "                ",
        "test            "
    );

    display_print_str("test", 5);
    ASSERT_DISPLAY(
        "                ",
        "test test       "
    );
}

void test_const_string() {
    init_test_display();
    display_goto_row(0);
    display_print_const_str("test", 0);
    ASSERT_DISPLAY(
        "test            ",
        "                "
    );
}

void display_test_suite() {
    test_empty_display();
    test_first_row_print();
    test_second_row_print();
    test_const_string();
}
