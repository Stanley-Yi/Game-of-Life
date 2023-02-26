/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "GridStatus.h"
#include "LifeGame.h"
#include "catch.hpp"
#include "gameCatchMain.h"

char result(char status, uint num) {
  char res = status;

  if (status == '-' & num == 3) {
    res = 'o';
  }

  // A live cell with two or three live neighbours should stay alive
  else if (status == 'o' & (num == 2 | num == 3)) {
    res = 'o';
  }

  // A live cell with less than two or more than three live neighbours should
  // die
  else if (status == 'o' & (num<2 | num> 3)) {
    res = '-';
  }

  return res;
}

TEST_CASE("Test implementing the game of life", "[task 2.1]") {

  REQUIRE_NOTHROW(game::LifeGame(5, 5));

  game::LifeGame grid(5, 5, 10);

  grid.takeStep();

  // test four corner, four edge, and one normal cell
  // four corner
  int x_1 = 0;
  int y_1 = 0;
  char status_1 = grid.getStatus(x_1, y_1);
  int num_1 = grid.aliveNeighbour(x_1, y_1);
  char res_1 = result(status_1, num_1);

  int x_2 = 4;
  int y_2 = 4;
  char status_2 = grid.getStatus(x_2, y_2);
  int num_2 = grid.aliveNeighbour(x_2, y_2);
  char res_2 = result(status_2, num_2);

  int x_3 = 0;
  int y_3 = 4;
  char status_3 = grid.getStatus(x_3, y_3);
  int num_3 = grid.aliveNeighbour(x_3, y_3);
  char res_3 = result(status_3, num_3);

  int x_4 = 4;
  int y_4 = 0;
  char status_4 = grid.getStatus(x_4, y_4);
  int num_4 = grid.aliveNeighbour(x_4, y_4);
  char res_4 = result(status_4, num_4);

  // four edge
  int x_5 = 0;
  int y_5 = 2;
  char status_5 = grid.getStatus(x_5, y_5);
  int num_5 = grid.aliveNeighbour(x_5, y_5);
  char res_5 = result(status_5, num_5);

  int x_6 = 3;
  int y_6 = 0;
  char status_6 = grid.getStatus(x_6, y_6);
  int num_6 = grid.aliveNeighbour(x_6, y_6);
  char res_6 = result(status_6, num_6);

  int x_7 = 4;
  int y_7 = 1;
  char status_7 = grid.getStatus(x_7, y_7);
  int num_7 = grid.aliveNeighbour(x_7, y_7);
  char res_7 = result(status_7, num_7);

  int x_8 = 3;
  int y_8 = 4;
  char status_8 = grid.getStatus(x_8, y_8);
  int num_8 = grid.aliveNeighbour(x_8, y_8);
  char res_8 = result(status_8, num_8);

  // one normal
  int x_9 = 2;
  int y_9 = 3;
  char status_9 = grid.getStatus(x_9, y_9);
  int num_9 = grid.aliveNeighbour(x_9, y_9);
  char res_9 = result(status_9, num_9);

  grid.takeStep();

  REQUIRE(res_1 == grid.getStatus(x_1, y_1));
  REQUIRE(res_2 == grid.getStatus(x_2, y_2));
  REQUIRE(res_3 == grid.getStatus(x_3, y_3));
  REQUIRE(res_4 == grid.getStatus(x_4, y_4));
  REQUIRE(res_5 == grid.getStatus(x_5, y_5));
  REQUIRE(res_6 == grid.getStatus(x_6, y_6));
  REQUIRE(res_7 == grid.getStatus(x_7, y_7));
  REQUIRE(res_8 == grid.getStatus(x_8, y_8));
  REQUIRE(res_9 == grid.getStatus(x_9, y_9));
}
