#ifndef ENIGMA_H
#define ENIGMA_H
#include <iostream>
#include <string.h>
#include "Rotor.h"
#include "Reflector.h"

class Enigma {
    private:
        Rotor *rotorList;
        Reflector reflector;
    public:
        Enigma(Rotor *rotorList, std::string reflectorWiring);
        std::string encode(std::string message);
};

#endif