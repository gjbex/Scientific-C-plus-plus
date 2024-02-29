cmake_minimum_required(VERSION 3.20)
project(grids LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMaKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(iterable.exe main.cpp)
