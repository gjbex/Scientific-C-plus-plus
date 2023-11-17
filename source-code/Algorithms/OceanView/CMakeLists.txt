cmake_minimum_required(VERSION 3.20)
project(ocean_view LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(ocean_view_test main_test.cpp ocean_view.cpp)
add_executable(ocean_view_timings main_timing.cpp ocean_view.cpp)
add_executable(ocean_view_timings2 main_timing2.cpp ocean_view.cpp)
