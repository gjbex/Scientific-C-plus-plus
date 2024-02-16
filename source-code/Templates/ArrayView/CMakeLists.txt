cmake_minimum_required(VERSION 3.18)
project(array_view LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(test_array_views.exe test_array_views.cpp)
