#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"

TEST_CASE("The Catch test framework works properly")
{
    REQUIRE(42 == 6 * 7);
}