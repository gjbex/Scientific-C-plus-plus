cmake_minimum_required(VERSION 3.20)

project(object_life_cycle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(gadget.exe gadget.cpp)

add_executable(emplace.exe emplace.cpp)
