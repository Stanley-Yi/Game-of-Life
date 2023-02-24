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
#include <fstream>
#include <vector>
#include <memory>


TEST_CASE( "Test storing the grid", "[task 1.1]" ) {

  REQUIRE_NOTHROW( game::GridStatus(5, 5) );

  REQUIRE_THROWS( game::GridStatus(0, 3) );

  game::GridStatus grid_1(5, 6);
  REQUIRE_THROWS( grid_1(5, 6) );  // out of range
  REQUIRE( grid_1.getSize().at(0) == 5 );
  REQUIRE( grid_1.getSize().at(1) == 6 );

}



TEST_CASE( "Test initialising the grid at random", "[task 1.2]" ) {

  game::GridStatus grid_1(5, 4, 6);
  REQUIRE( grid_1.getSize().at(0) == 5 );  // total number of placed cells is correct
  REQUIRE( grid_1.getSize().at(1) == 4 );

  game::GridStatus grid_2(5, 4, 6);
  REQUIRE( grid_2.getSize().at(0) == 5 );
  REQUIRE( grid_2.getSize().at(1) == 4 );

  uint count_1 = 0;
  uint count_2 = 0;
  uint same_loc = 0;

  for (int i = 0; i < 5; i ++)
  {
    for (int j = 0; j < 4; j ++)
    {
      if (grid_1.getStatus(i, j) == 'o')
      {
        count_1 ++;
      }

      if (grid_2.getStatus(i, j) == 'o')
      {
        count_2 ++;
      }

      if (grid_1.getStatus(i, j) == 'o' & grid_2.getStatus(i, j) == 'o')
      {
        same_loc ++;
      }
    }
  }

  REQUIRE( count_1 == 6 );  // total number of alive cells is correct
  REQUIRE( count_2 == 6 );
  REQUIRE( same_loc != 6 );  // different pattern


  // all cells alive
  game::GridStatus grid_3(5, 5, 25);
  uint count_3 = 0;

  for (int i = 0; i < 5; i ++)
  {
    for (int j = 0; j < 5; j ++)
    {
      if (grid_3.getStatus(i, j) == 'o')
      {
        count_3 ++;
      }
    }
  }

  REQUIRE( count_3 == 25 );


  // no cell alive
  game::GridStatus grid_4(5, 5, 0);
  uint count_4 = 0;

  for (int i = 0; i < 5; i ++)
  {
    for (int j = 0; j < 5; j ++)
    {
      if (grid_4.getStatus(i, j) == 'o')
      {
        count_4 ++;
      }
    }
  }

  REQUIRE( count_4 == 0 );
}



TEST_CASE( "Test initialising the grid from a file", "[task 1.3]") {
  
  game::GridStatus grid_1("./test/data/glider.txt");
  REQUIRE( grid_1.getSize().at(0) == 10 );
  REQUIRE( grid_1.getSize().at(1) == 10 );

  REQUIRE_THROWS( game::GridStatus("./test/data/input.txt") );

  game::GridStatus grid_3("./test/data/oscillators.txt");
  REQUIRE( grid_3.getSize().at(0) == 12 );
  REQUIRE( grid_3.getSize().at(1) == 12 );

  game::GridStatus grid_4("./test/data/still_lifes.txt");
  REQUIRE( grid_4.getSize().at(0) == 10 );
  REQUIRE( grid_4.getSize().at(1) == 10 );

  REQUIRE_THROWS( game::GridStatus("./Wrong_file_name.txt") );


  // test if file contain other character
  std::ofstream OutFile_1("./test/data/wrong_file.txt");
	OutFile_1 << "- o - - -\n- - o o o\n- A o - -";
	OutFile_1.close();

  REQUIRE_THROWS( game::GridStatus("./test/data/wrong_file.txt") );
  std::remove("./test/data/wrong_file.txt");


  // test file with unequal rows and columns
  std::ofstream OutFile_2("./test/data/right_file.txt");
	OutFile_2 << "- o - - -\n- - o o o\n- - o - -";
	OutFile_2.close();

  game::GridStatus grid_5("./test/data/right_file.txt");
  REQUIRE( grid_5.getSize().at(0) == 3 );
  REQUIRE( grid_5.getSize().at(1) == 5 );
  std::remove("./test/data/right_file.txt");
}
