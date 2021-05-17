#ifndef RANDOMIZE_H
#define RANDOMIZE_H

#include <algorithm>
#include <random>
#include <vector>
#include "../Shared/Point.h"
#include "../Shared/myTypes.h"
#include "RandomNumberGenerator.h"
#include "../Maze/Room.h"

class Randomizer {
private:
    std::mt19937 generator;

    RandomNumberGenerator numberGenerator;
public:
    Randomizer();

    explicit Randomizer(std::string &_seed);

    std::string getSeed();

    int randomInRange(int from, int to);

    Point randomPoint(const myTypes::Maze &maze);

    template<class T>
    void shuffleVector(std::vector<T> &toShuffle);
};


#endif //RANDOMIZE_H
