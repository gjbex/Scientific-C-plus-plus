cmake_minimum_required(VERSION 3.20)
project(assembler_quadratic LANGUAGES CXX ASM_NASM)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set_source_files_properties(quad.nsm PROPERTIES LANGUAGE ASM_NASM)

add_executable(quad_calc.exe quad_calc.cpp quad.nsm)
add_executable(timing.exe timing.cpp quad.nsm)
add_executable(quad_calc_inline.exe quad_calc_inline.cpp)

foreach(app quad_calc.exe timing.exe quad_calc_inline.exe)
    target_compile_options(${app} PRIVATE -Wall -Wextra -Wpedantic)
endforeach()
