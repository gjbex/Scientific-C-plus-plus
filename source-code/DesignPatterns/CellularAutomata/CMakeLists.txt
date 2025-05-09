cmake_minimum_required(VERSION 3.20)

project(cellular_automata LANGUAGES CXX)

if(POLICY CMP0167)
    cmake_policy(SET CMP0167 NEW)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

find_package(Boost REQUIRED COMPONENTS program_options)

add_executable(cellular_automata.exe
    cells.cpp
    collective_dynamics.cpp
    cycle_finder.cpp
    random_cells_factory.cpp
    rule.cpp
    runners.cpp
    uniform_cells_factory.cpp
    utils.cpp
    visualization_runner.cpp
    main.cpp)
target_compile_options(cellular_automata.exe PRIVATE -Wall -Wextra -Wpedantic)
target_link_libraries(cellular_automata.exe PRIVATE Boost::program_options)
