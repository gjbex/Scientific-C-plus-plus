cmake_minimum_required(VERSION 3.20)

project(random_values LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler flags matching Makefile: -O2, -g, -Wall, -Wextra, -Wpedantic
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -g -Wall -Wextra -Wpedantic")

# List of executables and their source files
set(APPLICATIONS
    random_int
    random_double
    multiple_distr
)

foreach(appl IN LISTS APPLICATIONS)
    add_executable(${appl}.exe ${appl}.cpp)
    target_compile_options(${appl}.exe
        PRIVATE -Wall -Wextra -Wpedantic)
endforeach()
