cmake_minimum_required(VERSION 3.16)

project(namespace_particles LANGUAGES CXX)

add_library(particles_lib particle.cpp)
set_target_properties(particles_lib PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
target_compile_features(particles_lib PRIVATE cxx_std_14)
target_compile_options(particles_lib PRIVATE
    $<$<COMPILE_LANG_AND_ID:CXX,Clang,AppleClang,GNU>:-Wall>
    $<$<COMPILE_LANG_AND_ID:CXX,Clang,AppleClang,GNU>:-Wextra>
    $<$<COMPILE_LANG_AND_ID:CXX,Clang,AppleClang,GNU>:-Wpedantic>
)

add_executable(particles particles_main.cpp)
set_target_properties(particles PROPERTIES
    OUTPUT_NAME "particles.exe"
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
target_compile_options(particles PRIVATE
    $<$<COMPILE_LANG_AND_ID:CXX,Clang,AppleClang,GNU>:-Wall>
    $<$<COMPILE_LANG_AND_ID:CXX,Clang,AppleClang,GNU>:-Wextra>
    $<$<COMPILE_LANG_AND_ID:CXX,Clang,AppleClang,GNU>:-Wpedantic>
)
target_link_libraries(particles PRIVATE particles_lib)
target_link_libraries(particles PRIVATE m) 
