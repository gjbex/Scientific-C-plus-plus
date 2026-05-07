cmake_minimum_required(VERSION 3.20)

project(back_substitution LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)


find_package(Boost COMPONENTS program_options)
if (NOT Boost_FOUND)
    message(FATAL_ERROR "Boost is required but can't be found")
endif (NOT Boost_FOUND)

add_subdirectory(src)
