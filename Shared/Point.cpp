#include "Point.h"

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(int _x, int _y) {
    x = _x;
    y = _y;
}

Point::Point(const Point &otherPoint) {
    x = otherPoint.x;
    y = otherPoint.y;
}

Point &Point::operator-=(const Point &right) {
    x = x - right.x;
    y = y - right.y;

    return *this;
}

Point &Point::operator+=(const Point &right) {
    x = x + right.x;
    y = y + right.y;

    return *this;
}

Point Point::operator+(const Point &right) const {
    Point p;
    p.x = this->x + right.x;
    p.y = this->y + right.y;

    return p;
}
