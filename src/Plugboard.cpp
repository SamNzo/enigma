#include "../include/Plugboard.h"

Plugboard::Plugboard(std::vector<std::string> couples)
    :   couples(couples) {

        if (!this->isValid()) {
            throw std::runtime_error("Plugboard configuration is invalid, for more information: './enigma -h plugboard' for more information");
        }
}

char Plugboard::plug(char letter) {

    for (const std::string& letters : this->couples) {
        if (letters[0] == letter) {
            return letters[1];
        }
        else if (letters[1] == letter) {
            return letters[0];
        }
    }

    return letter;
}

bool Plugboard::isValid() {
    std::string concatenatedString;

    for (const std::string& str : this->couples) {
        concatenatedString += str;
    }

    // check if letters are unique
    for (char c : concatenatedString) {
        if (std::count(concatenatedString.begin(), concatenatedString.end(), c) > 1) {
            return false;
        }
    }

    // check if the list is made of 2 letter strings
    for (const std::string& letters : this->couples) {
        if (letters.length() != 2) {
            return false;
        }
    }

    return true;
}
