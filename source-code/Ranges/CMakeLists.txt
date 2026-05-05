cmake_minimum_required(VERSION 3.20)
project(ranges LANGUAGES CXX)

function(target_enable_project_warnings target)
    if(NOT TARGET "${target}")
        message(FATAL_ERROR "target_enable_project_warnings called for unknown target: ${target}")
    endif()

    target_compile_options("${target}" PRIVATE
        "$<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang,IntelLLVM>:-Wall>"
        "$<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang,IntelLLVM>:-Wextra>"
        "$<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang,IntelLLVM>:-Wpedantic>"
    )
endfunction()

set(CMAKE_CXX_STANDARD 23)
set(CMaKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_executable(simple.exe
    simple.cpp)
target_enable_project_warnings(simple.exe)
add_executable(transform_accumulate.exe
    transform_accumulate.cpp)
target_enable_project_warnings(transform_accumulate.exe)
add_executable(classic_stl_to_ranges.exe
    classic_stl_to_ranges.cpp)
target_enable_project_warnings(classic_stl_to_ranges.exe)
add_executable(input_ranges.exe
    input_ranges.cpp)
target_enable_project_warnings(input_ranges.exe)
add_executable(enumerate.exe
    enumerate.cpp)
target_enable_project_warnings(enumerate.exe)
add_executable(projection.exe
    projection.cpp)
target_enable_project_warnings(projection.exe)
add_executable(particle_sort.exe
    particle_sort.cpp)
target_enable_project_warnings(particle_sort.exe)
