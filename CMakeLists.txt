cmake_minimum_required(VERSION 3.19)
project(MazeGenerator)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 17)

add_executable(MazeGenerator main.cpp Math/Point.h Generator/MazeGenerator.cpp Generator/MazeGenerator.h Maze/Directions.h Maze/MazeElement.cpp Maze/MazeElement.h Randomizer/Randomizer.cpp Randomizer/Randomizer.h Display/Display.h Display/NcursesDisplay.cpp Display/NcursesDisplay.h Display/MazeDrawer/MazeDrawer.h Display/MazeDrawer/NcursesMazeDrawer.cpp Display/MazeDrawer/NcursesMazeDrawer.h Maze/Room.cpp Maze/Room.h Randomizer/NumberGenerator.cpp Randomizer/NumberGenerator.h Maze/Maze.cpp Maze/Maze.h Generator/SettingsGenerator.cpp Generator/SettingsGenerator.h Math/Math.h Math/Rect.h Maze/Types.h Args/Args.cpp Args/Args.h App.cpp App.h)
target_link_libraries(MazeGenerator ${CURSES_LIBRARIES})