#include "NcursesDisplay.h"


NcursesDisplay::NcursesDisplay() {
    drawer = NcursesMazeDrawer();
}

void NcursesDisplay::init() {
    initscr();
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
