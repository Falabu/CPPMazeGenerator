#ifndef DIRECTIONS_H
#define DIRECTIONS_H

#include "../Math/Point.h"
#include <vector>

namespace myMaze::Directions {
    static const myMath::Point north{0, -1};
    static const myMath::Point east{1, 0};
    static const myMath::Point south{0, 1};
    static const myMath::Point west{-1, 0};

    static const myMath::Point north_west{-1, -1};
    static const myMath::Point north_east{-1, -1};
    static const myMath::Point south_east{1, 1};
    static const myMath::Point south_west{-1, 1};

    static const std::vector<myMath::Point> ordinalDirections{north, east, south, west};
    static const std::vector<myMath::Point> cardinalDirections{north_west, north_east, south_east, south_west};
    static const std::vector<myMath::Point> allDirections{north,
                                                          east,
                                                          south,
                                                          west,
                                                          north_west,
                                                          north_east,
                                                          south_east,
                                                          south_west};

};

#endif
