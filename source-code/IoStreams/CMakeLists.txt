cmake_minimum_required(VERSION 3.20)

project(iostream LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(csv2tsv.exe csv2tsv.cpp)
add_executable(formatting.exe formatting.cpp)
add_executable(serialization.exe serialization.cpp)
add_executable(sum.exe sum.cpp)
add_executable(aggregate.exe aggregate.cpp)
add_executable(alternative_io.exe alternative_io.cpp)
add_executable(format.exe format.cpp)
