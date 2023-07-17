#include "../include/Enigma.h"

Enigma::Enigma(std::vector<Rotor> rotorList, std::vector<Reflector> reflectorList)
    :   rotorList(rotorList),
        reflectorList(reflectorList) {

        this->createDefaultRotors(this->rotorList);
        this->createDefaultReflector(this->reflectorList);

            
}

std::string Enigma::encode(std::string message) {
    std::string cipher = "";
    /*int position;
    char letter;
    for (size_t i=0; i<message.length(); i++) {
        position = this->rotor.turn();
        letter = this->rotor.forward(message[i]);
        letter = this->reflector.reflect(letter);
        letter = this->rotor.backward(letter);
        cipher += letter;
        std::cout << "Encoded letter " << message[i] << ": " << letter << std::endl;
    }*/
    return cipher;
}

void Enigma::createDefaultRotors(std::vector<Rotor> rotorList) {
    // Check which rotors were provided by the user [1, 2, 3], the 4th one is not added if not provided
    std::vector<int> rotorsProvided;

    if (rotorList.size() == 0) {
        rotorsProvided.push_back(0);
    }
    else {
        for (int i=0; i<rotorList.size(); i++) {
            rotorsProvided.push_back(rotorList[i].position);
        }     
    }

    // Left rotor not provided (if 1 not in list)
    if (std::find(rotorsProvided.begin(), rotorsProvided.end(), 1) == rotorsProvided.end()) {
        // Default left rotor
        Rotor leftRotor = Rotor("I", 0, 0, 1);
        this->rotorList.push_back(leftRotor);
    }

    // Middle rotor not provided (if 2 not in list)
    if (std::find(rotorsProvided.begin(), rotorsProvided.end(), 2) == rotorsProvided.end()) {
        // Default middle rotor
        Rotor middleRotor = Rotor("II", 0, 0, 2);
        this->rotorList.push_back(middleRotor);
    }

    // Right rotor not provided (if 3 not in list)
    if (std::find(rotorsProvided.begin(), rotorsProvided.end(), 3) == rotorsProvided.end()) {
        // Default right rotor
        Rotor rightRotor = Rotor("III", 0, 0, 3);
        this->rotorList.push_back(rightRotor);
    }
}

void Enigma::createDefaultReflector(std::vector<Reflector> reflectorList) {
    // Check if a reflector was provided by the user
    
    if (reflectorList.size() == 0) {
        // Default reflector
            Reflector reflector = Reflector("B");
            this->reflectorList.push_back(reflector);
    }
}