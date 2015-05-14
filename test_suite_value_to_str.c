#include "utest.h"
#include "utils.h"

void value_to_str_test_suite() {
    char str[6] = {0};
    val_to_str(0, 1, 0, (char *) &str);
    ASSERT_STR_EQUALS("0", str);

    val_to_str(1, 1, 0, (char *) &str);
    ASSERT_STR_EQUALS("1", str);

    val_to_str(1, 2, 0, (char *) &str);
    ASSERT_STR_EQUALS(" 1", str);

    val_to_str(10, 2, 1, (char *) &str);
    ASSERT_STR_EQUALS("1.0", str);

    val_to_str(1, 2, 1, (char *) &str);
    ASSERT_STR_EQUALS("0.1", str);

    val_to_str(10, 3, 1, (char *) &str);
    ASSERT_STR_EQUALS(" 1.0", str);

    val_to_str(10, 3, 2, (char *) &str);
    ASSERT_STR_EQUALS("0.10", str);

    val_to_str(110, 3, 2, (char *) &str);
    ASSERT_STR_EQUALS("1.10", str);

    val_to_str(12, 5, 0, (char *) &str);
    ASSERT_STR_EQUALS("   12", str);

    val_to_str(1234, 6, 4, (char *) &str);
    ASSERT_STR_EQUALS(" 0.1234", str);
}
