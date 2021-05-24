cmake_minimum_required(VERSION 3.19)
project(Math)

add_library(Math INTERFACE)
target_include_directories(Math INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
