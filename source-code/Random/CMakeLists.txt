cmake_minimum_required(VERSION 3.5)
project(random_executables LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler flags matching Makefile: -O2, -g, -Wall, -Wextra, -Wpedantic
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -g -Wall -Wextra -Wpedantic")

# List of executables and their source files
set(EXE_SOURCES
    random_int.cpp
    random_double.cpp
    multiple_distr.cpp
)

foreach(src IN LISTS EXE_SOURCES)
    get_filename_component(name ${src} NAME_WE)
    add_executable(${name} ${src})
    # Ensure .exe suffix as in Makefile
    set_target_properties(${name} PROPERTIES SUFFIX ".exe")
    target_link_libraries(${name} PRIVATE m)
endforeach()