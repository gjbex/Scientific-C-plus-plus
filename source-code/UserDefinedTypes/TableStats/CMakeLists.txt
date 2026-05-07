cmake_minimum_required(VERSION 3.20)

project(table_stats CXX)

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

# C++ standard settings
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Common compiler flags

# Link libraries (e.g., -lm for math)
set(COMMON_LIBS m)

# stats executable
add_executable(stats.exe
    stats.cpp
    stats_main.cpp)
target_enable_project_warnings(stats.exe)
target_link_libraries(stats.exe PRIVATE ${COMMON_LIBS})

# table_stats executable
add_executable(table_stats.exe
    stats.cpp
    table_stats.cpp
    table_stats_main.cpp)
target_enable_project_warnings(table_stats.exe)
target_link_libraries(table_stats.exe PRIVATE ${COMMON_LIBS})