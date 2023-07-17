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
    public:
        Rotor(std::string wiring, int ringSetting, int startPosition, int position);
        char forward(char letter);
        char backward(char letter);
        int turn();
        int position; // position in the machine [1, 2, 3, (4)]
};

#endif