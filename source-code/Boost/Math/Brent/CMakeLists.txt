cmake_minimum_required(VERSION 3.20)
project(brent LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSION NO)

add_compile_options(-Wall -Wextra -Wpedantic)

find_package(Boost)
if (NOT Boost_FOUND)
    message(FATAL_ERROR "Boost is required but can't be found")
endif (NOT Boost_FOUND)

add_executable(brent.exe brent_optimization.cpp)
target_include_directories(brent.exe PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(brent.exe LINK_PRIVATE ${Boost_LIBRARIES})
