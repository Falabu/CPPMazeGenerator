#ifndef DISPLAY_H
#define DISPLAY_H

#include "MazeDrawer/MazeDrawer.h"

class Display {
public:
    ~Display() = default;

    virtual void init() = 0;

    virtual void deInit() = 0;

    virtual void read() = 0;

    virtual MazeDrawer &getMazeDrawer() = 0;
};


#endif
