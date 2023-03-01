cmake_minimum_required(VERSION 3.0)
project(algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMaKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(find_if.exe
    find_if.cpp)
add_executable(permutations.exe
    permutations.cpp)
add_executable(generate.exe
    generate.cpp)
add_executable(for_each.exe
    for_each.cpp)
add_executable(particle_sort.exe
    particle_sort.cpp)
add_executable(count_clamp.exe
    count_clamp.cpp)
add_executable(find_words.exe
    find_words.cpp)
add_executable(zip_it.exe
    zip_it.cpp)
add_executable(accumulate.exe
    accumulate.cpp)
add_executable(distance.exe
    distance.cpp)
add_executable(iota.exe
    iota.cpp)
add_executable(transform.exe
    transform.cpp)
add_executable(points.exe
    points.cpp)
