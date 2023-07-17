#include "../include/Enigma.h"

Enigma::Enigma(std::vector<Rotor> rotorList, std::vector<Reflector> reflectorList)
    :   rotorList(rotorList),
        reflectorList(reflectorList) {

        this->createDefaultRotors(this->rotorList);
        this->createDefaultReflector(this->reflectorList);

        // Sort list by increasing position in the machine
        std::sort(this->rotorList.begin(), this->rotorList.end(), compareByPosition);           
}

std::string Enigma::encode(std::string message) {
    std::string cipher = "";
    char letter;
    int previousRotorOffset;
    // For each letter to encode
    for (int i=0; i<message.length(); i++) {
        std::cout << "------------------------------" << std::endl;
        letter = message[i];
        // Go through each rotor right to left
        for (int j=this->rotorList.size()-1; j >= 0; j--) {
            // If the rotor is the first one, turn
            if (this->rotorList[j].position == rotorList.size()) {
                this->rotorList[j].turn();
                letter = this->rotorList[j].forward(letter, 0);
            }
            else {
                previousRotorOffset = this->rotorList[j+1].startPosition;
                letter = this->rotorList[j].forward(letter, previousRotorOffset);               
            }
        }
        // Go through the reflector
        letter = this->reflectorList[0].reflect(letter);
        // Go through each rotor again from left to right
        for (int j=0; j < this->rotorList.size(); j++) {
            // If the rotor is the first one
            if (this->rotorList[j].position == 1) {
                letter = this->rotorList[j].backward(letter, 0);
            }
            else if (this->rotorList[j].position == this->rotorList.size()) {
                previousRotorOffset = this->rotorList[j-1].startPosition;
                letter = this->rotorList[j].backward(letter, previousRotorOffset);
                int index = this->rotorList[j].left.find(letter);
                letter = this->rotorList[j].left[((index - this->rotorList[j].startPosition) % 26 + 26) % 26];
            }
            else {
                previousRotorOffset = this->rotorList[j-1].startPosition;
                letter = this->rotorList[j].backward(letter, previousRotorOffset);
            }
        }
        cipher += letter;
    std::cout << "Encoded letter " << message[i] << ": " << letter << std::endl;
    }
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

bool Enigma::compareByPosition(const Rotor& rotor1, const Rotor& rotor2) {
    return rotor1.position < rotor2.position;
}