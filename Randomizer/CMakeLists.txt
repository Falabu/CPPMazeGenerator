cmake_minimum_required(VERSION 3.19)
project(Randomizer)

add_library(Randomizer Randomizer.cpp)

target_include_directories(Randomizer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(Randomizer PRIVATE Common)
target_link_libraries(Randomizer PRIVATE Math)