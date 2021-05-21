#include "NumberGenerator.h"

NumberGenerator::NumberGenerator() {
    seedNumberList = generateSeedNumberList();

    std::srand(generateSeed(seedNumberList));
}

NumberGenerator::NumberGenerator(const std::string &seedString) {
    seedNumberList = generateSeedNumberList(seedString);

    std::srand(generateSeed(seedNumberList));
}

std::vector<int> NumberGenerator::generateSeedNumberList() const {
    std::random_device rd;
    std::uniform_int_distribution<> randomInt(1, 9);
    std::mt19937 gen(rd());

    std::vector<int> tempSeedList;
    for (int i{0}; i < seedLength; ++i) {
        int random = randomInt(gen);
        tempSeedList.push_back(random);
    }

    return tempSeedList;
}

std::vector<int> NumberGenerator::generateSeedNumberList(const std::string &seedString) {
    std::vector<int> tempSeedList;

    for (char const &c: seedString) {
        if (c != ' ') {
            int ia = c - '0';
            tempSeedList.push_back(ia);
        }
    }

    return tempSeedList;
}


unsigned int NumberGenerator::generateSeed(const std::vector<int> &vector) {
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

unsigned long int NumberGenerator::operator()() {
    return std::rand();
}

std::string NumberGenerator::getSeed() {
    std::string seedString;

    for (const auto &item : seedNumberList) {
        seedString.append(std::to_string(item));
    }

    return seedString;
}
