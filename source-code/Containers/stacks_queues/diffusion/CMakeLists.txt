cmake_minimum_required(VERSION 3.20)

project(diffusion LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(COMMON_FLAGS -Wall -Wextra -Wpedantic)
set(COMMON_LIBS m)

add_executable(diffusion.exe
    diffusion_main.cpp
    diffusion_system.cpp
)
target_compile_options(diffusion.exe PRIVATE ${COMMON_FLAGS})
target_link_libraries(diffusion.exe PRIVATE ${COMMON_LIBS})
