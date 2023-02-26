/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#pragma once
#include "GridStatus.h"
#include <iostream>
#include <string>
#include <vector>

#ifndef LifeGame_h
#define LifeGame_h

/**
 * \file LifeGame.h
 * \brief This header used for Task 2, where contain a class of LifeGame.
 * \ingroup utilities
 */
namespace game {

/**
 * \brief The class of LifeGame, which is a Simulator for the Game of Life.
 */

class LifeGame {
private:
  uint generation;
  GridStatus grid;

public:
  LifeGame(uint N, uint M);

  LifeGame(uint N, uint M, uint num);

  LifeGame(std::string filename);

  ~LifeGame() {}

  void printGrid();

  void takeStep();

  char getStatus(uint x, uint y);

  uint aliveNeighbour(uint x, uint y);
};

} // namespace game

#endif
