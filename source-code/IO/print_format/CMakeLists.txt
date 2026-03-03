cmake_minimum_required(VERSION 3.10)

project(print_format LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(print_format.exe print_format.cpp)
