#include <functional>
#include "MazeGenerator.h"

MazeGenerator::MazeGenerator(myMaze::Settings &&settings, Randomizer &rand) : rand(rand),
                                                                              myMaze(myMaze::Maze(settings)) {}

void MazeGenerator::digCorridors(const MazeMath::Point &from) {
    auto directions = myMaze::Directions::ordinalDirections;
    rand.shuffleVector(directions);

    while (!directions.empty()) {
        auto selectedDirection{directions.back()};
        directions.pop_back();

        MazeMath::Point newPoint{from.x + selectedDirection.x * myMaze.settings.corridorDistance,
                               from.y + selectedDirection.y * myMaze.settings.corridorDistance};

        if (myMaze.inMazeBoundaries(newPoint)) {
            if (!myMaze.mazeElementVisited(newPoint) && !myMaze.visitedInAnyDirection(newPoint)) {

                digTheGap(from, selectedDirection, myMaze.settings.corridorDistance);

                myMaze.setMazeElement(newPoint, myMaze::MazeElementsTypes::corridor);

                digCorridors(newPoint);
            }
        }
    }
}

void MazeGenerator::digTheGap(const MazeMath::Point &from, const MazeMath::Point &direction, int length) {
    MazeMath::Point bridgeGapPoint{from};

    for (int i{0}; i < length; ++i) {
        bridgeGapPoint += direction;

        myMaze.setMazeElement(bridgeGapPoint, myMaze::MazeElementsTypes::corridor);
    }
}

myMaze::Maze MazeGenerator::generate() {
    generateRooms();
    checkStartPoint();
    digCorridors(myMaze.settings.start);
    findPossibleEntrances();
    digRoomEntrances();

    myMaze.mapStructure([this](MazeMath::Point point) {
        deleteDeadEnds(point);
    });

    return myMaze;
}

void MazeGenerator::generateRooms() {
    for (int i{1}; i <= myMaze.settings.maxRooms; ++i) {
        int currentWidth = rand.randomInRange(myMaze.settings.roomsMinWidth,
                                              myMaze.settings.roomsMaxWidth);
        int currentHeight = rand.randomInRange(myMaze.settings.roomsMinHeight,
                                               myMaze.settings.roomsMaxHeight);

        currentWidth += rand.randomInRange(myMaze.settings.minRoomSizeVariance,
                                           myMaze.settings.maxRoomSizeVariance);
        currentHeight += rand.randomInRange(myMaze.settings.minRoomSizeVariance,
                                            myMaze.settings.maxRoomSizeVariance);

        MazeMath::Point whereTo = rand.randomPoint(myMaze.getMazeStructure());
        myMaze::Room currentRoom{whereTo, currentWidth, currentHeight};

        if (myMaze.inMazeBoundaries(currentRoom.position.getBoundaries()) && !myMaze.roomIntersect(currentRoom)) {
            digRoom(currentRoom);
        }
    }
}

void MazeGenerator::digRoom(myMaze::Room &room) {
    for (int y{0}; y <= room.position.height; ++y) {
        for (int x{0}; x <= room.position.width; ++x) {
            MazeMath::Point newPoint = {room.position.coordinate.x + x, room.position.coordinate.y + y};

            myMaze.setMazeElement(newPoint, myMaze::MazeElementsTypes::room);
        }
    }

    myMaze.getRooms().push_back(room);
}

void MazeGenerator::findPossibleEntrances() {

    for (auto &room : myMaze.getRooms()) {

        auto topEntrances = findRoomSideEntrances(room.position.width, myMaze::Directions::north, [&room](int i) {
            return MazeMath::Point{room.position.topLeft().x + i, room.position.topLeft().y};
        });

        auto bottomEntrances = findRoomSideEntrances(room.position.width, myMaze::Directions::south, [&room](int i) {
            return MazeMath::Point{room.position.bottomLeft().x + i, room.position.bottomLeft().y};
        });

        auto leftEntrances = findRoomSideEntrances(room.position.height, myMaze::Directions::west, [&room](int i) {
            return MazeMath::Point{room.position.topLeft().x, room.position.topLeft().y + i};
        });

        auto rightEntrances = findRoomSideEntrances(room.position.height, myMaze::Directions::east, [&room](int i) {
            return MazeMath::Point{room.position.topRight().x, room.position.topRight().y + i};
        });

        room.addPossibleEntrance(myMaze::RoomSides::top, topEntrances);
        room.addPossibleEntrance(myMaze::RoomSides::bottom, bottomEntrances);
        room.addPossibleEntrance(myMaze::RoomSides::right, rightEntrances);
        room.addPossibleEntrance(myMaze::RoomSides::left, leftEntrances);
    }
}

std::vector<myMaze::RoomEntrance>
MazeGenerator::findRoomSideEntrances(int lengthIn, const MazeMath::Point &direction,
                                     const std::function<MazeMath::Point(int)> &lambda) {
    std::vector<myMaze::RoomEntrance> entrances;

    for (int i{0}; i <= lengthIn; ++i) {
        if (i > 0 && i < lengthIn) {

            MazeMath::Point startPoint = lambda(i);

            MazeMath::Point toCheck = startPoint;
            for (int length{1}; length < myMaze.settings.corridorDistance * 2; ++length) {
                toCheck = toCheck + direction;
                if (myMaze.inMazeBoundaries(toCheck) && myMaze.getMazeElement(toCheck).isInMaze()) {
                    entrances.push_back({startPoint, direction, length});
                    break;
                }
            }
        }
    }

    return entrances;
}

void MazeGenerator::digRoomEntrances() {
    for (auto &room: myMaze.getRooms()) {
        std::vector<int> roomSides{myMaze::RoomSides::top, myMaze::RoomSides::right, myMaze::RoomSides::bottom,
                                   myMaze::RoomSides::left};
        rand.shuffleVector(roomSides);

        int entrancesDrawn = 0;
        int neededEntranceCount = rand.randomInRange(myMaze.settings.minRoomEntrances,
                                                     myMaze.settings.maxRoomEntrances);
        for (const auto &side : roomSides) {
            if (entrancesDrawn < neededEntranceCount) {
                std::vector<myMaze::RoomEntrance> sideEntrances = room.getPossibleEntrance(side);
                if (!sideEntrances.empty()) {
                    rand.shuffleVector(sideEntrances);

                    myMaze::RoomEntrance selectedEntrance = sideEntrances.front();
                    digTheGap(selectedEntrance.coordinate, selectedEntrance.direction, selectedEntrance.length - 1);

                    entrancesDrawn++;
                }
            }
        }
    }
}

void MazeGenerator::deleteDeadEnds(MazeMath::Point &from) {
    int count{0};
    MazeMath::Point nextPoint;

    for (const auto &direction: myMaze::Directions::ordinalDirections) {
        MazeMath::Point newPoint = from + direction;

        if (myMaze.inMazeBoundaries(newPoint) && myMaze.getMazeElement(newPoint).isInMaze()) {
            ++count;
            nextPoint = newPoint;
        }
    }

    if (count == 1) {
        myMaze.getMazeElement(from).unSet();
        deleteDeadEnds(nextPoint);
    }
}

void MazeGenerator::checkStartPoint() {
    MazeMath::Point currentStart = myMaze.settings.start;
    while (myMaze.getMazeElement(currentStart).isInMaze()) {
        currentStart = rand.randomPoint(myMaze.getMazeStructure());
    }

    myMaze.settings.start = currentStart;
}