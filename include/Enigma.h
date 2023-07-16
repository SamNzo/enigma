#ifndef ENIGMA_H
#define ENIGMA_H
#include <iostream>
#include <string.h>
#include "Rotor.h"
#include "Reflector.h"

class Enigma {
    private:
        Rotor rotor;
        Reflector reflector;
    public:
        Enigma(std::string rotorWiring, std::string reflectorWiring);
        std::string encode(std::string message);
};

#endif