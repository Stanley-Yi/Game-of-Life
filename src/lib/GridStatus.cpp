/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "GridStatus.h"
#include "FileManager.h"
#include <random>
#include <algorithm>
#include <stdexcept>


namespace game {

    GridStatus::GridStatus(uint N, uint M) : row(N), col(M)
    {
        if (N == 0 || M == 0)
        {
            throw std::invalid_argument("The input of grid size cannot be zero.");
        }

        for (int i = 0; i < row; i++)
        {
            std::vector<char> r(col, '-');
            grid.push_back(r);
        }

        randomInit();
    }


    GridStatus::GridStatus(uint N, uint M, uint num) : row(N), col(M)
    {
        if (N == 0 || M == 0)
        {
            throw std::invalid_argument("The input of grid size cannot be zero.");
        }

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


    GridStatus::GridStatus(std::string filename)
    {
        FileManager file(filename);

        char s;

        std::vector<char> r;

        while(file.getData(s))
        {   
            // process the line breaks, \r\n for Windows, \r for Mac, and \n for Unix
            if ((std::string) &s == "\r\n" | s == '\n' | s == '\r')
            {
                if (r.size() > 0)
                {
                    grid.push_back(r);
                    r.clear();
                }
            }
            else if (s == ' ')
            {
                continue;
            }
            else
            {
                if (s != '-' and s != 'o')
                {
                    throw std::invalid_argument("The content of file should only be - or o.");
                }

                r.push_back(s);
            }
        }

        if (r.size() > 0)
        {
            grid.push_back(r);  // the last line has no line breaks
        }

        row = grid.size();
        col = grid.at(0).size();
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


    std::vector<uint> GridStatus::getSize()
    {
        std::vector<uint> size;

        size.push_back(row);
        size.push_back(col);

        return size;
    }

} // end namespace
