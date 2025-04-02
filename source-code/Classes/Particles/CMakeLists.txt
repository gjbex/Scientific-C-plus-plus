cmake_minimum_required(VERSION 3.20)

project(particles LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(particles.exe
    main.cpp
    particle.cpp
    static_particle.cpp)
target_compile_options(particles.exe PRIVATE -Wall -Wextra -Wpedantic)
