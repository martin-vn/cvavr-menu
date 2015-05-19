#include "mock_display.h"

#include "screen.h"
#include "screen_monitor.h"

uint16_t monitor_value_value = 100;

uint16_t monitor_value_current() {
    return monitor_value_value;
}

CONSOLE(monitor_screen_console, 0, 0, 0, 0);

SCREEN_MONITOR(
    monitor_value,
    SCREEN_TEXT("MONITOR:", 0),
    SCREEN_MONITOR_VAR(
        monitor_value_current,
        4,
        2,
        9
    )
);

SCREEN(
    monitor_screen,
    "",
    monitor_screen_console,
    SCREEN_ITEM(monitor_value)
);

void test_monitor_display() {
    init_test_display();
    console_init();
    screen_init();
    screen_push(&monitor_screen);

    ASSERT_DISPLAY(
        "MONITOR:  1.00  ",
        "                "
    );
}

void screen_monitor_test_suite() {
    test_monitor_display();
}
