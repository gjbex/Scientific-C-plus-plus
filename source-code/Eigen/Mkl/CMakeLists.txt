cmake_minimum_required(VERSION 3.20)
project(eigen_mkl_example LANGUAGES CXX)

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

find_package(Eigen3 REQUIRED)

if(NOT DEFINED ENV{MKLROOT})
    message(FATAL_ERROR "MKLROOT must be set to build this example")
endif()

set(MKLROOT_DIR $ENV{MKLROOT})

add_executable(matrix_product.exe matrix_product.cpp)
target_enable_project_warnings(matrix_product.exe)
target_include_directories(
    matrix_product.exe PRIVATE
    ${EIGEN3_INCLUDE_DIR}
    ${MKLROOT_DIR}/include
)
target_link_directories(matrix_product.exe PRIVATE ${MKLROOT_DIR}/lib/intel64)
target_link_libraries(
    matrix_product.exe PRIVATE
    mkl_intel_lp64
    mkl_tbb_thread
    mkl_core
    tbb
    stdc++
    pthread
    m
    dl
)
