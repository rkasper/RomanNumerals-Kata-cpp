#ifndef ROMAN_NUMERALS_CPP_ROMAN_H
#define ROMAN_NUMERALS_CPP_ROMAN_H

#include <string>

using namespace std;

class Roman {

public:
    static int convert(const string &roman);

    static int convert_single_digit(const string &roman);

    static bool is_valid_roman(const string &roman);
};


#endif //ROMAN_NUMERALS_CPP_ROMAN_H
