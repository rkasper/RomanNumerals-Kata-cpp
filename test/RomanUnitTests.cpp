#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "../src/Roman.h"

TEST_CASE("The Catch test framework works properly")
{
    REQUIRE(42 == 6 * 7);
}

// 1) Convert single-digit Roman numerals
// As an elementary school teacher, I want to convert base Roman numerals to Arabic (I=1, V=5, X=10, L=50, C=100,
// D=500, M=1000)
TEST_CASE("Convert single-digit Roman numerals")
{
    REQUIRE(1 == Roman::convert("I"));
    REQUIRE(5 == Roman::convert("V"));
    REQUIRE(10 == Roman::convert("X"));
    REQUIRE(50 == Roman::convert("L"));
    REQUIRE(100 == Roman::convert("C"));
    REQUIRE(500 == Roman::convert("D"));
    REQUIRE(1000 == Roman::convert("M"));
}

// 2) Add Roman numerals
// As an elementary school teacher, I want to add Roman numerals (e.g., II, III, VI, VII, VIII, XI, XII, XIII, LX)
TEST_CASE("Add Roman numerals")
{
    REQUIRE(2 == Roman::convert("II"));
    REQUIRE(3 == Roman::convert("III"));
    REQUIRE(6 == Roman::convert("VI"));
    REQUIRE(7 == Roman::convert("VII"));
    REQUIRE(8 == Roman::convert("VIII"));
    REQUIRE(11 == Roman::convert("XI"));
    REQUIRE(12 == Roman::convert("XII"));
    REQUIRE(13 == Roman::convert("XIII"));
    REQUIRE(60 == Roman::convert("LX"));
    REQUIRE(3888 == Roman::convert("MMMDCCCLXXXVIII"));
}

// 3) Subtract Roman numerals
// As an elementary school teacher, I want to subtract Roman numerals (e.g., IV, IX, XC, XL, CD)
TEST_CASE("Subtract Roman numerals")
{
    REQUIRE(4 == Roman::convert("IV"));
    REQUIRE(9 == Roman::convert("IX"));
    REQUIRE(90 == Roman::convert("XC"));
    REQUIRE(40 == Roman::convert("XL"));
    REQUIRE(400 == Roman::convert("CD"));
}

// 4) Add and subtract Roman numerals in the same number
// As an elementary school teacher, I want to comingle addition and subtraction of Roman numerals (e.g., XLVI=46,
// XCVIII=98, CDXLVI=446, MCMXCVIII=1998)
TEST_CASE("Add and subtract Roman numerals in the same number")
{
    REQUIRE(46 == Roman::convert("XLVI"));
    REQUIRE(98 == Roman::convert("XCVIII"));
    REQUIRE(446 == Roman::convert("CDXLVI"));
    REQUIRE(1998 == Roman::convert("MCMXCVIII"));
}

// 5) Handle invalid inputs
// As an elementary school teacher, I want to handle invalid input strings (e.g., A, B, E, F, G, H, “”)
TEST_CASE("Handle invalid inputs")
{
    // Non-Roman characters
    REQUIRE(-1 == Roman::convert("A"));
    REQUIRE(-1 == Roman::convert("B"));
    REQUIRE(-1 == Roman::convert("E"));
    REQUIRE(-1 == Roman::convert("F"));
    REQUIRE(-1 == Roman::convert("G"));
    REQUIRE(-1 == Roman::convert("H"));

    // Empty string
    REQUIRE(-1 == Roman::convert(""));

    // Invalid sequence of valid digits
    REQUIRE(-1 == Roman::convert("IIV"));
    REQUIRE(-1 == Roman::convert("VIX"));
    REQUIRE(-1 == Roman::convert("XXC"));
}
