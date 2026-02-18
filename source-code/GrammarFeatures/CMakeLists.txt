cmake_minimum_required(VERSION 3.16)

project(grammar_features LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(if_init.exe if_init.cpp)
add_executable(structured_bindings.exe structured_bindings.cpp)

foreach(target if_init.exe structured_bindings.exe)
  target_compile_options(
    ${target}
    PRIVATE
      -O2
      -g
      -Wall
      -Wextra
      -Wpedantic
  )
endforeach()
