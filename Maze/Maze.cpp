#include "Maze.h"


Maze::Maze(myTypes::MazeSettings _settings) {
    settings = _settings;
    maze = myTypes::Maze(settings.height, std::vector<MazeElement>(settings.width, MazeElement()));
}

void Maze::addToMaze(Point &point, MazeElementsTypes type) {
    MazeElement *mazePoint = getMazeElementRef(point);

    mazePoint->setCoordinate(point);
    mazePoint->set(type);
}

MazeElement *Maze::getMazeElementRef(const Point &point) {
    return &maze[point.y][point.x];
}

bool Maze::mazePointVisited(Point &point) {
    MazeElement *mazePoint = getMazeElementRef(point);

    return mazePoint->isInMaze();
}

bool Maze::inMazeBoundaries(const Point &point) const {
    return (point.y >= 0 && point.y < settings.height) && (point.x >= 0 && point.x < settings.width);
}

bool Maze::inMazeBoundaries(const std::vector<Point> &points) const {
    bool inBoundaries = true;

    for (const auto &p : points) {
        if (inBoundaries) {
            inBoundaries = inMazeBoundaries(p);
        }
    }

    return inBoundaries;
}

bool Maze::visitedInAnyDirection(const Point &point) {
    std::vector<Point> allDirections;

    allDirections.insert(allDirections.end(), Directions::ordinalDirections.begin(),
                         Directions::ordinalDirections.end());
    allDirections.insert(allDirections.end(), Directions::cardinalDirections.begin(),
                         Directions::cardinalDirections.end());

    return std::any_of(allDirections.begin(), allDirections.end(), [&](Point &p) {
        Point pointToCheck = point + p;

        if (inMazeBoundaries(pointToCheck)) {
            MazeElement *mazePoint = getMazeElementRef(pointToCheck);

            return mazePoint->isInMaze();
        }

        return false;
    });
}
