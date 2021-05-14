#include "Room.h"

Room::Room(Point &point, int width, int height) : coordinate(point), width(width), height(height) {
    roomPoints.topLeft = point;
    roomPoints.topRight = {point.x + width, point.y};
    roomPoints.bottomRight = {point.x + width, point.y + height};
    roomPoints.bottomLeft = {point.x, point.y + height};
}

void Room::addPossibleEntrance(const Point &point, const Point &direction, int length) {
    RoomEntrance entrance{point, direction, length};
    possibleEntrances++;
    possibleRoomEntrances.push_back(entrance);
}

void Room::addPossibleEntrance(std::vector<RoomEntrance> entrances) {
    possibleEntrances += entrances.size();
    possibleRoomEntrances.insert(possibleRoomEntrances.end(), entrances.begin(), entrances.end());
}


std::vector<Point> Room::getBoundaries() const {
    std::vector<Point> boundaries;

    boundaries.push_back(roomPoints.topLeft);
    boundaries.push_back(roomPoints.topRight);
    boundaries.push_back(roomPoints.bottomLeft);
    boundaries.push_back(roomPoints.bottomRight);

    return boundaries;
}

std::vector<RoomEntrance> Room::getPossibleEntrance() {
    return possibleRoomEntrances;
}