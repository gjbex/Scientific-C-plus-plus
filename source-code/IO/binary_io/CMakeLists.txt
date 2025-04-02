cmake_minimum_required(VERSION 3.20)

project(binary_io LANGUAGES Fortran CXX)

set(CMAKE_Fortran_STANDARD 2008)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost REQUIRED COMPONENTS program_options)

add_executable(triangular_matrix.exe triangular_matrix.f90)
target_compile_options(triangular_matrix.exe PRIVATE -Wall -Wextra)

add_executable(read_triangular_matrix.exe read_triangular_matrix.cpp)
target_compile_options(read_triangular_matrix.exe PRIVATE -Wall -Wextra)
target_link_libraries(read_triangular_matrix.exe PRIVATE Boost::program_options)
