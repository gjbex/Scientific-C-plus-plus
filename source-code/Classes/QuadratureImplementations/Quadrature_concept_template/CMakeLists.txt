cmake_minimum_required(VERSION 3.16)

project(IntegrateConceptTemplate LANGUAGES CXX)

add_executable(
    quad
    gaussian_quad.cpp
    main_quad.cpp
)

set_target_properties(
    quad
    PROPERTIES
        OUTPUT_NAME quad
        SUFFIX .exe
)

target_compile_features(quad PRIVATE cxx_std_20)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(quad PRIVATE -Wall -Wextra -O2 -g)
endif()

target_link_libraries(quad PRIVATE m)
