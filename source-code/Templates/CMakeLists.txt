cmake_minimum_required(VERSION 3.16)

project(Templates LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Match Makefile output naming convention.
set(CMAKE_EXECUTABLE_SUFFIX .exe)

add_compile_options(-O2 -g -Wall -Wextra)

set(APPLICATIONS
    swap
    sum
    points
    print_container_no_range_for
    fac
)

foreach(app IN LISTS APPLICATIONS)
    add_executable(${app} ${app}.cpp)
    target_link_libraries(${app} PRIVATE m)
endforeach()
