cmake_minimum_required(VERSION 3.20)

project(table_stats CXX)

# C++ standard settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Common compiler flags
set(COMMON_FLAGS -Wall -Wextra -Wpedantic)

# Link libraries (e.g., -lm for math)
set(COMMON_LIBS m)

# stats executable
add_executable(stats.exe
    stats.cpp
    stats_main.cpp)
target_compile_options(stats.exe PRIVATE ${COMMON_FLAGS})
target_link_libraries(stats.exe PRIVATE ${COMMON_LIBS})

# table_stats executable
add_executable(table_stats.exe
    stats.cpp
    table_stats.cpp
    table_stats_main.cpp)
target_compile_options(table_stats.exe PRIVATE ${COMMON_FLAGS})
target_link_libraries(table_stats.exe PRIVATE ${COMMON_LIBS})