cmake_minimum_required(VERSION 3.20)

project(formatting LANGUAGES CXX)

include(CheckIncludeFileCXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

check_include_file_cxx(print HAVE_PRINT_HEADER)

add_executable(iomanip_formatting.exe iomanip_formatting.cpp)
add_executable(std_format.exe std_format.cpp)

if(HAVE_PRINT_HEADER)
    add_executable(print_format.exe print_format.cpp)
else()
    message(STATUS "Skipping print_format.exe because <print> is not available")
endif()
