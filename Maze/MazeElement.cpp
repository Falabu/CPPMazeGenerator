#include "MazeElement.h"

myMaze::MazeElement::MazeElement() {
    coordinate = {0, 0};
    type = MazeElementsTypes::empty;
}

myMaze::MazeElement::MazeElement(const myMath::Point &point) {
    coordinate = point;
    type = MazeElementsTypes::empty;
}

bool myMaze::MazeElement::isInMaze() const {
    return inMaze;
}

void myMaze::MazeElement::setCoordinate(const myMath::Point &point) {
    coordinate = point;
}

void myMaze::MazeElement::set(MazeElementsTypes _type) {
    inMaze = true;
    type = _type;
}

void myMaze::MazeElement::unSet() {
    inMaze = false;
    type = MazeElementsTypes::empty;
}

myMaze::MazeElementsTypes myMaze::MazeElement::getType() const {
    return type;
}

myMath::Point myMaze::MazeElement::getCoordinate() {
    return coordinate;
}
