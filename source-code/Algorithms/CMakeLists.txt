cmake_minimum_required(VERSION 3.20)
project(algorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMaKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

set(APPLICATIONS
    find_if
    permutations
    generate
    for_each
    particle_sort
    count_clamp
    find_words
    zip_it
    accumulate
    distance
    iota
    transform
    points)

foreach(APP ${APPLICATIONS})
    add_executable(${APP}.exe
        ${APP}.cpp)
    target_compile_options(${APP}.exe PRIVATE -Wall -Wextra -Wpedantic)
endforeach()
