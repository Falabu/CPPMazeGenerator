//
// Created by dawe on 2021. 05. 14..
//

#ifndef MAZEGENERATOR_MAZEGENERATORFACTORY_H
#define MAZEGENERATOR_MAZEGENERATORFACTORY_H

#include "MazeGenerator.h"

class MazeGeneratorFactory {
public:
    static MazeGenerator* create(MazeDrawer &drawer);

    static MazeGenerator* create(MazeDrawer &drawer, std::string seed);
};


#endif //MAZEGENERATOR_MAZEGENERATORFACTORY_H
