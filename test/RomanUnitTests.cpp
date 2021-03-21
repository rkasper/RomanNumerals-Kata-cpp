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

// ## 2) Add Roman numerals
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

// ## 3) Subtract Roman numerals
// As an elementary school teacher, I want to subtract Roman numerals (e.g., IV, IX, XC, XL, CD)
TEST_CASE("Subtract Roman numerals")
{
    REQUIRE(4 == Roman::convert("IV"));
    REQUIRE(9 == Roman::convert("IX"));
    REQUIRE(90 == Roman::convert("XC"));
    REQUIRE(40 == Roman::convert("XL"));
    REQUIRE(400 == Roman::convert("CD"));
}