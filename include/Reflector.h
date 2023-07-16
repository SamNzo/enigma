#ifndef REFLECTOR_H
#define REFLECTOR_H
#include <iostream>
#include <string.h>

class Reflector {
    private:
        std::string left;  
        std::string right;
    public:
        Reflector(std::string wiring);
        char reflect(char letter);
};

#endif