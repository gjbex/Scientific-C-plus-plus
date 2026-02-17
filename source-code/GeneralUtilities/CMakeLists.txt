cmake_minimum_required(VERSION 3.20)

project(general_utilities LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(optional.exe optional.cpp)
add_executable(variant_visit.exe variant_visit.cpp)
