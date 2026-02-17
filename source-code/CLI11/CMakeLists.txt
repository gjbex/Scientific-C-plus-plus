cmake_minimum_required(VERSION 3.20)
project(random_numbers LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
    cli11_proj
    QUIET
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.3.2
)

FetchContent_MakeAvailable(cli11_proj)

add_executable(random_default.exe
    random_default.cpp
)
target_link_libraries(random_default.exe PRIVATE CLI11::CLI11)
