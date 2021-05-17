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

        int roomMinDistance{6};
        int maxRooms{1000};

        int roomsMinWidth{8};
        int roomsMaxWidth{8};

        int roomsMinHeight{4};
        int roomsMaxHeight{4};

        int maxRoomEntrances{2};
        int minRoomEntrances{1};

        int deadEndMaxPercent{100};
        int deadEndMinPercent{0};

        Speed speed{5000, 2500};
    };
}

#endif
