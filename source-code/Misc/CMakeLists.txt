cmake_minimum_required(VERSION 3.0)
project(misc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMaKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(sieve.exe sieve.cpp)
