#ifndef MAZEGENERATOR_MAZEnullptr_H
#define MAZEGENERATOR_MAZE_H

#include <algorithm>
#include <memory>
#include "Room.h"
#include "MazeElement.h"
#include "Types.h"
#include "Directions.h"
#include "../Math/Math.h"

namespace myMaze {
    class Maze {
    public:
        Settings settings;

        MazeElements maze; // make private

        Rooms rooms; // make private

        explicit Maze(myMaze::Settings settings);

        void setMazeElement(myMath::Point &point, MazeElementsTypes type);

        MazeElement *getMazeElementRef(const myMath::Point &point);

        bool mazeElementVisited(myMath::Point &point);

        bool visitedInAnyDirection(const myMath::Point &point);

        bool inMazeBoundaries(const myMath::Point &point) const;

        bool inMazeBoundaries(const std::vector<myMath::Point> &points) const;

        bool roomIntersect(const Room &room);
    };

}


#endif
