cmake_minimum_required(VERSION 3.20)
project(using_c_libraries_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GSL REQUIRED gsl)

set(APPL cannon_max_range minimum)

foreach(app ${APPL})
    add_executable(${app}.exe ${app}.cpp)
    target_compile_options(${app}.exe PRIVATE -Wall -Wextra)
    target_include_directories(${app}.exe PRIVATE ${GSL_INCLUDE_DIRS})
    target_link_directories(${app}.exe PRIVATE ${GSL_LIBRARY_DIRS})
    target_link_libraries(${app}.exe PRIVATE ${GSL_LIBRARIES})
endforeach()
