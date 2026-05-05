cmake_minimum_required(VERSION 3.16)

project(namespace_particles LANGUAGES CXX)


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

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

function(add_particles_executable target_name source_file output_name)
    add_executable(${target_name} ${source_file})
    set_target_properties(${target_name} PROPERTIES OUTPUT_NAME ${output_name})
    target_enable_project_warnings(${target_name})
    target_link_libraries(${target_name} PRIVATE particles_lib m)
endfunction()

add_library(particles_lib particle.cpp)
target_enable_project_warnings(particles_lib)

add_particles_executable(particles particles_main.cpp particles.exe)

add_particles_executable(particles_no_using particles_main_no_using.cpp
    particles_no_using.exe)
