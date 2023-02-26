/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <GridStatus.h>
#include <LifeGame.h>
#include <gameExceptionMacro.h>
#include <iostream>

static void show_usage(std::string name) {
  std::cerr << "Usage: " << name << " <option(s)> SOURCES"
            << "Options:\n"
            << "\t-h,--help \t\tShow this help message\n"
            << "\t-i,--iteration \t\tSpecify the maximum number of iterations, "
               "and the default number is 10\n"
            << "\t-s,--size \t\tSpecify the size of grid, please input two "
               "integers as row and colnum\n"
            << "\t-n,--num \t\tSpecify the number of alive cell, the grid will "
               "initialised randomly if not specify\n"
            << "\t-c,--condition \t\tSpecify the number of different initial "
               "conditions need to try, and the default number is 3\n"
            << std::endl;
}

bool isStationary(uint r, uint c, game::LifeGame grid, game::LifeGame &last) {
  // check if a 4x4 grid changed
  uint count = 0;

  for (uint i = r; i < r + 4; i++) {
    for (uint j = c; j < c + 4; j++) {
      if (grid.getStatus(i, j) != last.getStatus(i, j)) {
        return false;
      }

      if (grid.getStatus(i, j) == 'o') {
        count++;
      }
    }
  }

  // if alive cell less than 3, there is no still life
  if (count > 3) {
    return true;
  }

  return false;
}

void print_pattern(uint r, uint c, game::LifeGame grid) {

  std::cout << "Found a still life:" << std::endl;

  for (uint i = r; i < r + 4; i++) {
    for (uint j = c; j < c + 4; j++) {
      std::cout << grid.getStatus(i, j) << " ";
    }

    std::cout << "\n";
  }

  std::cout << std::endl;
}

void find_still(uint r, uint c, game::LifeGame grid, uint iteration) {

  for (int k = 0; k < iteration; k++) {
    game::LifeGame *last = new game::LifeGame(grid);

    grid.takeStep();

    for (int i = 0; i < r - 3; i++) {
      for (int j = 0; j < c - 3; j++) {

        // check if exits still life
        if (isStationary(i, j, grid, *last)) {
          std::cout << "Program found a still life, the grid of last and "
                       "current and the pattern is:"
                    << std::endl;

          // print last and current grid
          last->printGrid();
          grid.printGrid();

          // print pattern
          print_pattern(i, j, grid);

          // jump over the same space
          i += 4;
          j += 4;
        }
      }
    }
  }
}

int main(int argc, char **argv) {

  if (argc < 2) {
    show_usage(argv[0]);

    return 1;
  }

  uint iteration = 10;
  uint condition = 3;
  uint row;
  uint col;
  uint num = -1;

  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if ((arg == "-h") || (arg == "--help")) {
      show_usage(argv[0]);

      return 1;

    }

    else if ((arg == "-i") || (arg == "--iteration")) {
      if (i + 1 < argc) {

        iteration = std::atoi(argv[++i]); // convert char to int

      } else {
        std::cerr << "--iteration option requires one integer as argument."
                  << std::endl;

        return 1;
      }
    }

    else if ((arg == "-c") || (arg == "--condition")) {
      if (i + 1 < argc) {

        condition = std::atoi(argv[++i]);

      } else {
        std::cerr << "--condition option requires one integer as argument."
                  << std::endl;

        return 1;
      }
    }

    else if ((arg == "-s") || (arg == "--size")) {
      if (i + 2 < argc) {

        row = std::atoi(argv[++i]);
        col = std::atoi(argv[++i]);

      } else {
        std::cerr
            << "--size option requires two integers row and colnum as argument."
            << std::endl;

        return 1;
      }
    }

    else if ((arg == "-n") || (arg == "--num")) {
      if (i + 1 < argc) {

        num = std::atoi(argv[++i]);

      } else {
        std::cerr << "--num option requires one integer as argument."
                  << std::endl;

        return 1;
      }
    }
  }

  // flag to show use which constructor
  uint flag = 0;

  if (row & col) {
    if (num != -1) {
      flag = 3;
    } else {
      flag = 2;
    }
  }

  else {
    std::cerr << "Cannot initial the game of life, please check if all "
                 "arguments are valid."
              << std::endl;

    return 1;
  }

  // generate different initial conditions
  for (int count = 0; count < condition; count++) {

    if (flag == 3) {
      find_still(row, col, game::LifeGame(row, col, num), iteration);
    } else if (flag == 2) {
      find_still(row, col, game::LifeGame(row, col), iteration);
    }
  }

  return 0;
}
