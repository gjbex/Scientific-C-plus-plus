cmake_minimum_required(VERSION 3.20)

project(stats LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(stats.exe
    main_stats.cpp
    simple_stats.cpp
    stats.cpp
)

target_compile_options(stats.exe PRIVATE -Wall -Wextra -Wpedantic)