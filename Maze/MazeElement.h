#ifndef MAZEPOINT_H
#define MAZEPOINT_H

#include "../Shared/Point.h"
#include "ncurses.h"

enum MazeElementsTypes {
    empty = 0,
    corridor = 1,
    room = 2
};

class MazeElement {
public:
    MazeElement();

    explicit MazeElement(const Point &point);

    bool isInMaze() const;

    void setCoordinate(const Point &point);

    void set(MazeElementsTypes _type);

    MazeElementsTypes getType() const;

private:
    MazeElementsTypes type;
    Point coordinate;
    bool inMaze{false};
};

#endif
