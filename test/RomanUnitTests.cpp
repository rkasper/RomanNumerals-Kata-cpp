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
