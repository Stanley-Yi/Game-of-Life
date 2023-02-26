/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#pragma once
#include <cstdio>
#include <fstream>
#include <iostream>
#include <stdexcept>

#ifndef FileManager_h
#define FileManager_h

/**
 * \file FileManager.h
 * \brief This header used for read file safely.
 * \ingroup utilities
 */
namespace game {

/**
 * \brief The class of FileManager used to read file.
 */

class FileManager {
private:
  FILE *f;

public:
  FileManager(std::string fileName);

  ~FileManager();

  bool getData(char &);
};

} // namespace game

#endif
