#ifndef UTEST_H
#define UTEST_H

#include "string.h"
#include "stdio.h"

void utest_init();
void utest_assert(
    int condition,
    const char * message,
    const char * filename,
    const char * function,
    unsigned int line
);

void utest_print_summary();

#define ASSERT_INT_EQUALS(expected, actual) \
    ASSERT_CONDITION((expected) != (actual), expected, actual)

#define ASSERT_STR_EQUALS(expected, actual) \
    ASSERT_CONDITION(strcmp((expected), (actual)), expected, actual)

#define ASSERT_STRN_EQUALS(expected, actual, n) \
    ASSERT_CONDITION(strncmp((expected), (actual), n), expected, actual)

#define ASSERT_FSTR_EQUALS(expected, actual) \
    ASSERT_CONDITION(strcmp((expected), (actual)), expected, actual)

#define ASSERT_CONDITION(condition, expected, actual) \
    utest_assert(condition, "Failed to assert that " #actual " equals " #expected, __FILE__, __FUNCTION__, __LINE__)

#define TEST_SUMMARY() utest_print_summary()

#endif
