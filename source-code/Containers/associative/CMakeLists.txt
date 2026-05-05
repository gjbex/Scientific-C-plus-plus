cmake_minimum_required(VERSION 3.20)

project(associative_examples LANGUAGES CXX)

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


set(ASSOCIATIVE_EXAMPLES
    aggregate_data
    dim_nr_counts
    dim_nrs
    distinct_words
    set
    word_frequencies
)

foreach(app ${ASSOCIATIVE_EXAMPLES})
    add_executable(${app}.exe ${app}.cpp)
target_enable_project_warnings(${app}.exe)
endforeach()
