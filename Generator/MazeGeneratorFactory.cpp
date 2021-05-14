//
// Created by dawe on 2021. 05. 14..
//

#include "MazeGeneratorFactory.h"

MazeGenerator *MazeGeneratorFactory::create(MazeDrawer &drawer) {
    MazeGenerator *mgPtr{nullptr};
    Randomizer randomizer{};

    mgPtr = new MazeGenerator(drawer, randomizer);
    return mgPtr;
}

MazeGenerator *MazeGeneratorFactory::create(MazeDrawer &drawer, std::string seed) {
    MazeGenerator *mgPtr{nullptr};
    Randomizer randomizer{seed};

    mgPtr = new MazeGenerator(drawer, randomizer);
    return mgPtr;
}
