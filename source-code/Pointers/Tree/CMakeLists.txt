cmake_minimum_required(VERSION 3.0)
project(trees LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMaKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(tree.exe tree.cpp)
add_executable(tree_uptr.exe tree_uptr.cpp)
add_executable(tree_sptr.exe tree_sptr.cpp)
