cmake_minimum_required(VERSION 3.20)
project(tbb_examples LANGUAGES CXX)

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

include(cmake/FetchTBB.cmake)

set(
    APPL
    simplest_parallel_for
    simple_parallel_for
    simple_parallel_reduce
    vector_parallel_reduce
    grain_size_parallel_for
    stats_parallel_reduce
    trivial_parallel_for
    trivial_parallel_reduce
    fibonacci_tasks
    flow_graph
)

foreach(app ${APPL})
    add_executable(${app}.exe ${app}.cpp)
target_enable_project_warnings(${app}.exe)
    target_link_libraries(${app}.exe PRIVATE TBB::tbb m)
endforeach()
