cmake_minimum_required(VERSION 3.20)

project(particles LANGUAGES CXX)

set(CMAKE_CXX_LANGUAGE_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)


add_executable(particles.exe particle.cpp particles_main.cpp)
target_compile_options(particles.exe BEFORE PRIVATE -Wall -Wextra -Wpedantic)
