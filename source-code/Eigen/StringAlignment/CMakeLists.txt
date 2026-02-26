cmake_minimum_required(VERSION 3.20)
project(string_alignment_example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Eigen3 REQUIRED)

add_executable(
    string_align.exe
    main.cpp
    string_aligner.cpp
)
target_compile_options(string_align.exe PRIVATE -Wall -Wextra -Wpedantic)
target_include_directories(string_align.exe PRIVATE ${EIGEN3_INCLUDE_DIR})
target_link_libraries(string_align.exe PRIVATE m)
