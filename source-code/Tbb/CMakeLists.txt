cmake_minimum_required(VERSION 3.20)
project(tbb_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(TBB REQUIRED)

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
    target_compile_options(${app}.exe PRIVATE -Wall -Wextra)
    target_link_libraries(${app}.exe PRIVATE TBB::tbb m)
endforeach()
