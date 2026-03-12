cmake_minimum_required(VERSION 3.20)

if(POLICY CMP0167)
  cmake_policy(SET CMP0167 NEW)
endif()

project(line_of_sight LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_compile_options(-Wall -Wextra -Wpedantic)

find_package(Boost CONFIG REQUIRED COMPONENTS program_options)
include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/FetchTBB.cmake)

add_subdirectory(src)
