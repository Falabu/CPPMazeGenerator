#ifndef MAZE_H
#define MAZE_H

#include <random>
#include <algorithm>
#include <unistd.h>
#include <memory>
#include <functional>
#include "../Math/Point.h"
#include "../Maze/Directions.h"
#include "../Maze/Maze.h"
#include "../Maze/Room.h"
#include "../Maze/Types.h"
#include "../Randomizer/Randomizer.h"

class MazeGenerator {
public:
    void generate(std::shared_ptr<myMaze::Maze> &_mazePtr);

    explicit MazeGenerator(std::shared_ptr<Randomizer> rand);

private:
    std::shared_ptr<myMaze::Maze> mazePtr;

    std::shared_ptr<Randomizer> rand;

    void checkStartPoint();

    void digCorridors(const myMath::Point &from);

    void generateRooms();

    void digRoom(myMaze::Room &room);

    void findPossibleEntrances();

    std::vector<myMaze::RoomEntrance>
    findRoomSideEntrances(int lengthIn, const myMath::Point &direction,const std::function<myMath::Point(int)> &lambda);

    void digRoomEntrances();

    void digTheGap(const myMath::Point &from, const myMath::Point &direction, int length);

    void deleteDeadEnds(myMath::Point &from);
};


#endif
