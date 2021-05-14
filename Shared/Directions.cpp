#include "Directions.h"

Point Directions::NORTH{0, -1};
Point Directions::EAST{1, 0};
Point Directions::SOUTH{0, 1};
Point Directions::WEST{-1, 0};

Point Directions::NORTH_WEST{-1, -1};
Point Directions::NORTH_EAST{1, -1};
Point Directions::SOUTH_EAST{1, 1};
Point Directions::SOUTH_WEST{-1, 1};

std::vector<Point> Directions::ordinalDirections{NORTH, EAST, SOUTH, WEST};
std::vector<Point> Directions::cardinalDirections{NORTH_WEST, NORTH_EAST, SOUTH_EAST, SOUTH_WEST};