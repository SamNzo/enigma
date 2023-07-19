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
    std::cout << "Index: " << index << std::endl;
    char cipher = this->right[index];
    std::cout << "Letter " << letter << " encoded into " << cipher << " with reflector " << std::endl;
    return cipher;
}
