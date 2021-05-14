cmake_minimum_required(VERSION 3.19)
project(MazeGenerator)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 14)

add_executable(MazeGenerator main.cpp Shared/Point.cpp Shared/Point.h Generator/MazeGenerator.cpp Generator/MazeGenerator.h Shared/myTypes.h Shared/Directions.cpp Shared/Directions.h Maze/MazeElement.cpp Maze/MazeElement.h Randomizer/Randomizer.cpp Randomizer/Randomizer.h Display/Display.h Display/NcursesDisplay.cpp Display/NcursesDisplay.h Display/MazeDrawer/MazeDrawer.h Display/MazeDrawer/NcursesMazeDrawer.cpp Display/MazeDrawer/NcursesMazeDrawer.h Maze/Room.cpp Maze/Room.h Randomizer/RandomNumberGenerator.cpp Randomizer/RandomNumberGenerator.h Generator/MazeGeneratorFactory.cpp Generator/MazeGeneratorFactory.h Maze/Maze.cpp Maze/Maze.h)
target_link_libraries(MazeGenerator ${CURSES_LIBRARIES})