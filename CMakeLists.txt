cmake_minimum_required(VERSION 3.19)
project(MazeGenerator)
find_package(Curses REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Args)
add_subdirectory(Common)
add_subdirectory(Math)
add_subdirectory(Display)
add_subdirectory(Maze)
add_subdirectory(Generator)
add_subdirectory(Randomizer)

add_executable(MazeGenerator main.cpp)
target_include_directories(MazeGenerator PUBLIC Args Display Math Generator Maze Randomizer Common)

target_link_libraries(MazeGenerator PUBLIC ${CURSES_LIBRARIES})

target_link_libraries(MazeGenerator PRIVATE Args)
target_link_libraries(MazeGenerator PRIVATE Display)
target_link_libraries(MazeGenerator PRIVATE Randomizer)
target_link_libraries(MazeGenerator PRIVATE Generator)
target_link_libraries(MazeGenerator PRIVATE Maze)

