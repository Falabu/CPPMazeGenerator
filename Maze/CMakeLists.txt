cmake_minimum_required(VERSION 3.19)

add_library(Maze Maze.cpp MazeElement.cpp Room.cpp)
target_include_directories(Maze PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(Maze PRIVATE Common)
target_link_libraries(Maze PRIVATE Math)