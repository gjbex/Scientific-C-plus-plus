cmake_minimum_required(VERSION 3.20)

project(cellular_automata LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)
set(CMaKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

find_package(Boost COMPONENTS program_options)
if (NOT Boost_FOUND)
    message(FATAL_ERROR "Boost is required but can't be found")
endif (NOT Boost_FOUND)

add_executable(cellular_automata.exe
    cells.cpp
    neighbourhood.cpp
    rule.cpp
    utils.cpp
    main.cpp)
target_compile_options(cellular_automata.exe PRIVATE -Wall -Wextra -Wpedantic)
target_include_directories(cellular_automata.exe PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(cellular_automata.exe LINK_PRIVATE ${Boost_LIBRARIES})
