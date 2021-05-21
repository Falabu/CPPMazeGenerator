#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H

#include <vector>
#include <random>
#include <string>
#include <algorithm>

class NumberGenerator {
public:
    explicit NumberGenerator();

    explicit NumberGenerator(const std::string &seedString);

    std::string getSeed();

    unsigned long int operator()();

private:
    std::vector<int> seedNumberList;

    int seedLength{25};

    std::vector<int> generateSeedNumberList(const std::string &seedString);

    std::vector<int> generateSeedNumberList() const;

    static unsigned int generateSeed(const std::vector<int> &vector);
};


#endif
