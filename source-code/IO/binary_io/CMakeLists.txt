cmake_minimum_required(VERSION 3.20)

project(binary_io LANGUAGES Fortran CXX)

function(target_enable_project_cxx_warnings target)
    if(NOT TARGET "${target}")
        message(FATAL_ERROR "target_enable_project_cxx_warnings called for unknown target: ${target}")
    endif()

    target_compile_options("${target}" PRIVATE
        "$<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang,IntelLLVM>:-Wall>"
        "$<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang,IntelLLVM>:-Wextra>"
        "$<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang,IntelLLVM>:-Wpedantic>"
    )
endfunction()

function(target_enable_project_fortran_warnings target)
    if(NOT TARGET "${target}")
        message(FATAL_ERROR "target_enable_project_fortran_warnings called for unknown target: ${target}")
    endif()

    target_compile_options("${target}" PRIVATE
        "$<$<COMPILE_LANG_AND_ID:Fortran,GNU>:-Wall>"
        "$<$<COMPILE_LANG_AND_ID:Fortran,GNU>:-Wextra>"
    )
endfunction()

set(CMAKE_Fortran_STANDARD 2008)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Boost REQUIRED COMPONENTS program_options)

add_executable(triangular_matrix.exe triangular_matrix.f90)
target_enable_project_fortran_warnings(triangular_matrix.exe)

add_executable(read_triangular_matrix.exe read_triangular_matrix.cpp)
target_enable_project_cxx_warnings(read_triangular_matrix.exe)
target_link_libraries(read_triangular_matrix.exe PRIVATE Boost::program_options)
