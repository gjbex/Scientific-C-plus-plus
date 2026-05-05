cmake_minimum_required(VERSION 3.16)

project(STLExamples LANGUAGES CXX)

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
target_enable_project_warnings(${target_name})
    endforeach()
endif()
