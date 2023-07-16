#include "../include/Reflector.h"
#include <iostream>
#include <string.h>

Reflector::Reflector(std::string wiring)
    :   left("ABCDEFGHIJKLMNOPQRSTUVWXYZ") {

    if (wiring == "A") {
        this->right = "EJMZALYXVBWFCRQUONTSPIKHGD";
    }
    else if (wiring == "B") {
        this->right = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
    }
    else if (wiring == "C") {
        this->right = "FVPJIAOYEDRZXWGCTKUQSBNMHL";
    }
    else {
        std::cout << "Reflector wiring not supported" << std::endl;
    }
}

char Reflector::reflect(char letter) {
    size_t index = this->left.find(letter);
    char cipher = this->right[index];
    return cipher;
}
