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

add_executable(terrain.exe terrain.cpp terrain_main.cpp)
target_enable_project_warnings(terrain.exe)
target_link_libraries(terrain.exe PRIVATE Boost::program_options)

add_executable(los_serial.exe terrain.cpp line_of_sight_serial.cpp)
target_enable_project_warnings(los_serial.exe)

add_executable(visibility_serial.exe terrain.cpp visibility_serial.cpp)
target_enable_project_warnings(visibility_serial.exe)

add_executable(visibility_par.exe terrain.cpp visibility_par.cpp)
target_enable_project_warnings(visibility_par.exe)
target_link_libraries(visibility_par.exe PRIVATE TBB::tbb)
