cmake_minimum_required(VERSION 3.10)

project(explicit_or_not LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(explicit_or_not.exe explicit_or_not.cpp)
