cmake_minimum_required(VERSION 3.20)

project(stats LANGUAGES CXX)
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

target_compile_options(stats.exe PRIVATE -Wall -Wextra -Wpedantic)
  
# Add exception tests (requires BUILD_TESTING enabled)
if(BUILD_TESTING)
    add_executable(stats_exceptions_test.exe
        test_exceptions.cpp
        simple_stats.cpp
        stats.cpp
    )
    target_compile_options(stats_exceptions_test.exe PRIVATE -Wall -Wextra -Wpedantic)
    add_test(NAME StatsExceptionTests
             COMMAND stats_exceptions_test.exe)

    # Add value correctness tests
    add_executable(stats_values_test.exe
        test_values.cpp
        simple_stats.cpp
        stats.cpp
    )
    target_compile_options(stats_values_test.exe PRIVATE -Wall -Wextra -Wpedantic)
    add_test(NAME StatsValuesTests
             COMMAND stats_values_test.exe)
endif()