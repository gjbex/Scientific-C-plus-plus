cmake_minimum_required(VERSION 3.20)

# Set project name and C++ standard
project(MyExecutables CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# List of executable targets
set(APPL
    hello
    talk
    col_dist
    gcd
    fac
    scope
    swap
    arrays
    argument_passing
    local_namespace_use
    data_parser
    arrays_vs_pointers
)

# Add an executable for each .cpp file
foreach(app ${APPL})
    add_executable(${app}.exe ${app}.cpp)
    target_compile_options(${app}.exe PRIVATE -Wall -Wextra)
endforeach()
