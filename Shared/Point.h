#ifndef POINT_H
#define POINT_H


class Point {
public:
    int x, y;

    Point();

    Point(int x1, int y1);

    Point(const Point &otherPoint);

    Point operator+(const Point &right) const;

    Point &operator-=(const Point &right);

    Point &operator+=(const Point &right);
};


#endif //POINT_H
