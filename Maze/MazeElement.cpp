#include "MazeElement.h"

MazeElement::MazeElement() {
    coordinate = {0, 0};
    type = MazeElementsTypes::empty;
}

MazeElement::MazeElement(const Point &point) {
    coordinate = point;
    type = MazeElementsTypes::empty;
}

bool MazeElement::isInMaze() const {
    return inMaze;
}

void MazeElement::setCoordinate(const Point &point) {
    coordinate = point;
}

void MazeElement::set(MazeElementsTypes _type) {
    inMaze = true;
    type = _type;
}


void MazeElement::unSet() {
    inMaze = false;
    type = MazeElementsTypes::empty;
}


MazeElementsTypes MazeElement::getType() const {
    return type;
}

Point MazeElement::getCoordinate() {
    return coordinate;
}
