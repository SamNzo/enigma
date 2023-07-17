#include "../include/Enigma.h"
#include <iostream>
#include <string.h>

Enigma::Enigma(std::vector<Rotor> rotorList, std::vector<Reflector> reflectorList)
    :   rotorList(rotorList),
        reflectorList(reflectorList) {
            
}

std::string Enigma::encode(std::string message) {
    std::string cipher = "";
    /*int position;
    char letter;
    for (size_t i=0; i<message.length(); i++) {
        position = this->rotor.turn();
        letter = this->rotor.forward(message[i]);
        letter = this->reflector.reflect(letter);
        letter = this->rotor.backward(letter);
        cipher += letter;
        std::cout << "Encoded letter " << message[i] << ": " << letter << std::endl;
    }*/
    return cipher;
}
