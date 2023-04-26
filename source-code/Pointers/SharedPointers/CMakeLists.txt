cmake_minimum_required(VERSION 3.0)
project(shared_pointers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMaKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(linked_list.exe
    main.cpp
    linked_list.cpp)
