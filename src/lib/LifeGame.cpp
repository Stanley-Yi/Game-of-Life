/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "LifeGame.h"
#include <stdexcept>


namespace game {

    LifeGame::LifeGame(uint N, uint M) : grid(GridStatus(N, M)), generation(0) {}

    
    LifeGame::LifeGame(uint N, uint M, uint num) : grid(GridStatus(N, M, num)), generation(0) {}


    LifeGame::LifeGame(std::string filename) : grid(GridStatus(filename)), generation(0) {}
    

    void LifeGame::printGrid()
    {
        std::cout << "\nThe status of generation " << generation << ": \n";

        grid.printGrid();

        std::cout << std::endl;
    }


    void LifeGame::takeStep()
    {
        generation ++;

        uint row = grid.getSize().at(0);
        uint col = grid.getSize().at(1);

        GridStatus* temp = new GridStatus(grid);

        for (int i = 0; i < row; i ++)
        {
            for (int j = 0; j < col; j ++)
            {
                int neighbour = grid.aliveNeighbour(i, j);
                char status = grid.getStatus(i, j);

                // A dead cell with exactly three live neighbours should become a live cell
                if (status == '-' & neighbour == 3)
                {
                    temp -> setStatus('o', i, j);
                }

                // A live cell with two or three live neighbours should stay alive
                else if (status == 'o' & (neighbour == 2 | neighbour == 3))
                {
                    continue;
                }

                // A live cell with less than two or more than three live neighbours should die
                else if (status == 'o' & (neighbour < 2 | neighbour > 3))
                {
                    temp -> setStatus('-', i, j);
                }
            }
        }

        grid = *temp;

        delete temp;

    }


    char LifeGame::getStatus(uint x, uint y)
    {
        return grid.getStatus(x, y);
    }


    uint LifeGame::aliveNeighbour(uint x, uint y)
    {
        return grid.aliveNeighbour(x, y);
    }


} // end namespace
