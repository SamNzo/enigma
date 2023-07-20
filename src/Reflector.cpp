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
    else if (wiring == "B-Thin") {
        this->right = "ENKQAUYWJICOPBLMDXZVFTHRGS";
    }
    else if (wiring == "C-Thin") {
        this->right = "RDOBJNTKVEHMLFCWZAXGYIPSUQ";
    }
    else {
        throw std::runtime_error("Wiring not supported by the reflector: './enigma -h reflector' for more information");
    }
}

char Reflector::reflect(char letter, int previousRotorOffset) {
    int index = this->left.find(letter);
    index = ((index - previousRotorOffset) % 26 + 26) % 26;
    char cipher = this->right[index];
    return cipher;
}
