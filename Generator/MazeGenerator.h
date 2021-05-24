#ifndef MAZE_H
#define MAZE_H

#include <random>
#include <algorithm>
#include <unistd.h>
#include <memory>
#include <functional>
#include "Point.hpp"
#include "Directions.h"
#include "Maze.h"
#include "Room.h"
#include "Types.h"
#include "Randomizer.h"

class MazeGenerator {
public:
    myMaze::Maze generate();

    explicit MazeGenerator(myMaze::Settings &&settings, Randomizer &rand);

private:
    myMaze::Maze myMaze;

    Randomizer &rand;

    void checkStartPoint();

    void digCorridors(const MazeMath::Point &from);

    void generateRooms();

    void digRoom(myMaze::Room &room);

    void findPossibleEntrances();

    std::vector<myMaze::RoomEntrance>
    findRoomSideEntrances(int lengthIn, const MazeMath::Point &direction,
                          const std::function<MazeMath::Point(int)> &lambda);

    void digRoomEntrances();

    void digTheGap(const MazeMath::Point &from, const MazeMath::Point &direction, int length);

    void deleteDeadEnds(MazeMath::Point &from);
};


#endif
