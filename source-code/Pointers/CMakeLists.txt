cmake_minimum_required(VERSION 3.0)
project(pointers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMaKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(runtime_vs_compile_time.exe
    runtime_vs_compile_time.cpp)
add_executable(pointers_vs_references.exe
    pointers_vs_references.cpp)
