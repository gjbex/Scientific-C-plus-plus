cmake_minimum_required(VERSION 3.20)
project(assembler_quadratic LANGUAGES CXX ASM_NASM)

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

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set_source_files_properties(quad.nsm PROPERTIES LANGUAGE ASM_NASM)

add_executable(quad_calc.exe quad_calc.cpp quad.nsm)
add_executable(timing.exe timing.cpp quad.nsm)
add_executable(quad_calc_inline.exe quad_calc_inline.cpp)

foreach(app quad_calc.exe timing.exe quad_calc_inline.exe)
target_enable_project_warnings(${app})
endforeach()
