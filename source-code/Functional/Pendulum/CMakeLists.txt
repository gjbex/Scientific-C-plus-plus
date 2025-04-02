cmake_minimum_required(VERSION 3.20)

project(closures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(APPL
    pendulum_bind
    pendulum_lambda
    pendulum_func_obj)

foreach(APP ${APPL})
    add_executable(${APP}.exe
        ${APP}.cpp
        pendulum_utils.cpp)
    target_compile_options(${APP}.exe
        PRIVATE -Wall -Wextra -Wpedantic)
endforeach()
