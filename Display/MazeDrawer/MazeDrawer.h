#ifndef UNTITLED_MAZEDRAWER_H
#define UNTITLED_MAZEDRAWER_H

#include "../../Maze/Types.h"

class MazeDrawer {
public:
    virtual ~MazeDrawer() = default;

    virtual void draw(const myMaze::MazeElements &mazeToDraw, int second) = 0;
};

#endif
