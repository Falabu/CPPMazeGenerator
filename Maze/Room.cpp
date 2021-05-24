#include "Room.h"

myMaze::Room::Room(const MazeMath::Point &point, int width, int height) : position(MazeMath::Rect(point, width, height)) {}

std::vector<myMaze::RoomEntrance> myMaze::Room::getPossibleEntrance(int side) {
    return possibleEntrances[side];
}

void myMaze::Room::addPossibleEntrance(myMaze::RoomSides side, const std::vector<RoomEntrance> &entrances) {
    possibleEntrances.insert({side, entrances});
}
