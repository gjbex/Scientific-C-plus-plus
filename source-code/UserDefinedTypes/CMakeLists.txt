cmake_minimum_required(VERSION 3.20)

project(UserDefinedTypes LANGUAGES CXX)

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
  target_enable_project_warnings("${target_name}")
  set_target_properties("${target_name}" PROPERTIES
    OUTPUT_NAME "${target_name}.exe"
  )
  target_link_libraries("${target_name}" PRIVATE m)
endforeach()
