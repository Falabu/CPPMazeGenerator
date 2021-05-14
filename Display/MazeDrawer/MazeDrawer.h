#ifndef UNTITLED_MAZEDRAWER_H
#define UNTITLED_MAZEDRAWER_H

#include "../../Shared/myTypes.h"

class MazeDrawer {
public:
    virtual ~MazeDrawer() = default;

    virtual void draw(const myTypes::Maze &mazeToDraw, int second) = 0;
};

#endif
