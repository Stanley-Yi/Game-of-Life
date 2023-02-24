#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "GridStatus.h"
#include <stdexcept>


TEST_CASE( "Check conversion to doubles", "[ex1]" ) {
    // We use the approx feature here because floating point arithmetic is not exact
    // epsilon is the amount of error that we allow
    // GridStatus grid(3, 3);
    // grid.setStatus('o', 0, 0);
    // REQUIRE(grid(0, 0) == 'o');

    // REQUIRE(GridStatus(2, 3).toDouble() == Approx(2.0/3.0).epsilon(1e-10));

    // REQUIRE(Fraction(0, 15).toDouble() == Approx(0).epsilon(1e-10));

    // REQUIRE(Fraction(2, 4).toDouble() == Approx(0.5).epsilon(1e-10));
}

// TEST_CASE( "Check conversion to doubles", "[ex1]" ) {
//     // We use the approx feature here because floating point arithmetic is not exact
//     // epsilon is the amount of error that we allow 
//     REQUIRE(Fraction(1, 2).toDouble() == Approx(0.5).epsilon(1e-10));

//     REQUIRE(Fraction(2, 3).toDouble() == Approx(2.0/3.0).epsilon(1e-10));

//     REQUIRE(Fraction(0, 15).toDouble() == Approx(0).epsilon(1e-10));

//     REQUIRE(Fraction(2, 4).toDouble() == Approx(0.5).epsilon(1e-10));
// }

// TEST_CASE( "Check conversion to strings", "[ex1]")
// {
//     REQUIRE(Fraction(1, 2).toString() == "1/2");

//     REQUIRE(Fraction(2, 3).toString() == "2/3");

//     REQUIRE(Fraction(7, 9).toString() == "7/9");

//     REQUIRE(Fraction(0, 5).toString() == "0");

//     REQUIRE(Fraction(0, 12).toString() == "0");
// }

// TEST_CASE( "Check multiples", "[ex1]")
// {
//     REQUIRE(Fraction(1, 2).multiply(2).toDouble() == Approx(1.0).epsilon(1e-10));

//     REQUIRE(Fraction(2, 3).multiply(0).toDouble() == 0.0);

//     REQUIRE(Fraction(1, 4).multiply(1).toDouble() == Approx(1.0/4.0).epsilon(1e-10));

//     REQUIRE(Fraction(1, 3).multiply(2).toString() == "2/3");
    
//     REQUIRE(Fraction(1, 3).multiply(1).toString() == "1/3");
// }

// TEST_CASE( "Check reciprocals", "[ex1]")
// {
//     REQUIRE(Fraction(1, 3).reciprocal().toString() == "3/1");

//     REQUIRE(Fraction(2, 7).reciprocal().toString() == "7/2");
// }

// TEST_CASE( "Check constructor exceptions", "[ex2]")
// {
//     CHECK_THROWS(Fraction(2, 0));
//     CHECK_THROWS(Fraction(0, 0));
//     CHECK_NOTHROW(Fraction(0, 1));
//     CHECK_NOTHROW(Fraction(5, 17));
// }