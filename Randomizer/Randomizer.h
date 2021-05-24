#ifndef RANDOMIZE_H
#define RANDOMIZE_H

#include <algorithm>
#include <random>
#include <vector>
#include <cassert>
#include "../Maze/Types.h"

class Randomizer {
public:
    Randomizer();

    explicit Randomizer(std::string &&_seed);

    std::string getSeed();

    int randomInRange(int from, int to);

    MazeMath::Point randomPoint(const myMaze::MazeStructure &maze);

    template<typename T>
    void shuffleVector(std::vector<T> &toShuffle);

private:
    std::mt19937 generator;

    std::vector<int> seedNumberList;

    int seedLength{25};

    std::string seed;

    std::vector<int> generateSeedNumberList(const std::string &seedString);

    std::vector<int> generateSeedNumberList();

    static unsigned int generateSeed(const std::vector<int> &vector);
};


#endif
