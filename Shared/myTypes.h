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
        int gap{};

        int roomMinDistance{3};
        int maxRooms{1000};

        int roomsMinWidth{6};
        int roomsMaxWidth{6};

        int roomsMinHeight{3};
        int roomsMaxHeight{3};

        int maxRoomEntrances{2};
        int minRoomEntrances{1};

        Speed speed{5000, 2500};
    };
}

#endif
