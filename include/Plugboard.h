#ifndef PLUGBOARD_H
#define PLUGBOARD_H
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

class Plugboard {
    private:
        std::vector<std::string> couples;
    public:
        Plugboard(std::vector<std::string> couples);
        char plug(char letter);
        bool hasDuplicateCharacters(const std::vector<std::string>& strings);
};

#endif