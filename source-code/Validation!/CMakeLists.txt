cmake_minimum_required(VERSION 3.20)

project(validation_examples LANGUAGES CXX)

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

if(POLICY CMP0167)
    cmake_policy(SET CMP0167 NEW)
endif()

find_package(Boost CONFIG REQUIRED)

add_executable(explicit_euler.exe explicit_euler.cpp command_line_options.cpp)
target_enable_project_warnings(explicit_euler.exe)

add_executable(boost_velocity_verlet.exe boost_velocity_verlet.cpp command_line_options.cpp)
target_enable_project_warnings(boost_velocity_verlet.exe)
target_link_libraries(boost_velocity_verlet.exe PRIVATE Boost::headers)
