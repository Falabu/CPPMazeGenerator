//
// Created by dawe on 2021. 05. 13..
//

#ifndef UNTITLED_NCURSESMAZEDRAWER_H
#define UNTITLED_NCURSESMAZEDRAWER_H

#include <unistd.h>
#include "MazeDrawer.h"
#include "ncurses.h"

class NcursesMazeDrawer : public MazeDrawer {
public:
    void draw(const myMaze::MazeElements &mazeToDraw, int second) override;
};


#endif //UNTITLED_NCURSESMAZEDRAWER_H
