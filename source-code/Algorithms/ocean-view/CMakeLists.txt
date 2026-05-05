cmake_minimum_required(VERSION 3.20)
project(ocean_view LANGUAGES CXX)

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

add_library(ocean_view src/ocean_view.cpp)
target_include_directories(ocean_view PUBLIC include)
target_enable_project_warnings(ocean_view)

add_executable(ocean_view_test tests/main_test.cpp)
target_link_libraries(ocean_view_test PRIVATE ocean_view)
target_enable_project_warnings(ocean_view_test)

add_executable(ocean_view_timings benchmarks/main_timing.cpp)
target_link_libraries(ocean_view_timings PRIVATE ocean_view)
target_enable_project_warnings(ocean_view_timings)

add_executable(ocean_view_timings2 benchmarks/main_timing2.cpp)
target_link_libraries(ocean_view_timings2 PRIVATE ocean_view)
target_enable_project_warnings(ocean_view_timings2)
