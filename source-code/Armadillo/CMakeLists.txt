cmake_minimum_required(VERSION 3.22)

project(armadillo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})

set(APPLICATIONS
    matrix_product
    read_matrix
    matrix_vector_product
    svd
    elementwise
    inverse
)   

foreach(APP ${APPLICATIONS})
    add_executable(${APP}.exe ${APP}.cpp)
    target_link_libraries(${APP}.exe PRIVATE ${ARMADILLO_LIBRARIES})
    target_compile_options(${APP}.exe PRIVATE -Wall -Wextra -pedantic)
endforeach()
