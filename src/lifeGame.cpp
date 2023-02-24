#include <iostream>
#include <vector>
#include <memory>
#include "GridStatus.h"

int main()
{

    game::GridStatus grid_1(5, 5);
    grid_1.printGrid();
    grid_1(6, 6);

}