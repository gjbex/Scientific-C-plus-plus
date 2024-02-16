# Ocean view

Given an array that represents heights of buildings, determine
which buildings have an ocean view.  A building has an ocean view
when all buildings between itself and the ocean are strictly smaller.
Consider the ocean position at the end of the array.

For example, consider buildings with heights [1, 9, 6, 8, 6, 3, 3],
then the implementation should return [1, 3, 4, 6].


## What is it?

1. `ocean_view.cpp`: two implementations of the algorithm, one based
   on a monotonic stack, as well as a function to create a vector of
   buildings.
1. `ocean_view.h`: corresponding header file.
1. `main_test.cpp`: main function that computes the ocean view
   buildings for both implementations for the example given above.
1. `main_timings.cpp`: main function to simply time the first
   implementation.
1. `main_timings2.cpp`: main function to simply time the second
   implementation.
1. `CMakeLists.txt`: CMake file to build the applications.
