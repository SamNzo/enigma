#include "../include/Enigma.h"
#include <getopt.h>
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

/* Function to map letters to integers */
int getIndexInAlphabet(const std::string& letter) {
    if (letter.length() == 1) {
        char ch = letter[0];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            ch = std::tolower(ch);  // Convert to lowercase
            return ch - 'a';
        }
    }
    return -1;  // Indicate invalid input
}

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
        int leftRingSetting = getIndexInAlphabet(leftRotorParam[1]);
        int leftStartPosition = getIndexInAlphabet(leftRotorParam[2]);
        if (leftRingSetting != -1 && leftStartPosition != -1) {
            try {
                Rotor leftRotor = Rotor(leftRotorParam[0], leftRingSetting, leftStartPosition, 1);
                rotorList.push_back(leftRotor);
            } catch (const std::exception& ex) {
                std::cerr << "Exception occurred: " << ex.what() << std::endl;
                return EXIT_FAILURE;
            }
        }
        else {
            std::cerr << "Exception occurred: The ring setting and starting position of the rotor(s) must be a letter [aA-zZ]" << std::endl;
            return EXIT_FAILURE;
        }
    }

    if (middleRotorProvided) {
        int middleRingSetting = getIndexInAlphabet(middleRotorParam[1]);
        int middleStartPosition = getIndexInAlphabet(middleRotorParam[2]);
        if (middleRingSetting != -1 && middleStartPosition != -1) {
            try {
                Rotor middleRotor = Rotor(middleRotorParam[0], middleRingSetting, middleStartPosition, 2);
                rotorList.push_back(middleRotor);
            } catch (const std::exception& ex) {
                std::cerr << "Exception occurred: " << ex.what() << std::endl;
                return EXIT_FAILURE;
            }
        }
        else {
            std::cerr << "Exception occurred: The ring setting and starting position of the rotor(s) must be a letter [aA-zZ]" << std::endl;
            return EXIT_FAILURE;
        }
    }

    if (rightRotorProvided) {
        int rightRingSetting = getIndexInAlphabet(rightRotorParam[1]);
        int rightStartPosition = getIndexInAlphabet(rightRotorParam[2]);
        if (rightRingSetting != -1 && rightStartPosition != -1) {
            try {
                Rotor rightRotor = Rotor(rightRotorParam[0], rightRingSetting, rightStartPosition, 3);
                rotorList.push_back(rightRotor);
            } catch (const std::exception& ex) {
                std::cerr << "Exception occurred: " << ex.what() << std::endl;
                return EXIT_FAILURE;
            }
        }
        else {
            std::cerr << "Exception occurred: The ring setting and starting position of the rotor(s) must be a letter [aA-zZ]" << std::endl;
            return EXIT_FAILURE;
        }
    }

    if (fourthRotorProvided) {
        int fourthRingSetting = getIndexInAlphabet(fourthRotorParam[1]);
        int fourthStartPosition = getIndexInAlphabet(fourthRotorParam[2]);
        if (fourthRingSetting != -1 && fourthStartPosition != -1) {
            try {
                Rotor fourthRotor = Rotor(rightRotorParam[0], fourthRingSetting, fourthStartPosition, 4);
                rotorList.push_back(fourthRotor);
            } catch (const std::exception& ex) {
                std::cerr << "Exception occurred: " << ex.what() << std::endl;
                return EXIT_FAILURE;
            }
        }
        else {
            std::cerr << "Exception occurred: The ring setting and starting position of the rotor(s) must be a letter [aA-zZ]" << std::endl;
            return EXIT_FAILURE;
        }
    }

    if (reflectorProvided) {
        try {
            Reflector reflector = Reflector(reflectorWiring);
            reflectorList.push_back(reflector);
        } catch (const std::exception& ex) {
            std::cerr << "Exception occurred: " << ex.what() << std::endl;
            return EXIT_FAILURE;
        }

    }

    Enigma enigma = Enigma(rotorList, reflectorList);


    return 0;
}