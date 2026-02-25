cmake_minimum_required(VERSION 3.20)

project(boost_units_examples LANGUAGES CXX)

if(POLICY CMP0167)
    cmake_policy(SET CMP0167 NEW)
endif()

find_package(Boost CONFIG REQUIRED)

set(common_cxx_options
    -Wall
    -Wextra
    -Wpedantic
)

add_executable(units_okay units_okay.cpp)
set_target_properties(units_okay PROPERTIES OUTPUT_NAME "units_okay.exe")
target_compile_features(units_okay PRIVATE cxx_std_14)
target_compile_options(units_okay PRIVATE ${common_cxx_options})
target_link_libraries(units_okay PRIVATE Boost::headers)

set(not_okay_object "${CMAKE_CURRENT_BINARY_DIR}/units_not_okay.o")
set(not_okay_script
    "${CMAKE_CURRENT_BINARY_DIR}/compile_units_not_okay.cmake"
)
set(not_okay_include_args "")

if(Boost_INCLUDE_DIRS)
    foreach(include_dir IN LISTS Boost_INCLUDE_DIRS)
        string(APPEND not_okay_include_args
            "          -I\n"
            "          \"${include_dir}\"\n"
        )
    endforeach()
else()
    get_target_property(
        boost_header_include_dirs
        Boost::headers
        INTERFACE_INCLUDE_DIRECTORIES
    )
    foreach(include_dir IN LISTS boost_header_include_dirs)
        if(NOT include_dir MATCHES "^\\$<")
            string(APPEND not_okay_include_args
                "          -I\n"
                "          \"${include_dir}\"\n"
            )
        endif()
    endforeach()
endif()

file(WRITE "${not_okay_script}"
"execute_process(\n"
"  COMMAND \"${CMAKE_CXX_COMPILER}\"\n"
"          -std=c++14\n"
"          -Wall\n"
"          -Wextra\n"
"${not_okay_include_args}"
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
