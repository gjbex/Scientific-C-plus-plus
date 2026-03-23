cmake_minimum_required(VERSION 3.20)

project(IncludeGuards LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(with_include_guards
    src_with_guards/matrices.cpp
    src_with_guards/matrix.cpp
    src_with_guards/utils.cpp
)

target_include_directories(with_include_guards
    PRIVATE
        src_with_guards
)

add_executable(without_include_guards EXCLUDE_FROM_ALL
    src_without_guards/matrices.cpp
    src_without_guards/matrix.cpp
    src_without_guards/utils.cpp
)

target_include_directories(without_include_guards
    PRIVATE
        src_without_guards
)
