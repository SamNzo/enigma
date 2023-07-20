#include "../include/Rotor.h"

Rotor::Rotor(std::string wiring, int ringSetting, int startPosition, int position)
    :   ringSetting(ringSetting), 
        startPosition(startPosition),
        position(position),
        left("ABCDEFGHIJKLMNOPQRSTUVWXYZ") {

    if (wiring == "I") {
        this->right = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
        this->notch = {16};
    }
    else if (wiring == "II") {
        this->right = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
        this->notch = {4};
    }
    else if (wiring == "III") {
        this->right = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
        this->notch = {21};
    }
    else if (wiring == "IV") {
        this->right = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
        this->notch = {9};
    }
    else if (wiring == "V") {
        this->right = "VZBRGITYUPSDNHLXAWMJQOFECK";
        this->notch = {25};
    }
    else if (wiring == "VI") {
        this->right = "JPGVOUMFYQBENHZRDKASXLICTW";
        this->notch = {12, 25};
    }
    else if (wiring == "VII") {
        this->right = "NZJHGRCXMYSWBOUFAIVLPEKQDT";
        this->notch = {12, 25};
    }
    else if (wiring == "VIII") {
        this->right = "FKQHTLXOCBJSPDZRAMEWNIUYGV";
        this->notch = {12, 25};
    }
    else {
        throw std::runtime_error("Wiring not supported by rotor: './enigma -h rotor' for more information");
    }

    this->setRing();
}

char Rotor::forward(char letter, int previousRotorOffset) {
    int index = this->left.find(letter);
    // Make sure that index is always between 0 and 25 even for negative numbers (-1 = 25)
    index = ((index + this->startPosition - previousRotorOffset) % 26 + 26) % 26;
    char cipher = this->right[index];
    return cipher;
}

char Rotor::backward(char letter, int previousRotorOffset) {
    int index = this->left.find(letter);
    // Make sure that index is always between 0 and 25 even for negative numbers (-1 = 25)
    index = ((index + this->startPosition - previousRotorOffset) % 26 + 26) % 26;
    // Get the index of the letter in the wiring
    int index2 = this->right.find(this->left[index]);
    // Read from the alphabet
    char cipher = this->left[index2];
    return cipher;
}

bool Rotor::turn() {
    bool notchReached = false;
    // Check if one of the notches is reached
    auto it = std::find(this->notch.begin(), this->notch.end(), this->startPosition);
    if (it != this->notch.end()) {
        notchReached = true;
    }
    this->startPosition = (this->startPosition + 1) % 26;
    return notchReached;
}

void Rotor::setRing() {
    char letter;
    this->startPosition = (this->startPosition - this->ringSetting) % 26;

    for (int i=0; i < this->notch.size(); i++) {
        letter = this->left[(this->notch[i] - this->ringSetting) % 26];
        this->notch[i] = this->left.find(letter);
    }

}
