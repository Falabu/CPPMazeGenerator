#ifndef MAZEGENERATOR_TYPES_H
#define MAZEGENERATOR_TYPES_H

#include <vector>
#include "Room.h"
#include "MazeElement.h"

namespace myMaze {
    using MazeStructure = std::vector<std::vector<MazeElement>>;
    using Rooms = std::vector<Room>;

    struct Settings {
        int width{};
        int height{};
        int corridorDistance{};

        MazeMath::Point start{0, 0};

        int roomMinDistance{10};
        int maxRooms{1000};

        int roomsMinWidth{12};
        int roomsMaxWidth{12};

        int roomsMinHeight{6};
        int roomsMaxHeight{6};

        int minRoomSizeVariance = 0;
        int maxRoomSizeVariance = 6;

        int maxRoomEntrances{2};
        int minRoomEntrances{1};
    };
}

#endif
