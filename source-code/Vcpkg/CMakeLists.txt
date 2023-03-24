cmake_minimum_required(VERSION 3.0)
project(eigen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMaKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_compile_options(-Wall -Wextra -Wpedantic)

find_package(Eigen3 CONFIG REQUIRED)

add_executable(read_matrix.exe read_matrix.cpp)
target_link_libraries(read_matrix.exe PRIVATE Eigen3::Eigen)

