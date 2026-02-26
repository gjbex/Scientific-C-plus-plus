cmake_minimum_required(VERSION 3.20)
project(builder_pattern_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
    rng_runner.exe
    rng.cpp
    rng_builder.cpp
    rng_runner.cpp
)
target_compile_options(rng_runner.exe PRIVATE -Wall -Wextra)
