//
// Created by dawe on 2021. 05. 13..
//

#include "NcursesMazeDrawer.h"

void NcursesMazeDrawer::draw(const myMaze::MazeElements &mazeToDraw) {
    for (const auto &y: mazeToDraw) {
        for (const auto &x: y) {
            if (x.isInMaze()) {
                switch (x.getType()) {
                    case myMaze::MazeElementsTypes::corridor:
                        attron(COLOR_PAIR(1));
                        addch(ACS_CKBOARD);
                        attroff(COLOR_PAIR(1));
                        break;
                    case myMaze::MazeElementsTypes::room:
                        attron(COLOR_PAIR(2));
                        addch(ACS_CKBOARD);
                        attroff(COLOR_PAIR(2));
                        break;
                    case myMaze::MazeElementsTypes::empty:
                        attron(COLOR_PAIR(3));
                        addch(ACS_CKBOARD);
                        attroff(COLOR_PAIR(3));
                        break;

                }
            } else {
                addch(' ');
            }
        }

        printw("\n");
    }

    refresh();
}
