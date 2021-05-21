#ifndef MAZEPOINT_H
#define MAZEPOINT_H

#include "../Math/Math.h"

namespace myMaze {

    enum MazeElementsTypes {
        empty = 0,
        corridor = 1,
        room = 2
    };

    class MazeElement {
    public:
        MazeElement();

        explicit MazeElement(const myMath::Point &point);

        bool isInMaze() const;

        myMath::Point getCoordinate();

        void setCoordinate(const myMath::Point &point);

        void set(MazeElementsTypes _type);

        void unSet();

        MazeElementsTypes getType() const;

    private:
        MazeElementsTypes type;
        myMath::Point coordinate;
        bool inMaze{false};
    };
}

#endif
