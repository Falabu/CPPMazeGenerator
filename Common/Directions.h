#ifndef DIRECTIONS_H
#define DIRECTIONS_H

#include "Point.hpp"
#include <array>

namespace myMaze::Directions {
    constexpr MazeMath::Point north{0, -1};
    constexpr MazeMath::Point east{1, 0};
    constexpr MazeMath::Point south{0, 1};
    constexpr MazeMath::Point west{-1, 0};

    constexpr MazeMath::Point north_west{-1, -1};
    constexpr MazeMath::Point north_east{-1, -1};
    constexpr MazeMath::Point south_east{1, 1};
    constexpr MazeMath::Point south_west{-1, 1};

    static const std::vector<MazeMath::Point> ordinalDirections{north, east, south, west};
    static const std::vector<MazeMath::Point> cardinalDirections{north_west, north_east, south_east, south_west};
    static const std::vector<MazeMath::Point> allDirections{north,
                                                            east,
                                                            south,
                                                            west,
                                                            north_west,
                                                            north_east,
                                                            south_east,
                                                            south_west};

};

#endif
