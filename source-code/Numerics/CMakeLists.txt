cmake_minimum_required(VERSION 3.20)

project(numerics LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(complex.exe complex.cpp)
add_executable(julia.exe julia.cpp)
add_executable(limits.exe limits.cpp)
add_executable(numbers_pi_versus_M_PI.exe numbers_pi_versus_M_PI.cpp)
add_executable(random.exe random.cpp)
add_executable(multiple_distr.exe multiple_distr.cpp)
