#include "../include/Enigma.h"

Enigma::Enigma(std::vector<Rotor> rotorList, std::vector<Reflector> reflectorList)
    :   rotorList(rotorList),
        reflectorList(reflectorList),
        plugboardList(plugboardList) {

        this->createDefaultRotors(this->rotorList);
        this->createDefaultReflector(this->reflectorList);

        // Sort list by increasing position in the machine
        std::sort(this->rotorList.begin(), this->rotorList.end(), compareByPosition);           
}

std::string Enigma::encode(std::string message) {
    std::string cipher = "";
    char letter;
    int previousRotorOffset;
    int nextToTurn1;
    int nextToTurn2;
    // For each letter to encode
    for (int i=0; i<message.length(); i++) {
        std::cout << "------------------------------" << std::endl;
        letter = message[i];
        this->turnCheckNotches();
        // Go through each rotor right to left
        for (int j=this->rotorList.size()-1; j >= 0; j--) {
            // If the rotor is the first one, previous offset is 0
            if (this->rotorList[j].position == rotorList.size()) {
                letter = this->rotorList[j].forward(letter, 0);
            }
            else {
                previousRotorOffset = this->rotorList[j+1].startPosition;
                letter = this->rotorList[j].forward(letter, previousRotorOffset);               
            }
        }
        // Go through the reflector
        letter = this->reflectorList[0].reflect(letter, this->rotorList.front().startPosition);
        // Go through each rotor again from left to right
        for (int j=0; j < this->rotorList.size(); j++) {
            // If the rotor is the first one, previous offset is 0
            if (this->rotorList[j].position == 1) {
                letter = this->rotorList[j].backward(letter, 0);
            }
            // If the rotor is the last one, adapt offset from letters wiring (substract the position on the alphabet)
            else if (this->rotorList[j].position == this->rotorList.size()) {
                previousRotorOffset = this->rotorList[j-1].startPosition;
                letter = this->rotorList[j].backward(letter, previousRotorOffset);
                int index = this->rotorList[j].left.find(letter);
                letter = this->rotorList[j].left[((index - this->rotorList[j].startPosition) % 26 + 26) % 26];
            }
            // Otherwise
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

void Enigma::turnCheckNotches() {
    bool notch;
    int rotorListSize = this->rotorList.size();
    // Make the first rotor turn
    notch = this->rotorList.back().turn();
    // If second rotor is turning because of notch
    if (notch) {
        notch = this->rotorList[rotorListSize-2].turn();
        // If third rotor is turning because of notch
        if (notch) {
            notch = this->rotorList[rotorListSize-3].turn();
            // If there are 4 rotor and the 4rth turns because of notch
            if (this->rotorList[rotorListSize-3].position != 1 && notch) {
                std::cout << "fourth rotor turning" << std::endl;
                notch = this->rotorList[rotorListSize-4].turn();
            }
        }
    }
}