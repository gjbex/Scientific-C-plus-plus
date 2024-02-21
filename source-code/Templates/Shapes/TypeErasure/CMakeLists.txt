cmake_minimum_required(VERSION 3.20)

project(type_erasure_shapes LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(type_erasure_shapes.exe main.cpp)
