/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "GridStatus.h"


namespace game {

GridStatus::GridStatus(uint col, uint row)
    {
        for (int i = 0; i < row; i++)
        {
            std::vector<char> r(col, '-');
            grid.push_back(r);
        }
    }


    void GridStatus::printGrid()
    {
        for (auto &r : grid)
        {

            for (auto &i : r)
            {
                std::cout << i << " ";
            }

            std::cout << "\n";
        }

        std::cout << std::endl;
    }


    char& GridStatus::operator()(uint x, uint y)
    {
        return grid.at(x).at(y);
    }


    void GridStatus::setStatus(char s, uint x, uint y)
    {
        (*this)(x, y) = s;
    }


    char GridStatus::getStatus(uint x, uint y)
    {
        return (*this)(x, y);
    }


} // end namespace
