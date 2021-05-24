#include "Randomizer.h"

Randomizer::Randomizer() {
    seedNumberList = generateSeedNumberList();

    std::srand(generateSeed(seedNumberList));
}

Randomizer::Randomizer(std::string &&_seed) {
    seedNumberList = generateSeedNumberList(_seed);

    std::srand(generateSeed(seedNumberList));
}

int Randomizer::randomInRange(int from, int to) {
    std::uniform_int_distribution<int> random(from, to);
    generator.seed(std::rand());

    return random(generator);
}

template<class T>
void Randomizer::shuffleVector(std::vector<T> &toShuffle) {
    generator.seed(std::rand());

    std::shuffle(toShuffle.begin(), toShuffle.end(), generator);
}

MazeMath::Point Randomizer::randomPoint(const myMaze::MazeStructure &maze) {
    std::size_t mazeHeight = maze.size();
    std::size_t mazeWidth = maze[0].size();

    int randomY = randomInRange(0, static_cast<int>(mazeHeight));
    int randomX = randomInRange(0, static_cast<int>(mazeWidth));

    return {randomX, randomY};
}

std::string Randomizer::getSeed() {
    return seed;
}

std::vector<int> Randomizer::generateSeedNumberList() {
    std::random_device rd;
    std::uniform_int_distribution<> randomInt(1, 9);
    std::mt19937 gen(rd());

    std::vector<int> tempSeedList;
    for (int i{0}; i < seedLength; ++i) {
        int random = randomInt(gen);
        tempSeedList.push_back(random);

        seed.append(std::to_string(random));
    }

    return tempSeedList;
}

std::vector<int> Randomizer::generateSeedNumberList(const std::string &seedString) {
    std::vector<int> tempSeedList;
    seed = seedString;

    for (char const &c: seedString) {
        if (c != ' ') {
            int ia = c - '0';
            tempSeedList.push_back(ia);
        }
    }

    return tempSeedList;
}


unsigned int Randomizer::generateSeed(const std::vector<int> &vector) {
    unsigned int newSeed{0};
    int counter{1};
    std::string numberString;

    for (const auto &number : vector) {
        if (counter <= 2) {
            numberString.append(std::to_string(number));
            counter++;
        } else {
            counter = 1;
        }

        if (counter == 2) {
            newSeed += std::stoi(numberString);
            numberString = "";
        }
    }

    return newSeed;
}


template void Randomizer::shuffleVector<MazeMath::Point>(std::vector<MazeMath::Point> &toShuffle);

template void Randomizer::shuffleVector<int>(std::vector<int> &toShuffle);

template void Randomizer::shuffleVector<myMaze::RoomEntrance>(std::vector<myMaze::RoomEntrance> &toShuffle);
