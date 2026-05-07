cmake_minimum_required(VERSION 3.20)

project(duck_typing_quadrature LANGUAGES CXX)

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

add_executable(quad.exe)

target_sources(
  quad.exe
  PRIVATE
    gaussian_quad.cpp
    main_quad.cpp
    simpson_quad.cpp
)

target_compile_features(quad.exe PRIVATE cxx_std_14)
target_enable_project_warnings(quad.exe)

# Match Makefile defaults: debug symbols and O2 optimization.
target_compile_options(quad.exe PRIVATE -g -O2)

# Match LDLIBS = -lm in the Makefile.
target_link_libraries(quad.exe PRIVATE m)
