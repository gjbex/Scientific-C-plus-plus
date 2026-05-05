cmake_minimum_required(VERSION 3.20)

# Set project name and C++ standard
project(MyExecutables CXX)

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

# List of executable targets
set(APPL
    hello
    talk
    col_dist
    gcd
    fac
    scope
    swap
    arrays
    argument_passing
    local_namespace_use
    data_parser
    arrays_vs_pointers
    cl_arguments
)

# Add an executable for each .cpp file
foreach(app ${APPL})
    add_executable(${app}.exe ${app}.cpp)
target_enable_project_warnings(${app}.exe)
endforeach()
