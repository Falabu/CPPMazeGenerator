#include "Maze.h"


myMaze::Maze::Maze(myMaze::Settings settings) : settings(settings) {
    maze = myMaze::MazeElements(settings.height, std::vector<MazeElement>(settings.width, MazeElement()));
}

void myMaze::Maze::setMazeElement(myMath::Point &point, MazeElementsTypes type) {
    MazeElement *mazeElement = getMazeElementRef(point);

    mazeElement->setCoordinate(point);
    mazeElement->set(type);
}

myMaze::MazeElement *myMaze::Maze::getMazeElementRef(const myMath::Point &point) {
    return &maze[point.y][point.x];
}

bool myMaze::Maze::mazeElementVisited(myMath::Point &point) {
    MazeElement *mazeElement = getMazeElementRef(point);

    return mazeElement->isInMaze();
}

bool myMaze::Maze::inMazeBoundaries(const myMath::Point &point) const {
    return (point.y >= 0 && point.y < settings.height) && (point.x >= 0 && point.x < settings.width);
}

bool myMaze::Maze::inMazeBoundaries(const std::vector<myMath::Point> &points) const {
    bool inBoundaries = true;

    for (const auto &p : points) {
        if (inBoundaries) {
            inBoundaries = inMazeBoundaries(p);
        }
    }

    return inBoundaries;
}

bool myMaze::Maze::visitedInAnyDirection(const myMath::Point &point) {
    return std::any_of(Directions::allDirections.begin(), Directions::allDirections.end(), [&](const myMath::Point &p) {
        myMath::Point pointToCheck = point + p;

        if (inMazeBoundaries(pointToCheck)) {
            MazeElement *mazeElement = getMazeElementRef(pointToCheck);

            return mazeElement->isInMaze();
        }

        return false;
    });
}

bool myMaze::Maze::roomIntersect(const Room &room) {
    return std::any_of(rooms.begin(), rooms.end(),
                       [&](Room &r) {
                           return myMath::Math::rectOverlap(room.position, r.position, settings.roomMinDistance);
                       });
}