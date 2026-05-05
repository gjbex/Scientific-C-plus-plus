cmake_minimum_required(VERSION 3.20)
project(Logging LANGUAGES CXX)

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

find_package(Boost CONFIG REQUIRED COMPONENTS log log_setup filesystem)

add_executable(file_logging.exe file_logging.cpp)
target_enable_project_warnings(file_logging.exe)
target_link_libraries(file_logging.exe
    PRIVATE Boost::log Boost::log_setup Boost::filesystem)

add_executable(auto_flush.exe auto_flush.cpp)
target_enable_project_warnings(auto_flush.exe)
target_link_libraries(auto_flush.exe
    PRIVATE Boost::log Boost::log_setup Boost::filesystem)
