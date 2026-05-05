cmake_minimum_required(VERSION 3.20)
project(using_c_libraries_examples LANGUAGES CXX)

function(target_enable_project_warnings target)
    if(NOT TARGET "${target}")
        message(FATAL_ERROR "target_enable_project_warnings called for unknown target: ${target}")
    endif()

    target_compile_options("${target}" PRIVATE
        "$<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang,IntelLLVM>:-Wall>"
        "$<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang,IntelLLVM>:-Wextra>"
        "$<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang,IntelLLVM>:-Wpedantic>"
    )
endfunction()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GSL REQUIRED gsl)

set(APPL cannon_max_range minimum)

foreach(app ${APPL})
    add_executable(${app}.exe ${app}.cpp)
target_enable_project_warnings(${app}.exe)
    target_include_directories(${app}.exe PRIVATE ${GSL_INCLUDE_DIRS})
    target_link_directories(${app}.exe PRIVATE ${GSL_LIBRARY_DIRS})
    target_link_libraries(${app}.exe PRIVATE ${GSL_LIBRARIES})
endforeach()
