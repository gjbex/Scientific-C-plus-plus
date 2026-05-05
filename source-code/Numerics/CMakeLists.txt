cmake_minimum_required(VERSION 3.20)

project(numerics LANGUAGES CXX)

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

add_executable(complex.exe complex.cpp)
target_enable_project_warnings(complex.exe)
add_executable(julia.exe julia.cpp)
target_enable_project_warnings(julia.exe)
add_executable(limits.exe limits.cpp)
target_enable_project_warnings(limits.exe)
add_executable(numbers_pi_versus_M_PI.exe numbers_pi_versus_M_PI.cpp)
target_enable_project_warnings(numbers_pi_versus_M_PI.exe)
add_executable(random.exe random.cpp)
target_enable_project_warnings(random.exe)
add_executable(multiple_distr.exe multiple_distr.cpp)
target_enable_project_warnings(multiple_distr.exe)
