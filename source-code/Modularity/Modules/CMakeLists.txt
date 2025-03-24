cmake_minimum_required(VERSION 3.28)

project(cpp_modules LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(fib.exe)
target_sources(fib.exe PUBLIC main.cpp)
target_sources(fib.exe PUBLIC FILE_SET appl_modules TYPE CXX_MODULES FILES fib.cppm)
