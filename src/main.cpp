#include "../include/Enigma.h"
#include <getopt.h>
#include <vector>
#include "Help.cpp"

int main(int argc, char** argv) {
    const char* const short_options = "h::";
    const struct option long_options[] = {
        {"help", optional_argument, nullptr, 'h'},
        {"left-rotor", required_argument, nullptr, 'l'},
        {"middle-rotor", required_argument, nullptr, 'm'},
        {"right-rotor", required_argument, nullptr, 'r'},
        {"reflector", required_argument, nullptr, 'R'},
        {nullptr, 0, nullptr, 0}
    };

    int option;
    bool helpRotor = false;
    bool helpReflector = false;
    while ((option = getopt_long(argc, argv, short_options, long_options, nullptr)) != -1) {
        switch (option) {
            case 'l':
                {
                    std::vector<std::string> arguments;
                    // First argument
                    arguments.push_back(optarg);

                    // Process additional arguments if present
                    for (int i = optind; i < argc && i < optind + 2; ++i) {
                        arguments.push_back(argv[i]);
                    }

                    std::cout << "Option --left-rotor specified with arguments: ";
                    for (const std::string& arg : arguments) {
                        std::cout << arg << " ";
                    }
                    std::cout << std::endl;

                    optind += arguments.size() - 1;  // Update optind to skip processed arguments
                }
                break;
            case 'm':
                {
                    std::vector<std::string> arguments;
                    // First argument
                    arguments.push_back(optarg);

                    // Process additional arguments if present
                    for (int i = optind; i < argc && i < optind + 2; ++i) {
                        arguments.push_back(argv[i]);
                    }

                    std::cout << "Option --middle-rotor specified with arguments: ";
                    for (const std::string& arg : arguments) {
                        std::cout << arg << " ";
                    }
                    std::cout << std::endl;

                    optind += arguments.size() - 1;  // Update optind to skip processed arguments
                }
                break;
            case 'r':
                {
                    std::vector<std::string> arguments;
                    // First argument
                    arguments.push_back(optarg);

                    // Process additional arguments if present
                    for (int i = optind; i < argc && i < optind + 2; ++i) {
                        arguments.push_back(argv[i]);
                    }

                    std::cout << "Option --right-rotor specified with arguments: ";
                    for (const std::string& arg : arguments) {
                        std::cout << arg << " ";
                    }
                    std::cout << std::endl;

                    optind += arguments.size() - 1;  // Update optind to skip processed arguments
                }
                break;
            case 'R':
                std::cout << "Unknown option: " << static_cast<char>(optopt) << std::endl;
                break;
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
            default:
                std::cout << "Invalid option" << std::endl;
                break;
        }
    }

    std::cout << optind << std::endl;

    return 0;
}