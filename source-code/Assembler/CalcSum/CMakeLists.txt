cmake_minimum_required(VERSION 3.20)
project(assembler_calc_sum LANGUAGES CXX ASM_NASM)

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

add_executable(calc_sum.exe calc_sum.cpp calc_sum_function.nsm)
add_executable(timing.exe timing.cpp calc_sum_function.nsm)
add_executable(timing_compiler.exe timing.cpp calc_sum_function_compiler.nsm)

set_source_files_properties(
    calc_sum_function.nsm
    calc_sum_function_compiler.nsm
    PROPERTIES LANGUAGE ASM_NASM
)

foreach(app calc_sum.exe timing.exe timing_compiler.exe)
target_enable_project_warnings(${app})
endforeach()
