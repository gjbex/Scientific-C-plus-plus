cmake_minimum_required(VERSION 3.20)
project(modularity_stats_example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(stats.exe stats.cpp stats_main.cpp)
target_compile_options(stats.exe PRIVATE -Wall -Wextra)
target_link_libraries(stats.exe PRIVATE m)
