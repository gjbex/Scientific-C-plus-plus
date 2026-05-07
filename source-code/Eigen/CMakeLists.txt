cmake_minimum_required(VERSION 3.20)

project(eigen LANGUAGES CXX)


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

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(APPLICATIONS
    matrix_product
    read_matrix
    solve_eqns)

foreach(APP ${APPLICATIONS})
    add_executable(${APP}.exe
        ${APP}.cpp)
    target_enable_project_warnings(${APP}.exe)
    target_include_directories(${APP}.exe
        PRIVATE ${EIGEN_INCLUDE_DIR})
endforeach()
