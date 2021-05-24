cmake_minimum_required(VERSION 3.19)

add_library(Args Args.cpp)
target_include_directories(Args PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
