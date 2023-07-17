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

char Rotor::forward(char letter, int previousRotorOffset) {
    std::cout << "Rotor " << this->position << " has letter " << letter << " and previousOffset " << previousRotorOffset << std::endl;
    int index = this->left.find(letter + this->startPosition - previousRotorOffset);
    // Make sure that index is always between 0 and 25 even for negative numbers (-1 = 25)
    index = (index % 26 + 26) % 26;
    std::cout << "Index: " << index << std::endl;
    char cipher = this->right[index];
    std::cout << "Letter " << letter << " encoded into " << cipher << " with rotor " << this->position << std::endl;
    return cipher;
}

char Rotor::backward(char letter, int previousRotorOffset) {
    std::cout << "Rotor " << this->position << " has letter " << letter << " and previousOffset " << previousRotorOffset << std::endl;
    int index = this->right.find(letter + this->startPosition - previousRotorOffset);
    // Make sure that index is always between 0 and 25 even for negative numbers (-1 = 25)
    index = (index % 26 + 26) % 26;
    char cipher = this->left[index];
    std::cout << "Letter " << letter << " encoded into " << cipher << " with rotor " << this->position << std::endl;
    return cipher;
}

void Rotor::turn() {
    this->startPosition = (this->startPosition + 1) % 26;
    std::cout << "Rotor " << this->position << " just turned and is in position " << this->startPosition << std::endl;
}
