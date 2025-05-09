cmake_minimum_required(VERSION 3.20)

project(function_factory LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost REQUIRED COMPONENTS program_options)

add_executable(function_factory.exe
    main.cpp
)
target_compile_options(function_factory.exe
    PRIVATE -Wall -Wextra -Wpedantic)
target_include_directories(function_factory.exe
    PRIVATE Boost::Boost)
target_link_libraries(function_factory.exe
    PRIVATE Boost::program_options)
