cmake_minimum_required(VERSION 3.20)
project(boost_coroutines_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost REQUIRED COMPONENTS coroutine context)

add_executable(range.exe range.cpp)
target_compile_options(range.exe PRIVATE -Wall -Wextra)
target_link_libraries(range.exe PRIVATE Boost::coroutine Boost::context)
