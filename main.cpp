#include "Args/Args.h"
#include "Generator/MazeGenerator.h"
#include "Display/NcursesDisplay.h"
#include "Generator/SettingsGenerator.h"

int main(int argc, char *argv[]) {
    Args args{argc, argv};
    NcursesDisplay display;
    std::optional<Randomizer> randomizer;

    if (args.haveSeed()) {
        randomizer = Randomizer(args.getSeed());
    } else {
        randomizer = Randomizer();
    }

    SettingsGenerator setting{randomizer.value(), args.getWidth(), args.getHeight()};

    MazeGenerator mGenerator(setting.getSetting(), randomizer.value());

    display.init();

    auto maze = mGenerator.generate();

    display.getMazeDrawer().draw(maze.getMazeStructure());

    display.writeLine("Your seed is: " + randomizer->getSeed());

    display.read();

    display.deInit();

    return 0;
}