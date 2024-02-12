cmake_minimum_required(VERSION 3.0)
project(ranges LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMaKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(simple.exe
    simple.cpp)
add_executable(transform_accumulate.exe
    transform_accumulate.cpp)
add_executable(classic_stl_to_ranges.exe
    classic_stl_to_ranges.cpp)
add_executable(input_ranges.exe
    input_ranges.cpp)
add_executable(enumerate.exe
    enumerate.cpp)
