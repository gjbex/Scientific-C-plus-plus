cmake_minimum_required(VERSION 3.20)

project(stats LANGUAGES CXX)

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

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(stats.exe
    main_stats.cpp
    simple_stats.cpp
    stats.cpp
)

target_enable_project_warnings(stats.exe)
  
# Add exception tests (requires BUILD_TESTING enabled)
if(BUILD_TESTING)
    add_executable(stats_exceptions_test.exe
        test_exceptions.cpp
        simple_stats.cpp
        stats.cpp
    )
target_enable_project_warnings(stats_exceptions_test.exe)
    add_test(NAME StatsExceptionTests
             COMMAND stats_exceptions_test.exe)

    # Add value correctness tests
    add_executable(stats_values_test.exe
        test_values.cpp
        simple_stats.cpp
        stats.cpp
    )
target_enable_project_warnings(stats_values_test.exe)
    add_test(NAME StatsValuesTests
             COMMAND stats_values_test.exe)
endif()