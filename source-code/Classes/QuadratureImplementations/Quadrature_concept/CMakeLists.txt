cmake_minimum_required(VERSION 3.16)

project(IntegrateConcept LANGUAGES CXX)

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

add_executable(
    quad
    gaussian_quad.cpp
    main_quad.cpp
    simpson_quad.cpp
)

set_target_properties(
    quad
    PROPERTIES
        OUTPUT_NAME quad
        SUFFIX .exe
)

target_compile_features(quad PRIVATE cxx_std_20)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(quad PRIVATE -O2 -g)
endif()
target_enable_project_warnings(quad)

target_link_libraries(quad PRIVATE m)
