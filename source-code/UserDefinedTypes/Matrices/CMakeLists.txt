cmake_minimum_required(VERSION 3.18)
project(algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMaKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(matrix_test.exe
    matrix_test.cpp)
