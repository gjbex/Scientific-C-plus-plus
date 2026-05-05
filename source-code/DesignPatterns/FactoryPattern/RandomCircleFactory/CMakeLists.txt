cmake_minimum_required(VERSION 3.20)
project(random_circle_factory LANGUAGES CXX)

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

add_executable(
    random_circles.exe
    circle.cpp
    circle_factory.cpp
    random_circles.cpp
)
add_executable(circle_overlap.exe circle.cpp circle_overlap.cpp)

foreach(app random_circles.exe circle_overlap.exe)
target_enable_project_warnings(${app})
    target_link_libraries(${app} PRIVATE m)
endforeach()

set(OVERLAP_DATA ${CMAKE_CURRENT_BINARY_DIR}/overlap_data.txt)

add_custom_command(
    OUTPUT ${OVERLAP_DATA}
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/generate_overlap_data.sh > ${OVERLAP_DATA}
    DEPENDS random_circles.exe circle_overlap.exe
            ${CMAKE_CURRENT_SOURCE_DIR}/generate_overlap_data.sh
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    VERBATIM
)

add_custom_target(data DEPENDS ${OVERLAP_DATA})

add_custom_target(
    plot
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/plot_overlap_data.plt
    DEPENDS data ${CMAKE_CURRENT_SOURCE_DIR}/plot_overlap_data.plt
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    VERBATIM
)
