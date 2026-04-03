cmake_minimum_required(VERSION 3.14)

project(duck_typing_quadrature_template LANGUAGES CXX)

add_executable(quad.exe)

target_sources(
  quad.exe
  PRIVATE
    gaussian_quad.cpp
    main_quad.cpp
)

target_compile_features(quad.exe PRIVATE cxx_std_14)
target_compile_options(quad.exe PRIVATE -Wall -Wextra -g -O2)
target_link_libraries(quad.exe PRIVATE m)
