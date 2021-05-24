#ifndef MAZEGENERATOR_MAZEnullptr_H
#define MAZEGENERATOR_MAZE_H

#include <algorithm>
#include <memory>
#include "Room.h"
#include "MazeElement.h"
#include "Types.h"
#include "Directions.h"
#include "../Math/Math.hpp"

namespace myMaze {
    class Maze {
    public:
        Settings settings;

        Rooms &getRooms();

        MazeStructure &getMazeStructure();

        explicit Maze(myMaze::Settings &settings);

        void setMazeElement(MazeMath::Point &point, MazeElementsTypes type);

        MazeElement &getMazeElement(const MazeMath::Point &point);

        bool mazeElementVisited(const MazeMath::Point &point);

        bool visitedInAnyDirection(const MazeMath::Point &point);

        bool inMazeBoundaries(const MazeMath::Point &point) const;

        bool inMazeBoundaries(const std::vector<MazeMath::Point> &points) const;

        bool roomIntersect(const Room &room);

        void mapStructure(const std::function<void(MazeMath::Point)> &lambda);

    private:
        Rooms rooms;

        MazeStructure mazeStructure;
    };

}


#endif
