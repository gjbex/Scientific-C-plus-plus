cmake_minimum_required(VERSION 3.0)

project(Particles LANGUAGES CXX)

set(CMAKE_CXX_LANGUAGE_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(particles.exe particle.cpp particles_main.cpp)
