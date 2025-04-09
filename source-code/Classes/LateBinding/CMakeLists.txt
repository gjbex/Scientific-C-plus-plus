cmake_minimum_required(VERSION 3.20)

project(quadrature LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)    

add_executable(stats.exe
    stats.cpp
    median_stats.cpp
    stats_main.cpp)
target_compile_options(stats.exe
    PRIVATE -Wall -Wextra -Wpedantic)
