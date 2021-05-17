#include <functional>
#include "MazeGenerator.h"

MazeGenerator::MazeGenerator(MazeDrawer &drawer, Randomizer &randomizer) : drawer(drawer), randomizer(randomizer) {
}

void MazeGenerator::generateCorridors(const Point &from) {
    auto directions = Directions::ordinalDirections;
    randomizer.shuffleVector(directions);

    while (!directions.empty()) {
        auto selectedDirection{directions.back()};
        directions.pop_back();

        Point newPoint{from.x + selectedDirection.x * mazePtr->settings.baseDistance,
                       from.y + selectedDirection.y * mazePtr->settings.baseDistance};

        if (mazePtr->inMazeBoundaries(newPoint)) {
            if (!mazePtr->mazePointVisited(newPoint) && !mazePtr->visitedInAnyDirection(newPoint)) {

                bridgeTheGap(from, selectedDirection, mazePtr->settings.baseDistance);

                mazePtr->addToMaze(newPoint, MazeElementsTypes::corridor);

                generateCorridors(newPoint);
            }
        }
    }
}

void MazeGenerator::bridgeTheGap(const Point &from, const Point &direction, int length) {
    Point bridgeGapPoint{from};

    for (int i{0}; i < length; ++i) {
        bridgeGapPoint += direction;

        mazePtr->addToMaze(bridgeGapPoint, MazeElementsTypes::corridor);

        drawer.draw(mazePtr->maze, mazePtr->settings.speed.corridor);
    }
}

void MazeGenerator::generate(std::shared_ptr<Maze> &_mazePtr) {
    mazePtr = _mazePtr;

    generateRooms();
    generateCorridors(mazePtr->settings.start);
    findPossibleEntrances();
    drawRoomEntrances();
    findDeadEnds();

    mazePtr.reset();
}

void MazeGenerator::generateRooms() {
    for (int i{1}; i <= mazePtr->settings.maxRooms; ++i) {
        int currentWidth = randomizer.randomInRange(mazePtr->settings.roomsMinWidth, mazePtr->settings.roomsMaxWidth);
        int currentHeight = randomizer.randomInRange(mazePtr->settings.roomsMinHeight,
                                                     mazePtr->settings.roomsMaxHeight);

        Point whereTo = randomizer.randomPoint(mazePtr->maze);
        Room currentRoom{whereTo, currentWidth, currentHeight};

        if (mazePtr->inMazeBoundaries(currentRoom.getBoundaries()) && !roomIntersect(currentRoom)) {
            generateRoom(currentRoom);
        }
    }
}

bool MazeGenerator::roomIntersect(const Room &room) {

    return std::any_of(mazePtr->rooms.begin(), mazePtr->rooms.end(), [&](Room &r) { return rectOverlap(room, r); });
}

void MazeGenerator::generateRoom(Room &room) {
    for (int y{0}; y <= room.height; ++y) {
        for (int x{0}; x <= room.width; ++x) {
            Point newPoint = {room.coordinate.x + x, room.coordinate.y + y};

            mazePtr->addToMaze(newPoint, MazeElementsTypes::room);

            drawer.draw(mazePtr->maze, mazePtr->settings.speed.rooms);
        }
    }

    mazePtr->rooms.push_back(room);
}

/**
 * https://stackoverflow.com/a/306379
 */
bool MazeGenerator::valueInRange(int value, int min, int max) {
    return (value >= min) && (value <= max);
}

bool MazeGenerator::rectOverlap(const Room &A, const Room &B) const {
    bool xOverlap =
            valueInRange(A.coordinate.x, B.coordinate.x,
                         B.coordinate.x + B.width + mazePtr->settings.roomMinDistance) ||
            valueInRange(B.coordinate.x, A.coordinate.x, A.coordinate.x + A.width + mazePtr->settings.roomMinDistance);

    bool yOverlap =
            valueInRange(A.coordinate.y, B.coordinate.y,
                         B.coordinate.y + B.height + mazePtr->settings.roomMinDistance) ||
            valueInRange(B.coordinate.y, A.coordinate.y, A.coordinate.y + A.height + mazePtr->settings.roomMinDistance);

    return xOverlap && yOverlap;
}

std::string MazeGenerator::getSeed() {
    return randomizer.getSeed();
}

void MazeGenerator::findPossibleEntrances() {

    for (auto &room : mazePtr->rooms) {

        auto topEntrances = findRoomEntrances(room.width, Directions::NORTH, [&room](int i) {
            return Point{room.roomPoints.topLeft.x + i, room.roomPoints.topLeft.y};
        });

        auto bottomEntrances = findRoomEntrances(room.width, Directions::SOUTH, [&room](int i) {
            return Point{room.roomPoints.bottomLeft.x + i, room.roomPoints.bottomLeft.y};
        });

        auto leftEntrances = findRoomEntrances(room.height, Directions::WEST, [&room](int i) {
            return Point{room.roomPoints.topLeft.x, room.roomPoints.topLeft.y + i};
        });

        auto rightEntrances = findRoomEntrances(room.height, Directions::EAST, [&room](int i) {
            return Point{room.roomPoints.topRight.x, room.roomPoints.topRight.y + i};
        });

        room.addPossibleEntrance(topEntrances);
        room.addPossibleEntrance(bottomEntrances);
        room.addPossibleEntrance(rightEntrances);
        room.addPossibleEntrance(leftEntrances);
    }
}

std::vector<RoomEntrance>
MazeGenerator::findRoomEntrances(int lengthIn, const Point &direction, const std::function<Point(int)> &lambda) {
    std::vector<RoomEntrance> entrances;

    for (int i{0}; i <= lengthIn; ++i) {
        if (i > 0 && i < lengthIn) {

            Point startPoint = lambda(i);

            Point toCheck = startPoint;
            for (int length{1}; length < mazePtr->settings.baseDistance * 2; ++length) {
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
        std::vector<RoomEntrance> entrances{room.getPossibleEntrance()};
        randomizer.shuffleVector(entrances);
        int maxEntrances = randomizer.randomInRange(mazePtr->settings.minRoomEntrances,
                                                    mazePtr->settings.maxRoomEntrances);

        if (entrances.size() >= maxEntrances) {
            for (int i{1}; i <= maxEntrances; ++i) {
                int randomEntrance = randomizer.randomInRange(0, room.possibleEntrances - 1);
                bridgeTheGap(entrances[randomEntrance].coordinate, entrances[randomEntrance].direction,
                             entrances[randomEntrance].length - 1);
            }
        }
    }
}

void MazeGenerator::findDeadEnds() {
    for (auto &y : mazePtr->maze) {
        for (auto &x : y) {
            if (x.isInMaze()) {
                Point currentPoint = x.getCoordinate();
                DeleteDeadEnds(currentPoint);
            }
        }
    }
}

void MazeGenerator::DeleteDeadEnds(Point &from) {
    int count{0};
    Point nextPoint;
    MazeElement *currentElement = mazePtr->getMazeElementRef(from);
    MazeElement *nextElement = {nullptr};

    for (const auto &direction: Directions::ordinalDirections) {
        Point newPoint = from + direction;
        nextElement = mazePtr->getMazeElementRef(newPoint);

        if (mazePtr->inMazeBoundaries(newPoint) && nextElement->isInMaze()) {
            ++count;
            nextPoint = newPoint;
        }
    }

    if (count == 1) {
        currentElement->unSet();
        drawer.draw(mazePtr->maze, 5000);
        DeleteDeadEnds(nextPoint);
    }
}
