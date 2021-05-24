cmake_minimum_required(VERSION 3.19)

add_library(Generator MazeGenerator.cpp SettingsGenerator.cpp)
target_include_directories(Generator PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Generator PRIVATE "../Randomizer")

target_link_libraries(Generator PRIVATE Common)
target_link_libraries(Generator PRIVATE Maze)
target_link_libraries(Generator PRIVATE Math)