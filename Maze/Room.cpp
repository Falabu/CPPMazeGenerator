#include "Room.h"

myMaze::Room::Room(const myMath::Point &point, int width, int height) : position(myMath::Rect(point, width, height)) {}

std::vector<myMaze::RoomEntrance> myMaze::Room::getPossibleEntrance(int side) {
    return possibleEntrances[side];
}

void myMaze::Room::addPossibleEntrance(int side, const std::vector<RoomEntrance> &entrances) {
    possibleEntrances.insert({side, entrances});
}
