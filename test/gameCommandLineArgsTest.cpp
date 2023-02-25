/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "catch.hpp"
#include "gameCatchMain.h"
#include "GridStatus.h"
#include <iostream>

TEST_CASE( "My first test", "[init]" ) {

  int expectedNumberOfArgs = 2;
  if (game::argc != expectedNumberOfArgs)
  {
    std::cerr << "fsdfad " << (std::string) game::argv[1] << std::endl;
    REQUIRE( game::argc == expectedNumberOfArgs);
  }
  REQUIRE(true);

  // game::GridStatus grid_1(game::argv[0]);
  // REQUIRE( grid_1.getSize().at(0) == 10 );
  // REQUIRE( grid_1.getSize().at(1) == 10 );
}
