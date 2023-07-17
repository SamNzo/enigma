#ifndef ENIGMA_H
#define ENIGMA_H
#include <iostream>
#include <string.h>
#include <vector>
#include "Rotor.h"
#include "Reflector.h"

class Enigma {
    private:
        std::vector<Rotor> rotorList;
        std::vector<Reflector> reflectorList;
    public:
        Enigma(std::vector<Rotor> rotorList, std::vector<Reflector> reflectorList);
        std::string encode(std::string message);
};

#endif