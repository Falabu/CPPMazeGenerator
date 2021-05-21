#include <functional>
#include <utility>
#include "MazeGenerator.h"

MazeGenerator::MazeGenerator(std::shared_ptr<Randomizer> rand) : rand(std::move(rand)) {}

void MazeGenerator::generateCorridors(const myMath::Point &from) {
    auto directions = myMaze::Directions::ordinalDirections;
    rand->shuffleVector(directions);

    while (!directions.empty()) {
        auto selectedDirection{directions.back()};
        directions.pop_back();

        myMath::Point newPoint{from.x + selectedDirection.x * mazePtr->settings.corridorDistance,
                               from.y + selectedDirection.y * mazePtr->settings.corridorDistance};

        if (mazePtr->inMazeBoundaries(newPoint)) {
            if (!mazePtr->mazeElementVisited(newPoint) && !mazePtr->visitedInAnyDirection(newPoint)) {

                bridgeTheGap(from, selectedDirection, mazePtr->settings.corridorDistance);

                mazePtr->setMazeElement(newPoint, myMaze::MazeElementsTypes::corridor);

                generateCorridors(newPoint);
            }
        }
    }
}

void MazeGenerator::bridgeTheGap(const myMath::Point &from, const myMath::Point &direction, int length) {
    myMath::Point bridgeGapPoint{from};

    for (int i{0}; i < length; ++i) {
        bridgeGapPoint += direction;

        mazePtr->setMazeElement(bridgeGapPoint, myMaze::MazeElementsTypes::corridor);
    }
}

void MazeGenerator::generate(std::shared_ptr<myMaze::Maze> &_mazePtr) {
    mazePtr = _mazePtr;

    generateRooms();
    checkStartPoint();
    generateCorridors(mazePtr->settings.start);
    findPossibleEntrances();
    drawRoomEntrances();
    findDeadEnds();

    mazePtr.reset();
}

void MazeGenerator::generateRooms() {
    for (int i{1}; i <= mazePtr->settings.maxRooms; ++i) {
        int currentWidth = rand->randomInRange(mazePtr->settings.roomsMinWidth,
                                               mazePtr->settings.roomsMaxWidth);
        int currentHeight = rand->randomInRange(mazePtr->settings.roomsMinHeight,
                                                mazePtr->settings.roomsMaxHeight);

        currentWidth += rand->randomInRange(mazePtr->settings.minRoomSizeVariance,
                                            mazePtr->settings.maxRoomSizeVariance);
        currentHeight += rand->randomInRange(mazePtr->settings.minRoomSizeVariance,
                                             mazePtr->settings.maxRoomSizeVariance);

        myMath::Point whereTo = rand->randomPoint(mazePtr->maze);
        myMaze::Room currentRoom{whereTo, currentWidth, currentHeight};

        if (mazePtr->inMazeBoundaries(currentRoom.position.getBoundaries()) && !mazePtr->roomIntersect(currentRoom)) {
            generateRoom(currentRoom);
        }
    }
}

void MazeGenerator::generateRoom(myMaze::Room &room) {
    for (int y{0}; y <= room.position.height; ++y) {
        for (int x{0}; x <= room.position.width; ++x) {
            myMath::Point newPoint = {room.position.coordinate.x + x, room.position.coordinate.y + y};

            mazePtr->setMazeElement(newPoint, myMaze::MazeElementsTypes::room);
        }
    }

    mazePtr->rooms.push_back(room);
}

