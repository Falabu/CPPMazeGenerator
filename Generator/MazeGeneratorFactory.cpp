//
// Created by dawe on 2021. 05. 14..
//

#include "MazeGeneratorFactory.h"

std::unique_ptr<MazeGenerator> MazeGeneratorFactory::create(MazeDrawer &drawer) {
    Randomizer randomizer{};

    return std::make_unique<MazeGenerator>(drawer, randomizer);
}

std::unique_ptr<MazeGenerator> MazeGeneratorFactory::create(MazeDrawer &drawer, std::string seed) {
    Randomizer randomizer{seed};

    return std::make_unique<MazeGenerator>(drawer, randomizer);
}
