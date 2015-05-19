#include "screen_monitor.h"

#include "display.h"
#include "utils.h"

void screen_monitor_print_var(TPrintable FLASH * screen_item) {
    TScreenMonitor FLASH * monitor_var =
            (TScreenMonitor FLASH *) screen_item;
    char value_str[6] = {0};

    val_to_str(
        monitor_var->current(),
        monitor_var->digits,
        monitor_var->decimals,
        value_str
    );
    display_print_str(value_str, monitor_var->pos);
}

void screen_monitor_select(TScreenItem FLASH * screen_item) {}
