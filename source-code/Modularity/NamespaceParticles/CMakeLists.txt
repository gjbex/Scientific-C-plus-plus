cmake_minimum_required(VERSION 3.16)

project(namespace_particles LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

set(PARTICLES_WARNING_FLAGS
    $<$<COMPILE_LANG_AND_ID:CXX,Clang,AppleClang,GNU>:-Wall>
    $<$<COMPILE_LANG_AND_ID:CXX,Clang,AppleClang,GNU>:-Wextra>
    $<$<COMPILE_LANG_AND_ID:CXX,Clang,AppleClang,GNU>:-Wpedantic>
)

function(add_particles_executable target_name source_file output_name)
    add_executable(${target_name} ${source_file})
    set_target_properties(${target_name} PROPERTIES OUTPUT_NAME ${output_name})
    target_compile_options(${target_name} PRIVATE ${PARTICLES_WARNING_FLAGS})
    target_link_libraries(${target_name} PRIVATE particles_lib m)
endfunction()

add_library(particles_lib particle.cpp)
target_compile_options(particles_lib PRIVATE ${PARTICLES_WARNING_FLAGS})

add_particles_executable(particles particles_main.cpp particles.exe)

add_particles_executable(particles_no_using particles_main_no_using.cpp
    particles_no_using.exe)
