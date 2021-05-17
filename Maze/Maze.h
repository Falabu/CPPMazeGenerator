//
// Created by dawe on 2021. 05. 14..
//

#ifndef MAZEGENERATOR_MAZE_H
#define MAZEGENERATOR_MAZE_H

#include <algorithm>
#include "../Shared/myTypes.h"
#include "Room.h"
#include "../Shared/Directions.h"

class Maze {
public:

    myTypes::MazeSettings settings;

    myTypes::Maze maze; // make private

    std::vector<Room> rooms; // make private

    explicit Maze(myTypes::MazeSettings _settings);

    void addToMaze(Point &point, MazeElementsTypes type);

    MazeElement *getMazeElementRef(const Point &point);

    bool mazePointVisited(Point &point);

    bool visitedInAnyDirection(const Point &point);

    bool inMazeBoundaries(const Point &point) const;

    bool inMazeBoundaries(const std::vector<Point> &points) const;
};


#endif //MAZEGENERATOR_MAZE_H
