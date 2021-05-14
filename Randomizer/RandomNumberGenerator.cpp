#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator() {
    unsigned int seedTemp = generateSeed();
    std::srand(seedTemp);

    generateNumbers();
}

RandomNumberGenerator::RandomNumberGenerator(const std::string &seedString) : seedString(seedString) {
    std::vector<int> initialSeed;
    for (char const &c: seedString) {
        if (c != ' ') {
            int ia = c - '0';
            initialSeed.push_back(ia);
        }
    }

    unsigned int seed = generateSeed(initialSeed);

    std::srand(seed);

    generateNumbers();
}

unsigned int RandomNumberGenerator::generateSeed() {
    std::random_device rd;
    std::uniform_int_distribution<> randomInt(1, 9);
    std::mt19937 gen(rd());

    std::vector<int> initialSeed;

    for (int i{0}; i < seedLength; ++i) {
        int random = randomInt(gen);
        seedString.append(std::to_string(random));
        initialSeed.push_back(random);
    }

    return generateSeed(initialSeed);
}

unsigned int RandomNumberGenerator::generateSeed(const std::vector<int> &vector) {
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

void RandomNumberGenerator::generateNumbers() {
    for (int i{0}; i < randomNumberCount; ++i) {
        numbers.push_back(std::rand());
    }
}

unsigned long int RandomNumberGenerator::operator()() {
    size_t numbersQty = numbers.size();
    if (currentNumberIndex >= numbersQty) {
        currentNumberIndex = 0;
    }

    long int selected{numbers[currentNumberIndex]};

    currentNumberIndex++;

    return selected;
}

std::string RandomNumberGenerator::seedToString() {
    return seedString;
}
