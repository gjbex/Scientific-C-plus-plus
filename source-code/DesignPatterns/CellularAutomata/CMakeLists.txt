cmake_minimum_required(VERSION 3.20)

project(cellular_automata LANGUAGES CXX)

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

if(POLICY CMP0167)
    cmake_policy(SET CMP0167 NEW)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

find_package(Boost REQUIRED COMPONENTS program_options)

add_executable(cellular_automata.exe
    cells.cpp
    collective_dynamics.cpp
    cycle_finder.cpp
    random_cells_factory.cpp
    rule.cpp
    runners.cpp
    uniform_cells_factory.cpp
    utils.cpp
    visualization_runner.cpp
    main.cpp)
target_enable_project_warnings(cellular_automata.exe)
target_link_libraries(cellular_automata.exe PRIVATE Boost::program_options)
