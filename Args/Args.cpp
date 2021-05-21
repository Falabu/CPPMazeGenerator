#include "Args.h"

Args::Args(int number, char *args[]) :
        number(number),
        args(args),
        width(50),
        height(50),
        _haveSeed(false) {}

void Args::parseArgs() {
    if (number >= 3) {
        std::istringstream w_in(args[1]);
        std::istringstream h_in(args[2]);
        int val_w;
        int val_h;

        if (w_in >> val_w) {
            width = val_w;
        }

        if (h_in >> val_h) {
            height = val_h;
        }
    } else if (number >= 4) {
        seed = args[3];
        _haveSeed = true;
    }
}

bool Args::haveSeed() {
    return _haveSeed;
}

int Args::getWidth() {
    return width;
}

int Args::getHeight() {
    return height;
}

std::string Args::getSeed() {
    return seed;
}
