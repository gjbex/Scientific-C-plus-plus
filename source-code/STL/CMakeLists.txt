cmake_minimum_required(VERSION 3.16)

project(STLExamples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SOURCES
    list_stl.cpp
    map_stl.cpp
    set_stl.cpp
    map_functions.cpp
    priority_queue_stl.cpp
    vector_stl.cpp
    valarray_stl.cpp
    time.cpp
)

foreach(source_file IN LISTS SOURCES)
    get_filename_component(target_name "${source_file}" NAME_WE)
    add_executable("${target_name}" "${source_file}")
    if(UNIX AND NOT APPLE)
        set_target_properties("${target_name}" PROPERTIES SUFFIX ".exe")
    endif()
endforeach()

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    foreach(source_file IN LISTS SOURCES)
        get_filename_component(target_name "${source_file}" NAME_WE)
        target_compile_options("${target_name}" PRIVATE -Wall -Wextra -Wpedantic)
    endforeach()
endif()
