#ifndef ENIGMA_H
#define ENIGMA_H
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "Rotor.h"
#include "Reflector.h"

class Enigma {
    private:
        std::vector<Rotor> rotorList;
        std::vector<Reflector> reflectorList;
    public:
        Enigma(std::vector<Rotor> rotorList, std::vector<Reflector> reflectorList);
        std::string encode(std::string message);
        void createDefaultRotors(std::vector<Rotor> rotorList);
        void createDefaultReflector(std::vector<Reflector> reflectorList);
        static bool compareByPosition(const Rotor& rotor1, const Rotor& rotor2);
};

#endif