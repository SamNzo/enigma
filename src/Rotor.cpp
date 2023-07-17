#include "../include/Rotor.h"

Rotor::Rotor(std::string wiring, int ringSetting, int startPosition, int position)
    :   ringSetting(ringSetting), 
        startPosition(startPosition),
        position(position),
        left("ABCDEFGHIJKLMNOPQRSTUVWXYZ") {

    if (wiring == "I") {
        this->right = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
    }
    else if (wiring == "II") {
        this->right = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
    }
    else if (wiring == "III") {
        this->right = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
    }
    else {
        throw std::runtime_error("Wiring not supported by rotor: './enigma -h rotor' for more information");
    }

    std::cout << "Rotor created with parameters: " << wiring << " " << ringSetting << " " << startPosition << std::endl; 
}

char Rotor::forward(char letter) {
    size_t index = this->left.find(letter + this->position);
    char cipher = this->right[index];
    return cipher;
}

char Rotor::backward(char letter) {
    size_t index = this->right.find(letter + this->position);
    char cipher = this->left[index];
    return cipher;
}

int Rotor::turn() {
    this->startPosition = (this->startPosition + 1) % 26;
    return this->startPosition;
}