#ifndef MAZEGENERATOR_RECT_H
#define MAZEGENERATOR_RECT_H

#include "Point.h"
#include <vector>

namespace myMath {
    class Rect {
    public:
        myMath::Point coordinate;
        int width;
        int height;

        Rect() :
                coordinate(myMath::Point()),
                width(0),
                height(0) {}

        Rect(const myMath::Point &startCoordinate, int width, int height) :
                coordinate(startCoordinate),
                width(width),
                height(height) {}

        myMath::Point topLeft() const {
            return coordinate;
        }

        myMath::Point topRight() const {
            return myMath::Point{coordinate.x + width, coordinate.y};
        }

        myMath::Point bottomRight() const {
            return myMath::Point{coordinate.x + width, coordinate.y + height};
        }

        myMath::Point bottomLeft() const {
            return myMath::Point{coordinate.x, coordinate.y + height};
        }

        std::vector<myMath::Point> getBoundaries() const {
            std::vector<myMath::Point> boundaries;

            boundaries.push_back(topLeft());
            boundaries.push_back(topRight());
            boundaries.push_back(bottomLeft());
            boundaries.push_back(bottomRight());

            return boundaries;
        }
    };
}

#endif
