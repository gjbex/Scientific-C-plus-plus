cmake_minimum_required(VERSION 3.16)

project(quadrature_dispatch_benchmark LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(bench_runtime.exe
    benchmark_runtime.cpp
    ../Quadrature/simpson_quad.cpp
    ../Quadrature/gaussian_quad.cpp
)
target_include_directories(bench_runtime.exe PRIVATE ../Quadrature)

add_executable(bench_crtp.exe
    benchmark_crtp.cpp
    ../Quadrature_CRTP/simpson_quad.cpp
    ../Quadrature_CRTP/gaussian_quad.cpp
)
target_include_directories(bench_crtp.exe PRIVATE ../Quadrature_CRTP)

add_executable(bench_duck_typing.exe
    benchmark_duck_typing.cpp
    ../Quadrature_duck_typing/simpson_quad.cpp
    ../Quadrature_duck_typing/gaussian_quad.cpp
)
target_include_directories(
    bench_duck_typing.exe
    PRIVATE
        ../Quadrature_duck_typing
)

foreach(target
        bench_runtime.exe
        bench_crtp.exe
        bench_duck_typing.exe)
    target_compile_options(${target} PRIVATE -O3 -DNDEBUG -Wall -Wextra -Wpedantic)
    target_link_libraries(${target} PRIVATE m)
endforeach()
