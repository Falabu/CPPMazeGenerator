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

    void generateCorridors(const myMath::Point &from);

    void generateRooms();

    void generateRoom(myMaze::Room &room);

    void bridgeTheGap(const myMath::Point &from, const myMath::Point &direction, int length);

    void findPossibleEntrances();

    std::vector<myMaze::RoomEntrance>
    findRoomEntrances(int lengthIn, const myMath::Point &direction, const std::function<myMath::Point(int)> &lambda);

    void drawRoomEntrances();

    void findDeadEnds();

    void DeleteDeadEnds(myMath::Point &from);
};


#endif
