cmake_minimum_required(VERSION 3.20)

project(sliding_window LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_executable(window.exe sliding_window_main.cpp)
