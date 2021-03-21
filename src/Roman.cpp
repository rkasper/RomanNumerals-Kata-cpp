#include "Roman.h"

int Roman::convert(const string roman) {
    if (roman.length() > 1) {
        return convert(roman.substr(0, 1)) + convert(roman.substr(1));
    }

    // else
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
    } else {
        return 1000;
    }
}
