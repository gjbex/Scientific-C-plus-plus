cmake_minimum_required(VERSION 3.20)

project(Templates LANGUAGES CXX)

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

# Match Makefile output naming convention.
set(CMAKE_EXECUTABLE_SUFFIX .exe)

add_compile_options(-O2 -g)

set(APPLICATIONS
    swap
    sum
    points
    print_container_no_range_for
    fac
)

foreach(app IN LISTS APPLICATIONS)
    add_executable(${app} ${app}.cpp)
    target_enable_project_warnings(${app})
    target_link_libraries(${app} PRIVATE m)
endforeach()
