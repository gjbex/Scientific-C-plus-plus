cmake_minimum_required(VERSION 3.0)
project(ranges LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMaKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(simple.exe
    simple.cpp)
add_executable(transform_accumulate.exe
    transform_accumulate.cpp)
