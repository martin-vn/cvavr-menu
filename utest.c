#include "utest.h"

#include "stdio.h"

#define MAX_FAILURES 16

typedef struct {
    const char * message;
    const char * function;
    const char * filename;
    unsigned int line;
} TTestFailure;

typedef struct {
    unsigned int executed;
    unsigned int failed;
    TTestFailure failures[MAX_FAILURES];
} TTestSummary;

static TTestSummary test_summary;

void utest_failure(
    const char * message,
    const char * filename,
    const char * function,
    unsigned int line
);

void utest_init() {
    test_summary.executed = 0;
    test_summary.failed = 0;
}

void utest_executed() {
    ++test_summary.executed;
}

void utest_assert(
    int condition,
    const char * message,
    const char * filename,
    const char * function,
    unsigned int line
) {
    utest_executed();
    if (condition != 0) {
        utest_failure(message, filename, function, line);
    }
}

void utest_failure(
    const char * message,
    const char * filename,
    const char * function,
    unsigned int line
) {
    TTestFailure *failure;

    if (test_summary.failed >= MAX_FAILURES) {
        return;
    }

    failure = &test_summary.failures[test_summary.failed];
    failure->message = message;
    failure->filename = filename;
    failure->function = function;
    failure->line = line;

    ++test_summary.failed;
}

void utest_print_summary() {
    int failureIndex;
    TTestFailure *failure;

    printf("Executed %d assert(s).\n", test_summary.executed);
    if (test_summary.failed > 0) {
        printf("%d failure(s) detected.\n", test_summary.failed);
        for (
            failureIndex = 0;
            failureIndex < test_summary.failed;
            ++failureIndex
        ) {
            failure = &test_summary.failures[failureIndex];
            printf(
                "%s - %s:%d -> %s\n",
                failure->function,
                failure->filename,
                failure->line,
                failure->message
            );
        }
    }
}
