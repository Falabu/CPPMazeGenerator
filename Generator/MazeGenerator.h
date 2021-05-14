#ifndef MAZE_H
#define MAZE_H

#include <random>
#include <algorithm>
#include <ncurses.h>
#include <unistd.h>
#include "../Shared/myTypes.h"
#include "../Shared/Point.h"
#include "../Shared/Directions.h"
#include "../Maze/Maze.h"
#include "../Randomizer/Randomizer.h"
#include "../Display/MazeDrawer/MazeDrawer.h"
#include "../Maze/Room.h"
#include "../Randomizer/RandomNumberGenerator.h"

class MazeGenerator {
public:
    explicit MazeGenerator(MazeDrawer &drawer, Randomizer &randomizer);

    void generate(Maze *_mazePtr, const Point &start = {0, 0});

    std::string getSeed();

private:
    Maze *mazePtr{nullptr};

    MazeDrawer &drawer;

    Randomizer randomizer;

    void generateCorridors(const Point &from);

    void generateRooms();

    void addRoom(Room &room);

    bool roomIntersect(const Room &room);

    void bridgeTheGap(const Point &oldPoint, const Point &currentDirection, int length);

    static bool valueInRange(int value, int min, int max);

    bool rectOverlap(const Room &A, const Room &B) const;

    void findPossibleEntrances();

    void drawRoomEntrances();

    void shrinkDeadEnds();
};


#endif
