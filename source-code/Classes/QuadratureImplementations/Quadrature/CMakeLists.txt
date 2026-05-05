cmake_minimum_required(VERSION 3.16)

project(quadrature LANGUAGES CXX)

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
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(quad
    simpson_quad.cpp
    gaussian_quad.cpp
    main_quad.cpp
)

# Match the Makefile output name.
set_target_properties(quad PROPERTIES OUTPUT_NAME "quad.exe")

# Match Makefile warning flags.
target_enable_project_warnings(quad)

# Link against libm as in LDLIBS = -lm.
target_link_libraries(quad PRIVATE m)
