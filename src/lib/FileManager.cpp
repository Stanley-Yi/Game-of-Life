/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "FileManager.h"

namespace game {

FileManager::FileManager(std::string fileName) {
  f = std::fopen(fileName.c_str(), "rw");

  if (!f) {
    throw std::runtime_error("Failed to open file " + fileName);
  }
  std::cout << "File " + fileName + " opened." << std::endl;
}

FileManager::~FileManager() {
  if (f) {
    std::fclose(f);
    std::cout << "File closed." << std::endl;
  }
}

bool FileManager::getData(char &c) {

  if (std::fscanf(f, "%c", &c) != EOF) {
    return true;
  } else {
    return false;
  }
}

} // namespace game