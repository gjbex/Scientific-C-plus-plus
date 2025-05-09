cmake_minimum_required(VERSION 3.20)

project(tabular LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


if(POLICY CMP0167)
  cmake_policy(SET CMP0167 NEW)
endif()

find_package(Boost REQUIRED COMPONENTS program_options)

add_executable(tabular_sum.exe
    tabular_sum.cpp)
target_include_directories(tabular_sum.exe
    PRIVATE Boost::Boost)
target_link_libraries(tabular_sum.exe
    PRIVATE Boost::program_options)
target_compile_options(tabular_sum.exe
    PRIVATE -Wall -Wextra -pedantic)
