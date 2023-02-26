[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-f4981d0f882b2a3f0472912d15f9806d57e124e0fc890972558857b51b24a6f9.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=10165801)
PHAS0100ASSIGNMENT1
------------------

Purpose
-------

This project serves as a starting point for the PHAS0100 2022/23 Assignment 1 Game of Life Simulation coursework. It has a reasonable folder structure for [CMake](https://cmake.org/) based projects that use [CTest](https://cmake.org/) to run unit tests via [Catch](https://github.com/catchorg/Catch2). 

Further information on the specific project is left as an exercise for the student.

Credits
-------

This project is maintained by [Dr. Jamie Quinn](http://jamiejquinn.com/). It is based on [CMakeCatch2](https://github.com/UCL/CMakeCatch2.git) that was originally developed as a teaching aid for UCL's ["Research Computing with C++"](https://github-pages.ucl.ac.uk/research-computing-with-cpp/) course developed by [Dr. James Hetherington](http://www.ucl.ac.uk/research-it-services/people/james) and [Dr. Matt Clarkson](https://iris.ucl.ac.uk/iris/browse/profile?upi=MJCLA42).

Build Instructions
------------------

To run cmake:

```
cmake -B build
```

To compile:

```
cmake --build build
```

To test:

```
cd build
ctest
```

Additional build and running instructions left to the student.


## Game of Life Simulator
### Running with glider.txt
To use glider.txt initialize grid (with generation 4):
```
./build/bin/gof_simulator -f test/data/glider.txt -g 4
```
After 4 evolutions, the result of grid that initialized by glider.txt is shown as below:

<img src="img/glider_after_4_evolutions.png" alt="image" style="zoom: 67%;" />

The whole process is shown as below:

![glider_4_evolutions_process](D:\Files\Learning Materials\Postgraduate\Semester 2\PHAS0100\Coursework\CW1\22043131\PHAS0100Assignment1\img\glider_4_evolutions_process.png)



### 7 x 7 random grid
To use 7 by 7 randomly initialized grid (with generation 4 and 15 alive cells initially):
```
./build/bin/gof_simulator -s 7 7 -n 15 -g 4
```
After 4 evolutions, the result of 7 by 7 randomly initialized grid is shown as below:

<img src="D:\Files\Learning Materials\Postgraduate\Semester 2\PHAS0100\Coursework\CW1\22043131\PHAS0100Assignment1\img\7x7_after_4_evolutions.png" alt="7x7_after_4_evolutions" style="zoom:67%;" />

The whole process is shown as below:

![7x7_4_evolutions_process](D:\Files\Learning Materials\Postgraduate\Semester 2\PHAS0100\Coursework\CW1\22043131\PHAS0100Assignment1\img\7x7_4_evolutions_process.png)



## Finding stationary patterns

To run the program for a 4 by 4 grid of cells (with 5 alive cells, maximum iteration 5, and 10 initial conditions):

```
./build/bin/still_lifes -s 4 4 -i 5 -n 5 -c 10
```

As a result, we found 3 still lifes,  the screenshots are shown as below:

![still_lifes](D:\Files\Learning Materials\Postgraduate\Semester 2\PHAS0100\Coursework\CW1\22043131\PHAS0100Assignment1\img\still_lifes.png)