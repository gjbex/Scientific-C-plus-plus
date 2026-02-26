cmake_minimum_required(VERSION 3.20)
project(boost_vector_example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(boost_vector.exe boost_vector.cpp)
target_compile_options(boost_vector.exe PRIVATE -Wall -Wextra)
target_link_libraries(boost_vector.exe PRIVATE m)
