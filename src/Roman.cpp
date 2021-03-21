#include <regex.h>
#include "Roman.h"

int Roman::convert(const string& roman) {
    if (is_valid_roman(roman)) {
        if (roman.length() == 1) {
            return convert_single_digit(roman);
        } else {
            int first = convert(roman.substr(0, 1));
            int second = convert(roman.substr(1, 1));
            int rest = convert(roman.substr(1));
            if (first >= second) {  // addition
                return first + rest;
            } else { // subtraction
                return rest - first;
            }
        }
    } else {
        return -1;
    }
}

int Roman::convert_single_digit(const string &roman) {
    if ("I" == roman) {
        return 1;
    } else if ("V" == roman) {
        return 5;
    } else if ("X" == roman) {
        return 10;
    } else if ("L" == roman) {
        return 50;
    } else if ("C" == roman) {
        return 100;
    } else if ("D" == roman) {
        return 500;
    } else { // "M"
        return 1000;
    }
}

bool Roman::is_valid_roman(const string &roman) {
    if (roman.length() == 0) {
        return false;
    } else {
        regex_t start_state{};

        // Regex for valid Roman numerals is from
        // https://stackoverflow.com/questions/267399/how-do-you-match-only-valid-roman-numerals-with-a-regular-expression
        // TODO Adjust this regex so it requires at least one digit
        const char *pattern = "^M{0,4}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$";

        if (regcomp(&start_state, pattern, REG_EXTENDED)) {
            printf("bad pattern: '%s'\n", pattern);
            return false;
        }

        return !regexec(&start_state, roman.c_str(), 0, nullptr, 0);
    }
}
