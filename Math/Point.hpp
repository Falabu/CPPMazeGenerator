#ifndef POINT_H
#define POINT_H

namespace MazeMath {

    class Point {
    public:
        int x = 0;
        int y = 0;

        Point() = default;

        constexpr Point(int x, int y) : x(x), y(y) {};

        constexpr Point(const Point &otherPoint) {
            x = otherPoint.x;
            y = otherPoint.y;
        };

        Point operator+(const Point &right) const {
            Point p;
            p.x = this->x + right.x;
            p.y = this->y + right.y;

            return p;
        };

        Point &operator-=(const Point &right) {
            x = x - right.x;
            y = y - right.y;

            return *this;
        };

        Point &operator+=(const Point &right) {
            x = x + right.x;
            y = y + right.y;

            return *this;
        };


    };
}

#endif
