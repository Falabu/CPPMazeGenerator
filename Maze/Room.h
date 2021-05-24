#ifndef UNTITLED_ROOM_H
#define UNTITLED_ROOM_H

#include "Math.hpp"

#include <vector>
#include "unordered_map"

namespace myMaze {

    struct RoomEntrance {
        MazeMath::Point coordinate;
        MazeMath::Point direction;
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
        MazeMath::Rect position;

        Room(const MazeMath::Point &point, int width, int height);

        void addPossibleEntrance(myMaze::RoomSides side, const std::vector<RoomEntrance> &entrances);

        std::vector<RoomEntrance> getPossibleEntrance(int side);

    private:
        RoomEntrances possibleEntrances;
    };
}

#endif
