cmake_minimum_required(VERSION 3.20)

project(simulations LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SIMULATIONS
    dice
    dice_avg)

foreach(SIMULATION ${SIMULATIONS})
    add_executable(${SIMULATION}.exe
        main_${SIMULATION}.cpp)
    target_compile_options(${SIMULATION}.exe
        PRIVATE -Wall -Wextra -Wpedantic)
endforeach()
