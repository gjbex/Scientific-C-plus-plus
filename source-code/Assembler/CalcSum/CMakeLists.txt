cmake_minimum_required(VERSION 3.20)
project(assembler_calc_sum LANGUAGES CXX ASM_NASM)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(calc_sum.exe calc_sum.cpp calc_sum_function.nsm)
add_executable(timing.exe timing.cpp calc_sum_function.nsm)
add_executable(timing_compiler.exe timing.cpp calc_sum_function_compiler.nsm)

set_source_files_properties(
    calc_sum_function.nsm
    calc_sum_function_compiler.nsm
    PROPERTIES LANGUAGE ASM_NASM
)

foreach(app calc_sum.exe timing.exe timing_compiler.exe)
    target_compile_options(${app} PRIVATE -Wall -Wextra -Wpedantic)
endforeach()
