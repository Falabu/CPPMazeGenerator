#include <sstream>
#include "Generator/MazeGenerator.h"
#include "Display/NcursesDisplay.h"
#include "Generator/SettingsGenerator.h"

int main(int argc, char *argv[]) {
    int w{50};
    int h{50};
    std::string seed;
    if (argc >= 3) {
        std::istringstream w_in(argv[1]);
        std::istringstream h_in(argv[2]);
        int val_w;
        int val_h;

        if (w_in >> val_w) {
            w = val_w;
        }

        if (h_in >> val_h) {
            h = val_h;
        }
    }

    NcursesDisplay display;
    std::shared_ptr<Randomizer> randPtr;
    if (argc >= 4) {
        seed = argv[3];
        randPtr = std::make_shared<Randomizer>(seed);
    } else {
        randPtr = std::make_shared<Randomizer>();
    }

    SettingsGenerator setting{randPtr, w, h};
    auto mazePtr = std::make_shared<myMaze::Maze>(setting.getSetting());

    MazeGenerator mGenerator(randPtr);

    display.init();

    mGenerator.generate(mazePtr);

    display.getMazeDrawer().draw(mazePtr->maze);

    display.writeLine("Your seed is: " + randPtr->getSeed());

    display.read();

    display.deInit();

    return 0;
}