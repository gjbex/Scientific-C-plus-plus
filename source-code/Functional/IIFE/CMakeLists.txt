cmake_minimum_required(VERSION 3.20)
project(immediately_invoked_function_expression LANGUAGES CXX)

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

add_executable(iife.exe iife.cpp)
set_target_properties(iife.exe PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED YES)
target_enable_project_warnings(iife.exe)
