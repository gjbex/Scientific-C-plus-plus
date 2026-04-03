cmake_minimum_required(VERSION 3.20)

project(numeric_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(COMMON_FLAGS -Wall -Wextra -Wpedantic)
set(COMMON_LIBS m)

set(NUMERIC_EXAMPLES
    cosine_similarity
    kaprekar
    point_distances
    stats
    synthesizer
)

foreach(app ${NUMERIC_EXAMPLES})
    add_executable(${app}.exe ${app}.cpp)
    target_compile_options(${app}.exe PRIVATE ${COMMON_FLAGS})
    target_link_libraries(${app}.exe PRIVATE ${COMMON_LIBS})
endforeach()
