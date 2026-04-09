cmake_minimum_required(VERSION 3.20)
project(ocean_view LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(ocean_view src/ocean_view.cpp)
target_include_directories(ocean_view PUBLIC include)
target_compile_options(ocean_view PRIVATE -Wall -Wextra -Wpedantic)

add_executable(ocean_view_test tests/main_test.cpp)
target_link_libraries(ocean_view_test PRIVATE ocean_view)
target_compile_options(ocean_view_test PRIVATE -Wall -Wextra -Wpedantic)

add_executable(ocean_view_timings benchmarks/main_timing.cpp)
target_link_libraries(ocean_view_timings PRIVATE ocean_view)
target_compile_options(ocean_view_timings PRIVATE -Wall -Wextra -Wpedantic)

add_executable(ocean_view_timings2 benchmarks/main_timing2.cpp)
target_link_libraries(ocean_view_timings2 PRIVATE ocean_view)
target_compile_options(ocean_view_timings2 PRIVATE -Wall -Wextra -Wpedantic)
