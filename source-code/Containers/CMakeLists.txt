cmake_minimum_required(VERSION 3.20)

project(MyExecutables CXX)

# C++ standard settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Common compiler flags
set(COMMON_FLAGS -Wall -Wextra -Wpedantic)

# Link libraries (e.g., -lm for math)
set(COMMON_LIBS m)

# List of simple one-object executables
set(SINGLE_SOURCE_EXES
    cosine_similarity
    synthesizer
    tuple
    vector
    list
    set
    stats
    dim_nrs
    dim_nr_counts
    split_string
    point_distances
    aggregate_data
    rpn_calc
    kaprekar
)

foreach(app ${SINGLE_SOURCE_EXES})
    add_executable(${app}.exe ${app}.cpp)
    target_compile_options(${app}.exe PRIVATE ${COMMON_FLAGS})
    target_link_libraries(${app}.exe PRIVATE ${COMMON_LIBS})
endforeach()

# Special case: diffusion.exe depends on multiple objects
add_executable(diffusion.exe
    diffusion_system.cpp
    diffusion_main.cpp)
target_compile_options(diffusion.exe PRIVATE ${COMMON_FLAGS})
target_link_libraries(diffusion.exe PRIVATE ${COMMON_LIBS})
