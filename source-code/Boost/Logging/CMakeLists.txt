cmake_minimum_required(VERSION 3.0)
project(Logging LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSION NO)

add_compile_options(-Wall -Wextra -Wpedantic)

find_package(Boost COMPONENTS log log_setup filesystem)
if (NOT Boost_FOUND)
    message(FATAL_ERROR "Boost is required but can't be found")
endif (NOT Boost_FOUND)

add_executable(file_logging.exe file_logging.cpp)
target_include_directories(file_logging.exe PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(file_logging.exe LINK_PRIVATE ${Boost_LIBRARIES})

add_executable(auto_flush.exe auto_flush.cpp)
target_include_directories(auto_flush.exe PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(auto_flush.exe LINK_PRIVATE ${Boost_LIBRARIES})
