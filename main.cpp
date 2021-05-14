#include <sstream>
#include "Generator/MazeGenerator.h"
#include "Display/NcursesDisplay.h"
#include "Generator/MazeGeneratorFactory.h"

int main(int argc, char *argv[]) {
    int w{300};
    int h{100};
    int g{2};
    std::string seed;
    if (argc >= 4) {
        std::istringstream w_in(argv[1]);
        std::istringstream h_in(argv[2]);
        std::istringstream g_in(argv[3]);
        int val_w;
        int val_h;
        int val_g;

        if (w_in >> val_w) {
            w = val_w;
        }

        if (h_in >> val_h) {
            h = val_h;
        }

        if (g_in >> val_g) {
            g = val_g;
        }
    }


    myTypes::MazeSettings settings{w, h, g};

    NcursesDisplay display;
    Maze myMaze(settings);
    Maze *mazePtr = &myMaze;
    MazeGenerator *mgPtr{nullptr};

    if (argc >= 5) {
        seed = argv[4];
        mgPtr = MazeGeneratorFactory::create(display.getMazeDrawer(), seed);
    } else {
        mgPtr = MazeGeneratorFactory::create(display.getMazeDrawer());
    }


    display.init();

    mgPtr->generate(mazePtr);

    printw(mgPtr->getSeed().c_str());
    display.read();

    display.deInit();

    delete mazePtr;
    delete mgPtr;

    return 0;
}