#ifndef NCURSESDISPLAY_H
#define NCURSESDISPLAY_H

#include "ncurses.h"
#include "Display.h"
#include "MazeDrawer/NcursesMazeDrawer.h"

class NcursesDisplay : public Display {
public:
    NcursesMazeDrawer drawer;

    NcursesDisplay();

    void init() override;

    void deInit() override;

    void read() override;

    void writeLine(std::string toWrite) override;

    MazeDrawer &getMazeDrawer() override;
};


#endif
