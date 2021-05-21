#include "SettingsGenerator.h"

SettingsGenerator::SettingsGenerator(const std::shared_ptr<Randomizer> &rand, int width, int height) : rand(rand) {
    settings.width = width;
    settings.height = height;
    settings.corridorDistance = rand->randomInRange(2, 6);

    calculateMazeSize();

    randomizeStart();
    randomizeRoomSizes();
    randomizeMaxRooms();
    randomizeRoomDistance();
    randomizeRoomEntrances();
}

void SettingsGenerator::calculateMazeSize() {
    area = settings.height * settings.width;

    if (area >= MazeSizes::large) {
        mazeSize = MazeSizes::large;
    } else if (area >= MazeSizes::medium) {
        mazeSize = MazeSizes::medium;
    } else {
        mazeSize = MazeSizes::small;
    }
}

void SettingsGenerator::randomizeMaxRooms() {
    int roomMinArea{settings.roomsMinWidth * settings.roomsMinHeight};
    int roomMaxArea{settings.roomsMaxWidth * settings.roomsMaxHeight};

    int roomAverageArea = (roomMaxArea + roomMinArea) / 2.0;

    int roomFits = (area / roomAverageArea);

    int selectedDensity{rand->randomInRange(0, 3)};

    int densityM{0};
    switch (selectedDensity) {
        case RoomDensity::lowDensity:
            densityM = RoomDensityMultiplier::lowDensityM;
            break;
        case RoomDensity::averageDensity:
            densityM = RoomDensityMultiplier::averageDensityM;
            break;
        default:
            densityM = RoomDensityMultiplier::highDensityM;
    }

    settings.maxRooms = roomFits * densityM;
}

void SettingsGenerator::randomizeRoomSizes() {
    int minVariance = rand->randomInRange(settings.corridorDistance + 1, settings.corridorDistance * 2);
    int minRoomWidth = rand->randomInRange(settings.corridorDistance + 1, minVariance);
    int roomVarianceWidth = rand->randomInRange(1, 10);
    int roomMaxVarianceWidth = rand->randomInRange(0, roomVarianceWidth);
    int maxRoomSizeWidth = rand->randomInRange(minRoomWidth, minRoomWidth + roomMaxVarianceWidth);

    int minRoomHeight = rand->randomInRange(settings.corridorDistance + 1, minVariance);
    int roomVarianceHeight = rand->randomInRange(1, 10);
    int roomMaxVarianceHeight = rand->randomInRange(0, roomVarianceHeight);
    int maxRoomSizeHeight = rand->randomInRange(minRoomHeight, minRoomHeight + roomMaxVarianceHeight);

    settings.roomsMinHeight = minRoomHeight / 2;
    settings.roomsMaxHeight = maxRoomSizeHeight / 2;

    settings.roomsMinWidth = minRoomWidth;
    settings.roomsMaxWidth = maxRoomSizeWidth;
}

void SettingsGenerator::randomizeStart() {
    int x{rand->randomInRange(0, settings.width - 1)};
    int y{rand->randomInRange(0, settings.height - 1)};

    settings.start = {x, y};
}

void SettingsGenerator::randomizeRoomDistance() {
    int maxRoomDistance =
            ((settings.width + settings.height) / 2.0) / ((settings.roomsMinWidth + settings.roomsMaxHeight) / 2.0);
    settings.roomMinDistance = rand->randomInRange(settings.corridorDistance - 1, maxRoomDistance);
}

myMaze::Settings SettingsGenerator::getSetting() {
    return settings;
}

void SettingsGenerator::randomizeRoomEntrances() {
    settings.minRoomEntrances = rand->randomInRange(1, 4);
    settings.maxRoomEntrances = rand->randomInRange(settings.minRoomEntrances, 4);
}

void SettingsGenerator::randomizeRoomSizeVariances() {
    settings.minRoomSizeVariance = rand->randomInRange(0, 10);
    settings.maxRoomSizeVariance = rand->randomInRange(0, 10);
}
