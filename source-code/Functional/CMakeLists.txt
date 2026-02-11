cmake_minimum_required(VERSION 3.20)

project(FunctionalAggregate LANGUAGES CXX)

add_executable(aggregate aggregate.cpp)

target_compile_features(aggregate PRIVATE cxx_std_14)
set_target_properties(aggregate PROPERTIES
  CXX_EXTENSIONS OFF
)

target_compile_options(aggregate PRIVATE
  $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall -Wextra>
)

target_link_libraries(aggregate PRIVATE m)
