cmake_minimum_required(VERSION 3.20)
project(memory_leak_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(APPL memory_leak memory_leak_fixed)

foreach(app ${APPL})
    add_executable(${app}.exe ${app}.cpp)
    target_compile_options(${app}.exe PRIVATE -Wall -Wextra)
    target_link_libraries(${app}.exe PRIVATE m)
endforeach()
