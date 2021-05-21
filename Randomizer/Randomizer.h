#ifndef RANDOMIZE_H
#define RANDOMIZE_H

#include <algorithm>
#include <random>
#include <vector>
#include <cassert>
#include "../Math/Point.h"
#include "NumberGenerator.h"
#include "../Maze/Room.h"
#include "../Maze/Types.h"

class Randomizer {
private:
    std::mt19937 generator;

    NumberGenerator numberGenerator;
public:
    Randomizer();

    explicit Randomizer(std::string &&_seed);

    std::string getSeed();

    int randomInRange(int from, int to);

    myMath::Point randomPoint(const myMaze::MazeElements &maze);

    template<class T>
    void shuffleVector(std::vector<T> &toShuffle);
};


#endif //RANDOMIZE_H
