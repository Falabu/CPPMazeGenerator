#ifndef MAZEGENERATOR_TYPES_H
#define MAZEGENERATOR_TYPES_H

#include <vector>
#include "Room.h"
#include "MazeElement.h"

namespace myMaze {
    typedef std::vector<std::vector<MazeElement>> MazeElements;
    typedef std::vector<Room> Rooms;

    struct Settings {
        int width{};
        int height{};
        int corridorDistance{};

        myMath::Point start{0, 0};

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
