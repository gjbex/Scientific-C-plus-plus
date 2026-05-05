cmake_minimum_required(VERSION 3.20)
project(tbb_julia_examples LANGUAGES CXX)

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

include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/FetchTBB.cmake)
find_package(OpenMP REQUIRED)

add_executable(julia_abs.exe julia_abs.cpp)
add_executable(julia.exe julia.cpp)
add_executable(julia_tbb.exe julia_tbb.cpp)
add_executable(julia_omp.exe julia_omp.cpp)
add_executable(julia_tasks_omp.exe julia_tasks_omp.cpp)

foreach(app julia_abs.exe julia.exe julia_tbb.exe julia_omp.exe julia_tasks_omp.exe)
target_enable_project_warnings(${app})
    target_link_libraries(${app} PRIVATE m)
endforeach()

target_link_libraries(julia_tbb.exe PRIVATE TBB::tbb)
target_link_libraries(julia_omp.exe PRIVATE OpenMP::OpenMP_CXX)
target_link_libraries(julia_tasks_omp.exe PRIVATE OpenMP::OpenMP_CXX)
