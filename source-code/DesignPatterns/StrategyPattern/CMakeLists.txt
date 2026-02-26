cmake_minimum_required(VERSION 3.20)
project(strategy_pattern_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
    cellular_automaton.exe
    automaton_runner.cpp
    cycle_finder.cpp
    main.cpp
)
target_compile_options(cellular_automaton.exe PRIVATE -Wall -Wextra -Wpedantic)
