#include "Maze.h"


myMaze::Maze::Maze(myMaze::Settings &settings) : settings(settings) {
    mazeStructure = myMaze::MazeStructure(settings.height, std::vector<MazeElement>(settings.width, MazeElement()));
}

void myMaze::Maze::setMazeElement(MazeMath::Point &point, MazeElementsTypes type) {
    getMazeElement(point).setCoordinate(point);
    getMazeElement(point).set(type);
}

myMaze::MazeElement &myMaze::Maze::getMazeElement(const MazeMath::Point &point) {
    return mazeStructure[point.y][point.x];
}

bool myMaze::Maze::mazeElementVisited(const MazeMath::Point &point) {
    return getMazeElement(point).isInMaze();
}

bool myMaze::Maze::inMazeBoundaries(const MazeMath::Point &point) const {
    return (point.y >= 0 && point.y < settings.height) && (point.x >= 0 && point.x < settings.width);
}

bool myMaze::Maze::inMazeBoundaries(const std::vector<MazeMath::Point> &points) const {
    bool inBoundaries = true;

    for (const auto &p : points) {
        if (inBoundaries) {
            inBoundaries = inMazeBoundaries(p);
        }
    }

    return inBoundaries;
}

bool myMaze::Maze::visitedInAnyDirection(const MazeMath::Point &point) {
    return std::any_of(Directions::allDirections.begin(), Directions::allDirections.end(),
                       [&](const MazeMath::Point &p) {
                           MazeMath::Point pointToCheck = point + p;

                           if (inMazeBoundaries(pointToCheck)) {
                               return getMazeElement(pointToCheck).isInMaze();
                           }

                           return false;
                       });
}

bool myMaze::Maze::roomIntersect(const Room &room) {
    return std::any_of(rooms.begin(), rooms.end(),
                       [&](Room &r) {
                           return MazeMath::Math::rectOverlap(room.position, r.position, settings.roomMinDistance);
                       });
}

void myMaze::Maze::mapStructure(const std::function<void(MazeMath::Point)> &lambda) {
    for (const auto &y : mazeStructure) {
        for (const auto &x : y) {
            if (x.isInMaze()) {
                MazeMath::Point currentPoint = x.getCoordinate();
                lambda(currentPoint);
            }
        }
    }
}

myMaze::Rooms &myMaze::Maze::getRooms() {
    return rooms;
}

myMaze::MazeStructure &myMaze::Maze::getMazeStructure() {
    return mazeStructure;
}
