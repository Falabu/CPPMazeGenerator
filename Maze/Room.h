#ifndef UNTITLED_ROOM_H
#define UNTITLED_ROOM_H

#include "../Math/Math.h"

#include <vector>
#include "unordered_map"

namespace myMaze {

    struct RoomEntrance {
        myMath::Point coordinate;
        myMath::Point direction;
        int length;
    };

    enum RoomSides {
        top = 0,
        right = 1,
        bottom = 2,
        left = 4
    };

    typedef std::unordered_map<int, std::vector<RoomEntrance>> RoomEntrances;

    class Room {
    public:
        myMath::Rect position;

        Room(const myMath::Point &point, int width, int height);

        void addPossibleEntrance(int side, const std::vector<RoomEntrance> &entrances);

        std::vector<RoomEntrance> getPossibleEntrance(int side);

    private:
        RoomEntrances possibleEntrances;
    };
}

#endif
