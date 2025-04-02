cmake_minimum_required(VERSION 3.20)

project(eigen LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(APPLICATIONS
    matrix_product
    read_matrix
    solve_eqns)

foreach(APP ${APPLICATIONS})
    add_executable(${APP}.exe
        ${APP}.cpp)
    target_include_directories(${APP}.exe
        PRIVATE ${EIGEN_INCLUDE_DIR})
endforeach()
