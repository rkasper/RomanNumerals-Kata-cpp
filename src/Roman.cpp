#include "Roman.h"

int Roman::convert(const string& roman) {
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
