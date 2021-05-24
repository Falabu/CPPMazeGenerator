#include "Args.h"
#include "Generator/MazeGenerator.h"
#include "Display/NcursesDisplay.h"
#include "Generator/SettingsGenerator.h"

int main(int argc, char *argv[]) {
    Args args{argc, argv};
    NcursesDisplay display;

    Randomizer randomizer = args.haveSeed() ? Randomizer(args.getSeed()) : Randomizer();
    SettingsGenerator setting{randomizer, args.getWidth(), args.getHeight()};
    MazeGenerator mGenerator(setting.getSetting(), randomizer);

    display.init();

    auto maze = mGenerator.generate();

    display.getMazeDrawer().draw(maze.getMazeStructure());
    display.writeLine("Your seed is: " + randomizer.getSeed());

    display.read();
    display.deInit();

    return 0;
}