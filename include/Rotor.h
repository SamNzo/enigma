#ifndef ROTOR_H
#define ROTOR_H
#include <iostream>
#include <string.h>

class Rotor {
    private:
        std::string left;  
        std::string right;
        int ringSetting;
        int startPosition;
        int position;
    public:
        Rotor(std::string wiring, int ringSetting, int startPosition);
        char forward(char letter);
        char backward(char letter);
        int turn();
};

#endif