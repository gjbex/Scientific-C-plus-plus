cmake_minimum_required(VERSION 3.20)
project(pointers LANGUAGES CXX)

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

set(CMAKE_CXX_STANDARD 17)
set(CMaKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_executable(runtime_vs_compile_time.exe
    runtime_vs_compile_time.cpp)
target_enable_project_warnings(runtime_vs_compile_time.exe)
add_executable(pointers_vs_references.exe
    pointers_vs_references.cpp)
target_enable_project_warnings(pointers_vs_references.exe)
add_executable(const_and_pointers.exe
    const_and_pointers.cpp)
target_enable_project_warnings(const_and_pointers.exe)
