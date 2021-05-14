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

    int seedLength{25};

    unsigned int generateSeed();

    static unsigned int generateSeed(const std::vector<int> &vector);
};


#endif
