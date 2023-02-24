#include <iostream>
#include <vector>
#include <memory>
#include "GridStatus.h"

int main()
{

    game::GridStatus grid_1(6, 6, 36);
    grid_1.printGrid();
    
    game::GridStatus grid_2(9, 9, 81);
    grid_2.printGrid();
}