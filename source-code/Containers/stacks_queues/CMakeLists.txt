cmake_minimum_required(VERSION 3.20)

project(stacks_queues_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(COMMON_FLAGS -Wall -Wextra -Wpedantic)

add_executable(rpn_calc.exe rpn_calc.cpp)
target_compile_options(rpn_calc.exe PRIVATE ${COMMON_FLAGS})
