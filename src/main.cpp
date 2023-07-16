#include "../include/Enigma.h"

// compilation
// https://stackoverflow.com/questions/30064686/making-and-compiling-c-projects-with-multiple-files
int main() {

    std::string rotorWiring = "III";
    std::string reflectorWiring = "B";

    Enigma enigma = Enigma(rotorWiring, reflectorWiring);

    std::string cipher = enigma.encode("SAM");
    std::cout << "Encoded message: " << cipher << std::endl;

    return 0;
}