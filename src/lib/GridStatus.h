/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#pragma once
#include <vector>
#include <string>
#include <iostream>

#ifndef GridStatus_h
#define GridStatus_h

/**
* \file GridStatus.h
* \brief This header used for Task 1, where contain a class of GridStatus.
* \ingroup utilities
*/
namespace game
{

/**
* \brief The class of GridStatus, which contain functions such as print, set, get and constructor. 
        It store maintain a nested vector to represent grid, and store status for cells.
*/

    class GridStatus
    {
    private:
        std::vector<std::vector<char>> grid;

        
    public:
        GridStatus(uint col, uint row);

        ~GridStatus(){}

        void printGrid();

        char& operator()(uint x, uint y);

        void setStatus(char s, uint x, uint y);

        char getStatus(uint x, uint y);

    };

} // end namespace

#endif
