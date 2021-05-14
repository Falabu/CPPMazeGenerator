#include "Randomizer.h"

Randomizer::Randomizer() {
    numberGenerator = RandomNumberGenerator();
}

Randomizer::Randomizer(std::string &_seed) {
    numberGenerator = RandomNumberGenerator{_seed};
}

int Randomizer::randomInRange(int from, int to) {
    std::uniform_int_distribution<int> random(from, to);
    generator.seed(numberGenerator());

    return random(generator);
}

template<class T>
void Randomizer::shuffleVector(std::vector<T> &toShuffle) {
    generator.seed(numberGenerator());

    std::shuffle(toShuffle.begin(), toShuffle.end(), generator);
}

Point Randomizer::randomPoint(const myTypes::Maze &maze) {
    size_t mazeHeight = maze.size();
    size_t mazeWidth = maze[0].size();

    int randomY = randomInRange(0, static_cast<int>(mazeHeight));
    int randomX = randomInRange(0, static_cast<int>(mazeWidth));

    return {randomX, randomY};
}

std::string Randomizer::getSeed() {
    return numberGenerator.seedToString();
}

void Randomizer::setGenerator(const RandomNumberGenerator &_generator) {
    numberGenerator = _generator;
}

template void Randomizer::shuffleVector<Point>(std::vector<Point> &toShuffle);

template void Randomizer::shuffleVector<RoomEntrance>(std::vector<RoomEntrance> &toShuffle);