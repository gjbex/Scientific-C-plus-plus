cmake_minimum_required(VERSION 3.20)
project(line_of_sight LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_compile_options(-Wall -Wextra -Wpedantic)

find_package(Boost REQUIRED COMPONENTS program_options)
include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/FetchTBB.cmake)

add_subdirectory(src)
