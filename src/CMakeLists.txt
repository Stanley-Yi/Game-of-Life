#/*============================================================================
#
#  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.
#
#  Copyright (c) University College London (UCL). All rights reserved.
#
#  This software is distributed WITHOUT ANY WARRANTY; without even
#  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
#  PURPOSE.
#
#  See LICENSE.txt in the top level directory for details.
#
#============================================================================*/

add_library(GridStatus lib/GridStatus.cpp)
target_include_directories(GridStatus PUBLIC ${ALL_THIRD_PARTY_LIBRARIES})

add_executable(lifeGame lifeGame.cpp)
target_link_libraries(lifeGame GridStatus)

add_subdirectory(lib)
add_subdirectory(app)
