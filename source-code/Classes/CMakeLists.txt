cmake_minimum_required(VERSION 3.20)

project(late_binding LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# List of executables and their source files
set(APPLICATIONS
    late_binding
)

foreach(appl IN LISTS APPLICATIONS)
    add_executable(${appl}.exe ${appl}.cpp)
    # Compiler flags matching Makefile: -Wall, -Wextra, -Wpedantic
    target_compile_options(${appl}.exe PRIVATE -Wall -Wextra -Wpedantic)
endforeach()