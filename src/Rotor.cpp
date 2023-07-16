#include "../include/Rotor.h"
#include <iostream>
#include <string.h>

Rotor::Rotor(std::string wiring, int ringSetting, int startPosition)
    :   ringSetting(ringSetting), 
        startPosition(startPosition),
        left("ABCDEFGHIJKLMNOPQRSTUVWXYZ") {
    
    this->position = startPosition;

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
        std::cout << "Rotor wiring not supported" << std::endl;
    }
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
    this->position = (this->position + 1) % 26;
    return this->position;
}