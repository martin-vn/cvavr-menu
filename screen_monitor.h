#ifndef SCREEN_MONITOR_H
#define SCREEN_MONITOR_H

#include "screen.h"
#include "screen_composite.h"
#include "screen_text.h"

#define SCREEN_MONITOR(name, caption, monitor) \
    TScreenText FLASH _##name##_caption = caption; \
    TScreenMonitor FLASH _##name##_monitor = monitor; \
    SCREEN_COMPOSITE( \
        name, \
        _##name##_caption, \
        _##name##_monitor, \
        screen_monitor_select \
    )

#define SCREEN_MONITOR_VAR(current, digits, decimals, pos) { \
    PRINTABLE_INIT(screen_monitor_print_var), \
    current, \
    digits, \
    decimals, \
    pos \
}

typedef uint16_t (*TScreenMonitorGetter)();

typedef struct {
    TPrintable _base;
    TScreenMonitorGetter current;
    uint16_t digits;
    uint16_t decimals;
    uint16_t pos;
} TScreenMonitor;

void screen_monitor_print(TPrintable FLASH * screen_item);
void screen_monitor_print_var(TPrintable FLASH * screen_item);
void screen_monitor_select(TScreenItem FLASH * screen_item);

#endif
