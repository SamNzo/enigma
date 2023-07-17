#include "../include/Reflector.h"

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
        throw std::runtime_error("Wiring not supported by the reflector: './enigma -h reflector' for more information");
    }

    std::cout << "Reflector created with wiring: " << wiring << std::endl;
}

char Reflector::reflect(char letter) {
    int index = this->left.find(letter);
    char cipher = this->right[index];
    std::cout << "Letter " << letter << " encoded into " << cipher << " with reflector " << std::endl;
    return cipher;
}
