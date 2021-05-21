#include "NcursesDisplay.h"


NcursesDisplay::NcursesDisplay() {
    drawer = NcursesMazeDrawer();
}

void NcursesDisplay::init() {
    initscr();

    start_color();
    use_default_colors();

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLACK, COLOR_BLACK);
}

void NcursesDisplay::deInit() {
    endwin();
}

void NcursesDisplay::read() {
    getch();
}

MazeDrawer &NcursesDisplay::getMazeDrawer() {
    return drawer;
}

void NcursesDisplay::writeLine(std::string toWrite) {
    printw(toWrite.c_str());
}
