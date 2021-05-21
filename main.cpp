#include "Args/Args.h"
#include "Generator/MazeGenerator.h"
#include "Display/NcursesDisplay.h"
#include "Generator/SettingsGenerator.h"

int main(int argc, char *argv[]) {
    Args args{argc, argv};
    NcursesDisplay display;
    std::shared_ptr<Randomizer> randPtr;

    if (args.haveSeed()) {
        randPtr = std::make_shared<Randomizer>(args.getSeed());
    } else {
        randPtr = std::make_shared<Randomizer>();
    }

    SettingsGenerator setting{randPtr, args.getWidth(), args.getHeight()};
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