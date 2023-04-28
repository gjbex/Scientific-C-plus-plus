cmake_minimum_required(VERSION 3.0)
project(parallel_algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMaKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_compile_options(-Wall -Wextra -Wpedantic)

find_package(TBB REQUIRED)

add_executable(no_policy.exe
    main_no_policy.cpp
    data.cpp)
target_link_libraries(no_policy.exe PRIVATE TBB::tbb)

add_executable(seq.exe
    main_seq.cpp
    data.cpp)
target_link_libraries(seq.exe PRIVATE TBB::tbb)

add_executable(par.exe
    main_par.cpp
    data.cpp)
target_link_libraries(par.exe PRIVATE TBB::tbb)

add_executable(transform_seq.exe
    main_transform_seq.cpp
    data.cpp
    functions.cpp)
target_link_libraries(transform_seq.exe PRIVATE TBB::tbb)

add_executable(transform_par.exe
    main_transform_par.cpp
    data.cpp
    functions.cpp)
target_link_libraries(transform_par.exe PRIVATE TBB::tbb)

add_executable(transform_par_unseq.exe
    main_transform_par_unseq.cpp
    data.cpp
    functions.cpp)
target_link_libraries(transform_par_unseq.exe PRIVATE TBB::tbb)
