cmake_minimum_required(VERSION 3.31)
project(immediately_invoked_function_expression LANGUAGES CXX)

add_executable(iife.exe iife.cpp)
set_target_properties(iife.exe PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED YES)
target_compile_options(iife.exe PRIVATE
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic>)
