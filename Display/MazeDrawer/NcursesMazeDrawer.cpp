//
// Created by dawe on 2021. 05. 13..
//

#include "NcursesMazeDrawer.h"

void NcursesMazeDrawer::draw(const myTypes::Maze &mazeToDraw, int second) {
    erase();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLACK, COLOR_BLACK);

    start_color();
    use_default_colors();

    for (const auto &y: mazeToDraw) {
        for (const auto &x: y) {
            if (x.isInMaze()) {
                switch (x.getType()) {
                    case MazeElementsTypes::corridor:
                        attron(COLOR_PAIR(1));
                        addch(ACS_CKBOARD);
                        attroff(COLOR_PAIR(1));
                        break;
                    case MazeElementsTypes::room:
                        attron(COLOR_PAIR(2));
                        addch(ACS_CKBOARD);
                        attroff(COLOR_PAIR(2));
                        break;
                    case MazeElementsTypes::empty:
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
    usleep(second);
}
