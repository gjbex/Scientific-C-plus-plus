cmake_minimum_required(VERSION 3.16)

project(UserDefinedTypes LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(EXECUTABLE_SOURCES
  struct_particles.cpp
  class_particles.cpp
  charged_particles.cpp
  streaming_stats.cpp
  function_objects.cpp
  placement_new.cpp
)

foreach(source_file IN LISTS EXECUTABLE_SOURCES)
  get_filename_component(target_name "${source_file}" NAME_WE)
  add_executable("${target_name}" "${source_file}")
  set_target_properties("${target_name}" PROPERTIES
    OUTPUT_NAME "${target_name}.exe"
  )
  target_link_libraries("${target_name}" PRIVATE m)
endforeach()
