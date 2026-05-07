cmake_minimum_required(VERSION 3.20)
project(ProgramOptions LANGUAGES CXX)

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
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSION NO)

if(POLICY CMP0167)
    cmake_policy(SET CMP0167 NEW)
endif()

find_package(Boost CONFIG REQUIRED COMPONENTS program_options)

add_executable(random.exe random.cpp)
target_enable_project_warnings(random.exe)
target_link_libraries(random.exe PRIVATE Boost::program_options)

add_executable(random_default.exe random_default.cpp)
target_enable_project_warnings(random_default.exe)
target_link_libraries(random_default.exe PRIVATE Boost::program_options)
