#ifndef UNTITLED_MAZEDRAWER_H
#define UNTITLED_MAZEDRAWER_H

#include "../../Maze/Types.h"

class MazeDrawer {
public:
    virtual ~MazeDrawer() = default;

    virtual void draw(const myMaze::MazeElements &mazeToDraw) = 0;
};

#endif