void MazeGenerator::findPossibleEntrances() {

    for (auto &room : mazePtr->rooms) {

        auto topEntrances = findRoomEntrances(room.position.width, myMaze::Directions::north, [&room](int i) {
            return myMath::Point{room.position.topLeft().x + i, room.position.topLeft().y};
        });

        auto bottomEntrances = findRoomEntrances(room.position.width, myMaze::Directions::south, [&room](int i) {
            return myMath::Point{room.position.bottomLeft().x + i, room.position.bottomLeft().y};
        });

        auto leftEntrances = findRoomEntrances(room.position.height, myMaze::Directions::west, [&room](int i) {
            return myMath::Point{room.position.topLeft().x, room.position.topLeft().y + i};
        });

        auto rightEntrances = findRoomEntrances(room.position.height, myMaze::Directions::east, [&room](int i) {
            return myMath::Point{room.position.topRight().x, room.position.topRight().y + i};
        });

        room.addPossibleEntrance(myMaze::RoomSides::top, topEntrances);
        room.addPossibleEntrance(myMaze::RoomSides::bottom, bottomEntrances);
        room.addPossibleEntrance(myMaze::RoomSides::right, rightEntrances);
        room.addPossibleEntrance(myMaze::RoomSides::left, leftEntrances);
    }
}

std::vector<myMaze::RoomEntrance>
MazeGenerator::findRoomEntrances(int lengthIn, const myMath::Point &direction,
                                 const std::function<myMath::Point(int)> &lambda) {
    std::vector<myMaze::RoomEntrance> entrances;

    for (int i{0}; i <= lengthIn; ++i) {
        if (i > 0 && i < lengthIn) {

            myMath::Point startPoint = lambda(i);

            myMath::Point toCheck = startPoint;
            for (int length{1}; length < mazePtr->settings.corridorDistance * 2; ++length) {
                toCheck = toCheck + direction;
                if (mazePtr->inMazeBoundaries(toCheck) && mazePtr->getMazeElementRef(toCheck)->isInMaze()) {
                    entrances.push_back({startPoint, direction, length});
                    break;
                }
            }
        }
    }

    return entrances;
}

void MazeGenerator::drawRoomEntrances() {
    for (auto &room: mazePtr->rooms) {
        std::vector<int> roomSides{myMaze::RoomSides::top, myMaze::RoomSides::right, myMaze::RoomSides::bottom,
                                   myMaze::RoomSides::left};
        rand->shuffleVector(roomSides);

        int entrancesDrawn = 0;
        int neededEntranceCount = rand->randomInRange(mazePtr->settings.minRoomEntrances,
                                                      mazePtr->settings.maxRoomEntrances);
        for (const auto &side : roomSides) {
            if (entrancesDrawn < neededEntranceCount) {
                std::vector<myMaze::RoomEntrance> sideEntrances = room.getPossibleEntrance(side);
                if (!sideEntrances.empty()) {
                    rand->shuffleVector(sideEntrances);

                    myMaze::RoomEntrance selectedEntrance = sideEntrances.front();
                    bridgeTheGap(selectedEntrance.coordinate, selectedEntrance.direction, selectedEntrance.length - 1);

                    entrancesDrawn++;
                }
            }
        }
    }
}

void MazeGenerator::findDeadEnds() {
    for (auto &y : mazePtr->maze) {
        for (auto &x : y) {
            if (x.isInMaze()) {
                myMath::Point currentPoint = x.getCoordinate();
                DeleteDeadEnds(currentPoint);
            }
        }
    }
}

void MazeGenerator::DeleteDeadEnds(myMath::Point &from) {
    int count{0};
    myMath::Point nextPoint;
    myMaze::MazeElement *currentElement = mazePtr->getMazeElementRef(from);
    myMaze::MazeElement *nextElement{nullptr};

    for (const auto &direction: myMaze::Directions::ordinalDirections) {
        myMath::Point newPoint = from + direction;
        nextElement = mazePtr->getMazeElementRef(newPoint);

        if (mazePtr->inMazeBoundaries(newPoint) && nextElement->isInMaze()) {
            ++count;
            nextPoint = newPoint;
        }
    }

    if (count == 1) {
        currentElement->unSet();
        DeleteDeadEnds(nextPoint);
    }
}

void MazeGenerator::checkStartPoint() {
    myMath::Point currentStart = mazePtr->settings.start;
    while (mazePtr->getMazeElementRef(currentStart)->isInMaze()) {
        currentStart = rand->randomPoint(mazePtr->maze);
    }

    mazePtr->settings.start = currentStart;
}