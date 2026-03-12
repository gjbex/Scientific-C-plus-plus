cmake_minimum_required(VERSION 3.20)
project(tbb_tree LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_compile_options(-Wall -Wextra -Wpedantic)

include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/FetchTBB.cmake)

add_subdirectory(src)
