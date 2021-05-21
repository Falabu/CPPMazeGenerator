#include "Randomizer.h"

Randomizer::Randomizer() {
    numberGenerator = NumberGenerator();
}

Randomizer::Randomizer(std::string &_seed) {
    numberGenerator = NumberGenerator{_seed};
}

int Randomizer::randomInRange(int from, int to) {
    std::uniform_int_distribution<int> random(from, to);
    auto seed = numberGenerator();
    generator.seed(seed);

    return random(generator);
}

template<class T>
void Randomizer::shuffleVector(std::vector<T> &toShuffle) {
    generator.seed(numberGenerator());

    std::shuffle(toShuffle.begin(), toShuffle.end(), generator);
}

myMath::Point Randomizer::randomPoint(const myMaze::MazeElements &maze) {
    std::size_t mazeHeight = maze.size();
    std::size_t mazeWidth = maze[0].size();

    int randomY = randomInRange(0, static_cast<int>(mazeHeight));
    int randomX = randomInRange(0, static_cast<int>(mazeWidth));

    return {randomX, randomY};
}

std::string Randomizer::getSeed() {
    return numberGenerator.getSeed();
}

template void Randomizer::shuffleVector<myMath::Point>(std::vector<myMath::Point> &toShuffle);

template void Randomizer::shuffleVector<int>(std::vector<int> &toShuffle);

template void Randomizer::shuffleVector<myMaze::RoomEntrance>(std::vector<myMaze::RoomEntrance> &toShuffle);
