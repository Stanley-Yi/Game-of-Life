#include <iostream>
#include <vector>
#include <memory>
#include "GridStatus.h"
#include "LifeGame.h"

int main()
{

    try
    {
        game::GridStatus grid_1("./test/data/still_lifes.txt");
        grid_1.printGrid();

    }
    catch(std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
        std::cout << "We no longer have access to the file handle." << std::endl;
    }

    game::LifeGame grid_2(5, 5);

    grid_2.printGrid();
    grid_2.takeStep();
    grid_2.printGrid();
    grid_2.takeStep();
    grid_2.printGrid();
    grid_2.takeStep();
    grid_2.printGrid();
    grid_2.takeStep();
    grid_2.printGrid();
    grid_2.takeStep();
    grid_2.printGrid();
    grid_2.takeStep();
    grid_2.printGrid();

}