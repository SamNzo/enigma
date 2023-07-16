#include "../include/Enigma.h"
#include <iostream>
#include <string.h>

Enigma::Enigma(std::string rotorWiring, std::string reflectorWiring) {
    this->rotor = Rotor(rotorWiring, 0, 0);
    this->reflector = Reflector(reflectorWiring);
}

std::string Enigma::encode(std::string message) {
    std::string cipher = "";
    char letter;
    for (size_t i=0; i<message.length(); i++) {
        letter = this->rotor.forward(message[i]);
        letter = this->reflector.reflect(letter);
        letter = this->rotor.backward(letter);
        cipher += letter;
        std::cout << "Encoded letter " << message[i] << ": " << letter << std::endl;
    }
    return cipher;
}
