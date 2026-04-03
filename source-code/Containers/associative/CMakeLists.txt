cmake_minimum_required(VERSION 3.20)

project(associative_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(COMMON_FLAGS -Wall -Wextra -Wpedantic)

set(ASSOCIATIVE_EXAMPLES
    aggregate_data
    dim_nr_counts
    dim_nrs
    set
)

foreach(app ${ASSOCIATIVE_EXAMPLES})
    add_executable(${app}.exe ${app}.cpp)
    target_compile_options(${app}.exe PRIVATE ${COMMON_FLAGS})
endforeach()
