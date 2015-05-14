void val_to_str(unsigned int value, char digits, char decimals, char * str) {
    signed char pos = digits - 1;
    signed char span = digits;

    if (decimals > 0) {
        str[digits - decimals] = '.';
        span = digits - decimals - 1;
        ++pos;
    }

    do {
        str[pos] = (value % 10) + 48;
        value = value / 10;
        -- pos;
        if (decimals > 0 && (digits - decimals) == pos) {
            --pos;
        }
    } while (value || pos >= span);

    while(pos >= 0) {
        str[pos] = ' ';
        --pos;
    }
}
