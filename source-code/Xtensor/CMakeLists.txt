cmake_minimum_required(VERSION 3.20)
project(xtensor_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)

set(XTL_INCLUDE_DIR
    "/usr/local/software/xtl/0.5.1/include"
    CACHE PATH "Path to xtl include directory"
)
set(XTENSOR_INCLUDE_DIR
    "/usr/local/software/xtensor/0.19.1/include"
    CACHE PATH "Path to xtensor include directory"
)
set(XTENSOR_BLAS_INCLUDE_DIR
    "/usr/local/software/xtensor-blas/0.15.0/include"
    CACHE PATH "Path to xtensor-blas include directory"
)

add_executable(elementwise.exe elementwise.cpp)
add_executable(svd.exe svd.cpp)

foreach(app elementwise.exe svd.exe)
    target_compile_options(${app} PRIVATE -Wall -Wextra)
    target_include_directories(
        ${app} PRIVATE
        ${XTL_INCLUDE_DIR}
        ${XTENSOR_INCLUDE_DIR}
        ${XTENSOR_BLAS_INCLUDE_DIR}
    )
    target_link_libraries(${app} PRIVATE m)
endforeach()

target_link_libraries(svd.exe PRIVATE ${BLAS_LIBRARIES} ${LAPACK_LIBRARIES})
