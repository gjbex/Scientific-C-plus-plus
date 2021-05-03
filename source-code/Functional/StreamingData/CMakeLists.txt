cmake_minimum_required(VERSION 3.0)
project(stats LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_GNU_EXTNESIONS NO)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(stats_functional.exe main_functional.cpp)
add_executable(stats_oo.exe main_oo.cpp)
