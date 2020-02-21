cmake_minimum_required(VERSION 3.0)

project(Knapsack LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_compile_options(-g -Wall -Wextra -Wpedantic)

add_subdirectory(src)
