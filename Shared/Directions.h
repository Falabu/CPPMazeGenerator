#ifndef DIRECTIONS_H
#define DIRECTIONS_H

#include "../Shared/Point.h"
#include <vector>

class Directions {
public:
    static Point NORTH;
    static Point EAST;
    static Point SOUTH;
    static Point WEST;

    static Point NORTH_WEST;
    static Point NORTH_EAST;
    static Point SOUTH_EAST;
    static Point SOUTH_WEST;

    static std::vector<Point> ordinalDirections;
    static std::vector<Point> cardinalDirections;
};

#endif
