cmake_minimum_required(VERSION 3.20)

project(armadillo LANGUAGES CXX)

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
target_enable_project_warnings(${APP}.exe)
endforeach()
