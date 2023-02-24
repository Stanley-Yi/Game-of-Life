/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "catch.hpp"
#include "golCatchMain.h"
#include "GridStatus.h"
#include <iostream>
#include <vector>
#include <memory>


TEST_CASE( "Test storing the grid", "[task 1.1]" ) {

  REQUIRE_NOTHROW( game::GridStatus(5, 5) );

  game::GridStatus grid_1(5, 5);
  REQUIRE( grid_1(4, 4) == '-' );
  REQUIRE_THROWS( grid_1(5, 5) );  // out of range

}

TEST_CASE( "Test initialising the grid at random", "[task 1.2]" ) {
  // std::vector<int> a;
  // REQUIRE( a.size() == 0 );
}

TEST_CASE( "Test initialising the grid from a file", "[task 1.3]") {
  // game::GridStatus a(1, 2);
  // a.setStatus('o', 0, 0);
  // REQUIRE( a.getStatus(0, 0) == 'o' );
}
