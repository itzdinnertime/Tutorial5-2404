#include "defs.h"
#include "RGB.h"

int RGB::getR() const{
    return red;
}

int RGB::getG() const{
    return green;
}

int RGB::getB() const{
    return blue;
}

RGB RGB::WHITE(){
    return RGB(255,255,255);
}

RGB RGB::BLACK(){
    return RGB(0,0,0);
}

RGB RGB::RED(){
    return RGB(255,0,0);
}

RGB RGB::GREEN(){
    return RGB(0,255,0);
}

RGB RGB::BLUE(){
    return RGB(0,0,255);
}

