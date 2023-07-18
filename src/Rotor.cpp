#include "../include/Rotor.h"

Rotor::Rotor(std::string wiring, int ringSetting, int startPosition, int position)
    :   ringSetting(ringSetting), 
        startPosition(startPosition),
        position(position),
        left("ABCDEFGHIJKLMNOPQRSTUVWXYZ") {

    if (wiring == "I") {
        this->right = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
        this->notch = 16;
    }
    else if (wiring == "II") {
        this->right = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
        this->notch = 4;
    }
    else if (wiring == "III") {
        this->right = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
        this->notch = 21;
    }
    else if (wiring == "IV") {
        this->right = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
        this->notch = 9;
    }
    else if (wiring == "V") {
        this->right = "VZBRGITYUPSDNHLXAWMJQOFECK";
        this->notch = 25;
    }
    else if (wiring == "VI") {
        this->right = "JPGVOUMFYQBENHZRDKASXLICTW";
        this->notch = 25;
    }
    else if (wiring == "VII") {
        this->right = "NZJHGRCXMYSWBOUFAIVLPEKQDT";
        this->notch = 25;
    }
    else if (wiring == "VIII") {
        this->right = "FKQHTLXOCBJSPDZRAMEWNIUYGV";
        this->notch = 25;
    }
    else {
        throw std::runtime_error("Wiring not supported by rotor: './enigma -h rotor' for more information");
    }

    std::cout << "Rotor created with parameters: " << wiring << " " << ringSetting << " " << startPosition << std::endl; 
}

char Rotor::forward(char letter, int previousRotorOffset) {
    std::cout << "Rotor " << this->position << " has letter " << letter << " and previousOffset " << previousRotorOffset << std::endl;
    int index = this->left.find(letter);
    // Make sure that index is always between 0 and 25 even for negative numbers (-1 = 25)
    index = ((index + this->startPosition - previousRotorOffset) % 26 + 26) % 26;
    std::cout << "Index: " << index << std::endl;
    char cipher = this->right[index];
    std::cout << "Letter " << letter << " encoded into " << cipher << " with rotor " << this->position << std::endl;
    return cipher;
}

char Rotor::backward(char letter, int previousRotorOffset) {
    std::cout << "Rotor " << this->position << " has letter " << letter << " and previousOffset " << previousRotorOffset << std::endl;
    int index = this->left.find(letter);
    // Make sure that index is always between 0 and 25 even for negative numbers (-1 = 25)
    index = ((index + this->startPosition - previousRotorOffset) % 26 + 26) % 26;
    // Get the index of the letter in the wiring
    int index2 = this->right.find(this->left[index]);
    // Read from the alphabet
    char cipher = this->left[index2];
    std::cout << "Letter " << letter << " encoded into " << cipher << " with rotor " << this->position << std::endl;
    return cipher;
}

bool Rotor::turn() {
    bool notchReached = false;
    if (this->notch == this->startPosition) {
        notchReached = true;
        std::cout << "Rotor " << this->position << " makes rotor " << this->position - 1 << " turn" << std::endl;
    }
    this->startPosition = (this->startPosition + 1) % 26;
    std::cout << "Rotor " << this->position << " just turned and is in position " << this->startPosition << std::endl;
    return notchReached;
}
