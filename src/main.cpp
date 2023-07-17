#include "../include/Enigma.h"
#include <getopt.h>
#include <vector>
#include "Help.cpp"

/* Rotors parameters */
std::vector<std::string> leftRotorParam;
std::vector<std::string> middleRotorParam;
std::vector<std::string> rightRotorParam;
std::vector<std::string> fourthRotorParam;

/* Rotor booleans */
bool leftRotorProvided = false;
bool middleRotorProvided = false;
bool rightRotorProvided = false;
bool fourthRotorProvided = false;

/* Reflector parameter */
std::string reflectorWiring;

/* Reflector boolean */
bool reflectorProvided = false;

/* Help booleans */
bool helpRotor = false;
bool helpReflector = false;

int main(int argc, char** argv) {

    /* Program command line options */
    const char* const short_options = "h::lmrRf";
    const struct option long_options[] = {
        {"help", optional_argument, nullptr, 'h'},
        {"left-rotor", required_argument, nullptr, 'l'},
        {"middle-rotor", required_argument, nullptr, 'm'},
        {"right-rotor", required_argument, nullptr, 'r'},
        {"reflector", required_argument, nullptr, 'R'},
        {"fourth-rotor", required_argument, nullptr, 'f'},

        {nullptr, 0, nullptr, 0}
    };

    /* Parse command line */
    int option;

    while ((option = getopt_long(argc, argv, short_options, long_options, nullptr)) != -1) {
        switch (option) {
            case 'h':
                {
                    if (optarg == NULL && optind < argc && argv[optind][0] != '-') {
                        optarg = argv[optind++];
                        std::string argument(optarg);
                        if (argument == "rotor") {
                            helpRotor = true;
                        } 
                        else if (argument == "reflector") {
                            helpReflector = true;
                        }
                    }
                    printHelp(helpRotor, helpReflector);
                }
                break;
            case 'l':
                {
                    // Left rotor
                    leftRotorProvided = true;
                    std::vector<std::string> arguments;
                    // First argument
                    arguments.push_back(optarg);

                    // Process additional arguments if present
                    for (int i = optind; i < argc && i < optind + 2; ++i) {
                        arguments.push_back(argv[i]);
                    }

                    // Add arguments to rotor params
                    for (int i = 0; i < arguments.size(); i++) {
                        leftRotorParam.push_back(arguments[i]);
                    }

                    optind += arguments.size() - 1;  // Update optind to skip processed arguments
                }
                break;
            case 'm':
                {
                    // Middle rotor
                    middleRotorProvided = true;
                    std::vector<std::string> arguments;
                    // First argument
                    arguments.push_back(optarg);

                    // Process additional arguments if present
                    for (int i = optind; i < argc && i < optind + 2; ++i) {
                        arguments.push_back(argv[i]);
                    }
                    
                    // Add arguments to rotor params
                    for (int i = 0; i < arguments.size(); i++) {
                        middleRotorParam.push_back(arguments[i]);
                    }

                    optind += arguments.size() - 1;  // Update optind to skip processed arguments
                }
                break;
            case 'r':
                {
                    // Right rotor
                    rightRotorProvided = true;
                    std::vector<std::string> arguments;
                    // First argument
                    arguments.push_back(optarg);

                    // Process additional arguments if present
                    for (int i = optind; i < argc && i < optind + 2; ++i) {
                        arguments.push_back(argv[i]);
                    }
                    
                    // Add arguments to rotor params
                    for (int i = 0; i < arguments.size(); i++) {
                        rightRotorParam.push_back(arguments[i]);
                    }

                    optind += arguments.size() - 1;  // Update optind to skip processed arguments
                }
                break;
            case 'R':
                {
                    // Reflector
                    reflectorProvided = true;
                    reflectorWiring = optarg;
                }
                break;
            case 'f':
                {
                    // Fourth rotor
                    fourthRotorProvided = true;
                    std::vector<std::string> arguments;
                    // First argument
                    arguments.push_back(optarg);

                    // Process additional arguments if present
                    for (int i = optind; i < argc && i < optind + 2; ++i) {
                        arguments.push_back(argv[i]);
                    }
                    
                    // Add arguments to rotor params
                    for (int i = 0; i < arguments.size(); i++) {
                        fourthRotorParam.push_back(arguments[i]);
                    }

                    optind += arguments.size() - 1;  // Update optind to skip processed arguments
                }
                break;
            default:
                std::cout << "Invalid option" << std::endl;
                break;
        }
    }

    /* Create enigma machine */
    std::vector<Rotor> rotorList;
    std::vector<Reflector> reflectorList;

    if (leftRotorProvided) {
        Rotor leftRotor = Rotor(leftRotorParam[0], std::stoi(leftRotorParam[1]), std::stoi(leftRotorParam[2]), 1);
        rotorList.push_back(leftRotor);
    }

    if (middleRotorProvided) {
        Rotor middleRotor = Rotor(middleRotorParam[0], std::stoi(middleRotorParam[1]), std::stoi(middleRotorParam[2]), 2);
        rotorList.push_back(middleRotor);
    }

    if (rightRotorProvided) {
        Rotor rightRotor = Rotor(rightRotorParam[0], std::stoi(rightRotorParam[1]), std::stoi(rightRotorParam[2]), 3);
        rotorList.push_back(rightRotor);
    }

    if (fourthRotorProvided) {
        Rotor fourthRotor = Rotor(fourthRotorParam[0], std::stoi(fourthRotorParam[1]), std::stoi(fourthRotorParam[2]), 4);
        rotorList.push_back(fourthRotor);
    }

    if (reflectorProvided) {
        Reflector reflector = Reflector(reflectorWiring);
        reflectorList.push_back(reflector);
    }

    Enigma enigma = Enigma(rotorList, reflectorList);

    /* */

    return 0;
}