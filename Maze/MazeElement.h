#ifndef MAZEPOINT_H
#define MAZEPOINT_H

#include "../Math/Math.hpp"

namespace myMaze {

    enum MazeElementsTypes {
        empty = 0,
        corridor = 1,
        room = 2
    };

    class MazeElement {
    public:
        MazeElement();

        explicit MazeElement(const MazeMath::Point &point);

        bool isInMaze() const;

        MazeMath::Point getCoordinate() const;

        void setCoordinate(const MazeMath::Point &point);

        void set(MazeElementsTypes _type);

        void unSet();

        MazeElementsTypes getType() const;

    private:
        MazeElementsTypes type;
        MazeMath::Point coordinate;
        bool inMaze{false};
    };
}

#endif
