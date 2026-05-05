cmake_minimum_required(VERSION 3.22)

project(boost_process LANGUAGES CXX)


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

if(POLICY CMP0167)
    cmake_policy(SET CMP0167 NEW)
endif()

find_package(Boost CONFIG REQUIRED COMPONENTS system filesystem)

add_executable(ls_boost.exe ls.cpp)
target_enable_project_warnings(ls_boost.exe)
target_link_libraries(ls_boost.exe PRIVATE Boost::system Boost::filesystem)
add_executable(bc_boost.exe bc.cpp)
target_enable_project_warnings(bc_boost.exe)
target_link_libraries(bc_boost.exe PRIVATE Boost::system Boost::filesystem)
add_executable(env_boost.exe env.cpp)
target_enable_project_warnings(env_boost.exe)
target_link_libraries(env_boost.exe PRIVATE Boost::system Boost::filesystem)
