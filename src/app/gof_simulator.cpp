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
#include <golExceptionMacro.h>
#include <iostream>
#include <thread>
#include <chrono>


static void show_usage(std::string name)
{
    std::cerr << "Usage: " << name << " <option(s)> SOURCES"
              << "Options:\n"
              << "\t-h,--help \t\tShow this help message\n"
              << "\t-f,--file \t\tInitialise the Game of Life by specified txt file\n"
              << "\t-g,--generation \tSpecify the maximum number of generation, and the default number is 10\n"
              << "\t-s,--size \t\tSpecify the size of grid, please input two integers as row and colnum\n"
              << "\t-n,--num \t\tSpecify the number of alive cell, the grid will initialised randomly if not specify\n"
              << std::endl;
}



int main(int argc, char** argv)
{

  if (argc < 2) 
  {
    show_usage(argv[0]);

    return 1;
  }

  std::string filename;
  uint generation = 10;
  uint row;
  uint col;
  uint num = -1;

  for (int i = 1; i < argc; i++) 
  {
    std::string arg = argv[i];
    if ((arg == "-h") || (arg == "--help")) 
    {
      show_usage(argv[0]);

      return 1;

    }

    else if ((arg == "-f") || (arg == "--file")) 
    {
      if (i + 1 < argc)  // Make sure we aren't at the end of argv!
      {
        filename = argv[++i];  // Increment 'i' so we don't get the argument as the next argv[i].
      } 
      else 
      { // Uh-oh, there was no argument to the destination option.
        std::cerr << "--file option requires one file path as argument." << std::endl;

        return 1;
      }
    }

    else if ((arg == "-g") || (arg == "--generation")) 
    {
      if (i + 1 < argc)
      {

        generation = std::atoi(argv[++i]);
        
      } 
      else 
      {
        std::cerr << "--generation option requires one integer as argument." << std::endl;

        return 1;
      }
    }

    else if ((arg == "-s") || (arg == "--size")) 
    {
      if (i + 2 < argc)
      {

        row = std::atoi(argv[++i]);
        col = std::atoi(argv[++i]);
        
      } 
      else 
      {
        std::cerr << "--size option requires two integers row and colnum as argument." << std::endl;

        return 1;
      }
    }

    else if ((arg == "-n") || (arg == "--num")) 
    {
      if (i + 1 < argc)
      {

        num = std::atoi(argv[++i]);
        
      } 
      else 
      {
        std::cerr << "--num option requires one integer as argument." << std::endl;

        return 1;
      }
    }
  }


  game::LifeGame life(1, 1);

  if (! filename.empty())
  {
    
    try
    {
      game::LifeGame g(filename);
      life = g;
    }
    catch(std::exception &e)
    {
      std::cout << "Exception caught: " << e.what() << std::endl;

      return 1;
    }

  }

  else if (row & col)
  {
    if (num != -1)
    {
      game::LifeGame g(row, col, num);
      life = g;
    }
    else
    {
      game::LifeGame g(row, col);
      life = g;
    }
  }

  else
  {
    std::cerr << "Cannot initial the game of life, please check if all arguments are valid." << std::endl;

    return 1;
  }

  
  life.printGrid();

  for (int i = 0; i < generation; i++)
  {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    life.takeStep();
    life.printGrid();
  }
  
  return 0;
}
