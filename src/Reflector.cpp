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
    size_t index = this->left.find(letter);
    char cipher = this->right[index];
    return cipher;
}
