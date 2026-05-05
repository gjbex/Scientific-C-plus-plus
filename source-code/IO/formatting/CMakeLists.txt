cmake_minimum_required(VERSION 3.20)

project(formatting LANGUAGES CXX)


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

include(CheckIncludeFileCXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

check_include_file_cxx(print HAVE_PRINT_HEADER)

add_executable(iomanip_formatting.exe iomanip_formatting.cpp)
target_enable_project_warnings(iomanip_formatting.exe)
add_executable(std_format.exe std_format.cpp)
target_enable_project_warnings(std_format.exe)

if(HAVE_PRINT_HEADER)
    add_executable(print_format.exe print_format.cpp)
    target_enable_project_warnings(print_format.exe)
else()
    message(STATUS "Skipping print_format.exe because <print> is not available")
endif()
