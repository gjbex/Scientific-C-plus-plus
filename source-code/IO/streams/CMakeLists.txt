cmake_minimum_required(VERSION 3.20)

project(streams LANGUAGES CXX)

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
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(csv2tsv.exe csv2tsv.cpp)
target_enable_project_warnings(csv2tsv.exe)
add_executable(serialization.exe serialization.cpp)
target_enable_project_warnings(serialization.exe)
add_executable(sum.exe sum.cpp)
target_enable_project_warnings(sum.exe)
add_executable(aggregate.exe aggregate.cpp)
target_enable_project_warnings(aggregate.exe)
add_executable(alternative_io.exe alternative_io.cpp)
target_enable_project_warnings(alternative_io.exe)
