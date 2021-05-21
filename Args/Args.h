#ifndef MAZEGENERATOR_ARGS_H
#define MAZEGENERATOR_ARGS_H

#include <vector>
#include <string>
#include <sstream>

class Args {
public:
    Args(int number, char *args[]);

    bool haveSeed();

    int getWidth();

    int getHeight();

    std::string getSeed();

private:
    int number;
    char **args;
    bool _haveSeed;
    int width, height;
    std::string seed;

    void parseArgs();
};


#endif
