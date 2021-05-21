#ifndef MAZEGENERATOR_SETTINGSGENERATOR_H
#define MAZEGENERATOR_SETTINGSGENERATOR_H

#include <memory>
#include "../Maze/Types.h"
#include "../Randomizer/Randomizer.h"

enum MazeSizes {
    small = 2500,
    medium = 7500,
    large = 12500
};

enum RoomDensityMultiplier {
    lowDensityM = 1,
    averageDensityM = 2,
    highDensityM = 4,
};

enum RoomDensity {
    lowDensity = 0,
    averageDensity = 1,
    highDensity = 2,
};

class SettingsGenerator {
public:
    SettingsGenerator(const std::shared_ptr<Randomizer> &rand, int width, int height);

    myMaze::Settings getSetting();

private:
    myMaze::Settings settings;
    int area{};
    MazeSizes mazeSize{};
    std::shared_ptr<Randomizer> rand;

    void calculateMazeSize();

    void randomizeMaxRooms();

    void randomizeStart();

    void randomizeRoomSizes();

    void randomizeRoomSizeVariances();

    void randomizeRoomDistance();

    void randomizeRoomEntrances();
};


#endif //MAZEGENERATOR_SETTINGSGENERATOR_H
