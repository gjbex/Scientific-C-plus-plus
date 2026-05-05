cmake_minimum_required(VERSION 3.20)

project(IncludeGuards LANGUAGES CXX)


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

add_executable(with_include_guards
    src_with_guards/matrices.cpp
    src_with_guards/matrix.cpp
    src_with_guards/utils.cpp
)
target_enable_project_warnings(with_include_guards)

target_include_directories(with_include_guards
    PRIVATE
        src_with_guards
)

add_executable(without_include_guards EXCLUDE_FROM_ALL
    src_without_guards/matrices.cpp
    src_without_guards/matrix.cpp
    src_without_guards/utils.cpp
)
target_enable_project_warnings(without_include_guards)

target_include_directories(without_include_guards
    PRIVATE
        src_without_guards
)
