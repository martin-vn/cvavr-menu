#include "types.h"

#define VALUE_DECLARE(name) \
    uint16_t name##_current(); \
    void name##_change(uint16_t value); \
    uint16_t name##_min(); \
    uint16_t name##_max();

#define VALUE_DEFINE(name, min, max) \
    uint16_t name; \
    uint16_t name##_current() {return name;} \
    void name##_change(uint16_t value) {name = value;} \
    uint16_t name##_min() {return min;} \
    uint16_t name##_max() {return max;}

#define VALUE_SETTINGS(name) {name##_current, name##_change, name##_min, name##_max}

#define OPTION_DECLARE(name) \
    uint16_t name##_current(); \
    void name##_next();

#define OPTION_DEFINE(name, size) \
    uint16_t name; \
    uint16_t name##_current() {return name;} \
    void name##_next() {if (++name >= size) name = 0;}

#define OPTION_SETTINGS(name) {name##_current, name##_next}

#define ACTION_DEFINE(name, captionm, pos) \
    void name##_action(TScreenItem FLASH * screen_item); \
    SCREEN_ACTION( \
        name, \
        name##_action, \
        SCREEN_TEXT(caption, pos) \
    ); \
    void name##_action(TScreenItem FLASH * screen_item)
