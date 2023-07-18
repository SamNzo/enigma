#ifndef ENIGMA_H
#define ENIGMA_H
#include <stdexcept>
#include "Rotor.h"
#include "Reflector.h"
#include "Plugboard.h"

class Enigma {
    private:
        std::vector<Rotor> rotorList;
        std::vector<Reflector> reflectorList;
        std::vector<Plugboard> plugboardList;
    public:
        Enigma(std::vector<Rotor> rotorList, std::vector<Reflector> reflectorList);
        std::string encode(std::string message);
        void createDefaultRotors(std::vector<Rotor> rotorList);
        void createDefaultReflector(std::vector<Reflector> reflectorList);
        void turnCheckNotches();
        static bool compareByPosition(const Rotor& rotor1, const Rotor& rotor2);
};

#endif