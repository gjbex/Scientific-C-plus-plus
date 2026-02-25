cmake_minimum_required(VERSION 3.16)

project(quadrature LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(quad
    simpson_quad.cpp
    gaussian_quad.cpp
    main_quad.cpp
)

# Match the Makefile output name.
set_target_properties(quad PROPERTIES OUTPUT_NAME "quad.exe")

# Match Makefile warning flags.
target_compile_options(quad PRIVATE
    -Wall
    -Wextra
)

# Link against libm as in LDLIBS = -lm.
target_link_libraries(quad PRIVATE m)
