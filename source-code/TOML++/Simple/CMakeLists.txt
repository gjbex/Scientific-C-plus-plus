cmake_minimum_required(VERSION 3.20)

project(tomlpp_example LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

FetchContent_Declare(
    tomlplusplus
    GIT_REPOSITORY https://github.com/marzer/tomlplusplus.git
    GIT_TAG        v3.4.0
)

FetchContent_MakeAvailable(tomlplusplus)

add_executable(config_demo.exe
    main.cpp
)

target_link_libraries(config_demo.exe
    PRIVATE
        tomlplusplus::tomlplusplus
)
