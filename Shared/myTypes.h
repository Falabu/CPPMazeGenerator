#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include "vector"
#include "../Maze/MazeElement.h"

namespace myTypes {
    typedef std::vector<std::vector<MazeElement>> Maze;

    struct Speed {
        int corridor;
        int rooms;
    };

    struct MazeSettings {
        int width{};
        int height{};
        int baseDistance{};

        Point start{0, 0};

        int roomMinDistance{10};
        int maxRooms{1000};

        int roomsMinWidth{12};
        int roomsMaxWidth{12};

        int roomsMinHeight{6};
        int roomsMaxHeight{6};

        int maxRoomEntrances{2};
        int minRoomEntrances{1};

        Speed speed{5000, 2500};
    };
}

#endif
