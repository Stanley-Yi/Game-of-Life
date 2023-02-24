/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "GridStatus.h"
#include <random>
#include <algorithm>


namespace game {

    GridStatus::GridStatus(uint N, uint M) : row(N), col(M)
    {
        for (int i = 0; i < row; i++)
        {
            std::vector<char> r(col, '-');
            grid.push_back(r);
        }

        randomInit();
    }


    GridStatus::GridStatus(uint N, uint M, uint num) : row(N), col(M)
    {
        for (int i = 0; i < row; i++)
        {
            std::vector<char> r(col, '-');
            grid.push_back(r);
        }

        // flat the grid, and store index in to vector temp
        std::vector<uint> temp;
        for (int i = 0; i < row * col; i ++)
        {
            temp.push_back(i);
        }

        // shuffle the vector temp, and get top-num elements as random number
        std::random_shuffle(temp.begin(), temp.end());

        for (int i = 0; i < num; i ++)
        {
            uint location = temp.at(i);

            // revert position from index
            this -> setStatus('o', location / col, location >= col ? location % col : location);
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


    void GridStatus::randomInit()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j ++)
            {
                if (rand () / double (RAND_MAX) >= 0.66)  // generate random number in range [0, 1]
                {
                    this -> setStatus('o', i, j);
                }
            }
        }

    }

} // end namespace
