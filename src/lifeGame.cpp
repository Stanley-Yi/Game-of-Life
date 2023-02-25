#include <iostream>
#include <vector>
#include <memory>
#include "GridStatus.h"

int main()
{

    try
    {
        game::GridStatus grid_1("./test/data/still_lifes.txt");
        grid_1.printGrid();

        std::cout << grid_1.getSize().at(0) << std::endl;
        std::cout << grid_1.getSize().at(1) << std::endl;

        std::cout << grid_1.aliveNeighbour(10, 10) << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
        std::cout << "We no longer have access to the file handle." << std::endl;
    }


}