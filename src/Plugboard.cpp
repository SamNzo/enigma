#include "../include/Plugboard.h"

Plugboard::Plugboard(std::vector<std::string> couples)
    :   couples(couples) {

        if (this->hasDuplicateCharacters(this->couples)) {
            throw std::runtime_error("A letter can only be plugged with a single other one: './enigma -h plugboard' for more information");
        }
}

char Plugboard::plug(char letter) {
    return letter;
}

bool Plugboard::hasDuplicateCharacters(const std::vector<std::string>& strings) {
    std::string concatenatedString;
    for (const std::string& str : strings) {
        concatenatedString += str;
    }

    for (char c : concatenatedString) {
        if (std::count(concatenatedString.begin(), concatenatedString.end(), c) > 1) {
            return true;
        }
    }
    return false;
}
