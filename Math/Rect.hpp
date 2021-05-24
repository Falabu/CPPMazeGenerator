#ifndef MAZEGENERATOR_RECT_HPP
#define MAZEGENERATOR_RECT_HPP

#include "Point.hpp"
#include <vector>

namespace MazeMath {
    class Rect {
    public:
        MazeMath::Point coordinate;
        int width;
        int height;

        Rect() :
                coordinate(MazeMath::Point()) {}

        Rect(const MazeMath::Point &startCoordinate, int width, int height) :
                coordinate(startCoordinate),
                width(width),
                height(height) {}

        MazeMath::Point topLeft() const {
            return coordinate;
        }

        MazeMath::Point topRight() const {
            return MazeMath::Point{coordinate.x + width, coordinate.y};
        }

        MazeMath::Point bottomRight() const {
            return MazeMath::Point{coordinate.x + width, coordinate.y + height};
        }

        MazeMath::Point bottomLeft() const {
            return MazeMath::Point{coordinate.x, coordinate.y + height};
        }

        std::vector<MazeMath::Point> getBoundaries() const {
            std::vector<MazeMath::Point> boundaries;

            boundaries.push_back(topLeft());
            boundaries.push_back(topRight());
            boundaries.push_back(bottomLeft());
            boundaries.push_back(bottomRight());

            return boundaries;
        }
    };
}

#endif
