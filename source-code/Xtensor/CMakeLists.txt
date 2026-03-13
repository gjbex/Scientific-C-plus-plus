cmake_minimum_required(VERSION 3.20)
project(xtensor_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
set(FETCHCONTENT_UPDATES_DISCONNECTED ON)

find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)

find_package(xtl CONFIG QUIET)
if(NOT TARGET xtl)
    FetchContent_Declare(
        xtl
        GIT_REPOSITORY https://github.com/xtensor-stack/xtl.git
        GIT_TAG 0.8.1
    )
    FetchContent_MakeAvailable(xtl)
endif()

find_package(xtensor CONFIG QUIET)
if(NOT TARGET xtensor)
    FetchContent_Declare(
        xtensor
        GIT_REPOSITORY https://github.com/xtensor-stack/xtensor.git
        GIT_TAG 0.27.1
    )
    FetchContent_MakeAvailable(xtensor)
endif()

find_package(xtensor-blas CONFIG QUIET)
if(NOT TARGET xtensor-blas)
    FetchContent_Declare(
        xtensor-blas
        GIT_REPOSITORY https://github.com/xtensor-stack/xtensor-blas.git
        GIT_TAG 0.23.0
    )
    FetchContent_MakeAvailable(xtensor-blas)
endif()

add_executable(elementwise.exe elementwise.cpp)
add_executable(svd.exe svd.cpp)

foreach(app elementwise.exe svd.exe)
    target_compile_options(${app} PRIVATE -Wall -Wextra)
    target_link_libraries(${app} PRIVATE m xtensor xtensor-blas)
endforeach()

target_link_libraries(svd.exe PRIVATE ${BLAS_LIBRARIES} ${LAPACK_LIBRARIES})
