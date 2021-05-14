#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H

#include <vector>
#include <random>
#include <string>
#include <algorithm>

class RandomNumberGenerator {
public:
    RandomNumberGenerator();

    explicit RandomNumberGenerator(const std::string &seedString);

    std::string seedToString();

    unsigned long int operator()();

private:
    std::string seedString;

    std::vector<unsigned int> numbers;

    int randomNumberCount{1000};

    int seedLength{25};

    int currentNumberIndex{0};

    void generateNumbers();

    unsigned int generateSeed();

    static unsigned int generateSeed(const std::vector<int> &vector);
};


#endif
