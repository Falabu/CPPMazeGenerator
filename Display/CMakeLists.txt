cmake_minimum_required(VERSION 3.19)

add_library(Display NcursesDisplay.cpp MazeDrawer/NcursesMazeDrawer.cpp)
target_include_directories(Display PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Display PRIVATE MazeDrawer)

target_link_libraries(Display PRIVATE Math)
target_link_libraries(Display PRIVATE Common)
target_link_libraries(Display PUBLIC ${CURSES_LIBRARIES})
