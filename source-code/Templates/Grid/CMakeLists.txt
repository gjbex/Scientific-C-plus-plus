cmake_minimum_required(VERSION 3.0)
project(grids LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMaKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(grid.exe main.cpp)
add_executable(grid2.exe main2.cpp)
