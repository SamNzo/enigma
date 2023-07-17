#ifndef ROTOR_H
#define ROTOR_H
#include <iostream>
#include <string.h>

class Rotor {
    private:

        int ringSetting;

    public:
        Rotor(std::string wiring, int ringSetting, int startPosition, int position);
        char forward(char letter, int previousRotorOffset);
        char backward(char letter, int previousRotorOffset);
        void turn();
        std::string left;  
        std::string right;
        int startPosition;
        int position; // position in the machine [1, 2, 3, (4)]
};

#endif