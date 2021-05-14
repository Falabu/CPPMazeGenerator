//
// Created by dawe on 2021. 05. 13..
//

#ifndef UNTITLED_ROOM_H
#define UNTITLED_ROOM_H

#include "../Shared/Point.h"
#include <vector>

struct RoomPoints {
    Point topLeft;
    Point topRight;
    Point bottomRight;
    Point bottomLeft;
};

struct RoomEntrance {
    Point coordinate;
    Point direction;
    int length;
};

class Room {
public:
    Point coordinate;
    RoomPoints roomPoints;
    int width;

    int height;

    Room(Point &point, int width, int height);

    void addPossibleEntrance(const Point &point, const Point &direction, int length);

    std::vector<RoomEntrance> getPossibleEntrance();

    std::vector<Point> getBoundaries() const;

    int possibleEntrances{0};
private:

    std::vector<RoomEntrance> possibleRoomEntrances;
};


#endif //UNTITLED_ROOM_H
