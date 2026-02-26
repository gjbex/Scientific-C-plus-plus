cmake_minimum_required(VERSION 3.20)
project(regex_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(APPL strings processes reformat_events simple_re_replace case word_counter)

foreach(app ${APPL})
    add_executable(${app}.exe ${app}.cpp)
    target_compile_options(${app}.exe PRIVATE -Wall)
endforeach()
