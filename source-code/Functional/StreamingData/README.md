# StteamingData

Comparison between a functional and OO approach to computing running statistics.

## What is it?

1. `stats_functional.h`: functional implemenation using higher order functions
   and shared pointers.
1. `main_functional.cpp`: main function that reads from standard input and
   uses functional approach.
1. `stats_oo.h`: object-oriented implemenation using parenthesis overloading.
1. `main_oo.cpp`: main function that reads from standard input and
   uses object-oriented approach.
1. `CMakeLists.txt`: CMake file to build the applications.
1. `generate_data.py` Python script to generate large data files.
1. `data.txt`: small data file to experiment with.


## Contributors

Thanks to Jakob Randa for suggesting a solution with unique rather than shared
pointers.
