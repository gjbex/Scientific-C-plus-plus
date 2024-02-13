cmake_minimum_required(VERSION 3.22)

project(boost_process LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(Boost_USE_MULTITHREADED ON)
find_package(Boost REQUIRED COMPONENTS system filesystem)

add_executable(ls_boost.exe ls.cpp)
target_link_libraries(ls_boost.exe Boost::system Boost::filesystem)
add_executable(bc_boost.exe bc.cpp)
target_link_libraries(bc_boost.exe Boost::system Boost::filesystem)
add_executable(env_boost.exe env.cpp)
target_link_libraries(env_boost.exe Boost::system Boost::filesystem)
