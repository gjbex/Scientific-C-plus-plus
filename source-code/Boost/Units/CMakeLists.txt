cmake_minimum_required(VERSION 3.20)

project(boost_units_examples LANGUAGES CXX)

set(common_cxx_options
    -Wall
    -Wextra
)

add_executable(units_okay units_okay.cpp)
set_target_properties(units_okay PROPERTIES OUTPUT_NAME "units_okay.exe")
target_compile_features(units_okay PRIVATE cxx_std_14)
target_compile_options(units_okay PRIVATE ${common_cxx_options})

set(not_okay_object "${CMAKE_CURRENT_BINARY_DIR}/units_not_okay.o")
set(not_okay_script
    "${CMAKE_CURRENT_BINARY_DIR}/compile_units_not_okay.cmake"
)

file(WRITE "${not_okay_script}"
"execute_process(\n"
"  COMMAND \"${CMAKE_CXX_COMPILER}\"\n"
"          -std=c++14\n"
"          -Wall\n"
"          -Wextra\n"
"          -c\n"
"          \"${CMAKE_CURRENT_SOURCE_DIR}/units_not_okay.cpp\"\n"
"          -o\n"
"          \"${not_okay_object}\"\n"
"  RESULT_VARIABLE compile_result\n"
")\n"
"if(NOT compile_result EQUAL 0)\n"
"  message(STATUS\n"
"    \"units_not_okay.cpp failed to compile; continuing to match Makefile.\"\n"
"  )\n"
"endif()\n"
)

add_custom_target(not_okay
    COMMAND ${CMAKE_COMMAND} -P "${not_okay_script}"
    BYPRODUCTS "${not_okay_object}"
    COMMENT "Compiling units_not_okay.cpp (errors ignored)"
    VERBATIM
)
