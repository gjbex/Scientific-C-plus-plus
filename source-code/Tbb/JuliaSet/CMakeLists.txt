cmake_minimum_required(VERSION 3.20)
project(tbb_julia_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(TBB REQUIRED)
find_package(OpenMP REQUIRED)

add_executable(julia_abs.exe julia_abs.cpp)
add_executable(julia.exe julia.cpp)
add_executable(julia_tbb.exe julia_tbb.cpp)
add_executable(julia_omp.exe julia_omp.cpp)
add_executable(julia_tasks_omp.exe julia_tasks_omp.cpp)

foreach(app julia_abs.exe julia.exe julia_tbb.exe julia_omp.exe julia_tasks_omp.exe)
    target_compile_options(${app} PRIVATE -Wall -Wextra -Wpedantic)
    target_link_libraries(${app} PRIVATE m)
endforeach()

target_link_libraries(julia_tbb.exe PRIVATE TBB::tbb)
target_link_libraries(julia_omp.exe PRIVATE OpenMP::OpenMP_CXX)
target_link_libraries(julia_tasks_omp.exe PRIVATE OpenMP::OpenMP_CXX)
