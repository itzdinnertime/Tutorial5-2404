#ifndef RGB_H
#define RGB_H

#include "defs.h"

class RGB {
private:
    int red;
    int green;
    int blue;

public:
    // Constructor with default parameters
    RGB(int r = 255, int g = 255, int b = 255) : red(r), green(g), blue(b) {}

    //getter functions
    int getR() const;
    int getG() const;
    int getB() const;

    // Static functions to create predefined colors
    static RGB WHITE();
    static RGB BLACK();
    static RGB RED();
    static RGB GREEN();
    static RGB BLUE();
};

#endif
