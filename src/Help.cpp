#include <iostream>

void printHelp(bool helpRotor, bool helpReflector) {

    std::cout << "                     __                                   " << std::endl;
    std::cout << "                    |  \\                                  " << std::endl;
    std::cout << "  ______   _______   \\$$  ______   ______ ____    ______  " << std::endl;
    std::cout << " /      \\ |       \\ |  \\ /      \\ |      \\    \\  |      \\ " << std::endl;
    std::cout << "|  $$$$$$\\| $$$$$$$\\| $$|  $$$$$$\\| $$$$$$\\$$$$\\  \\$$$$$$\\" << std::endl;
    std::cout << "| $$    $$| $$  | $$| $$| $$  | $$| $$ | $$ | $$ /      $$" << std::endl;
    std::cout << "| $$$$$$$$| $$  | $$| $$| $$__| $$| $$ | $$ | $$|  $$$$$$$" << std::endl;
    std::cout << " \\$$     \\| $$  | $$| $$ \\$$    $$| $$ | $$ | $$ \\$$    $$" << std::endl;
    std::cout << "  \\$$$$$$$ \\$$   \\$$ \\$$ _\\$$$$$$$ \\$$  \\$$  \\$$  \\$$$$$$$" << std::endl;
    std::cout << "                        |  \\__| $$                        " << std::endl;
    std::cout << "                         \\$$    $$                        " << std::endl;
    std::cout << "                          \\$$$$$$                          " << std::endl;
    std::cout << "\n";
    
    if (helpRotor) {
        std::cout << "Rotor options:\n"  
              << "                          -l, --left-rotor <wiring> <ring setting> <start position>\n"
              << "                          -m, --middle-rotor <wiring> <ring setting> <start position>\n"
              << "                          -r, --right-rotor <wiring> <ring setting> <start position>\n"
              << "\n"
              << "If no rotors are specified the default configuration is <I 0 0> <II 0 0> <III 0 0>\n"
              << "The rotor order is left-to-right: the first rotor used is the right one\n"
              << "\n"
              << "Options:\n"
              << "  <wiring>                                            Specify the internal wiring of the rotor\n"
              << "\n"
              << "  +----------+---------------------------------+---------------------+------------------------+\n"
              << "  |  option  |             wiring              |   date introduced   |       model name       |\n"
              << "  +----------+---------------------------------+---------------------+------------------------+\n"
              << "  |    I     |   EKMFLGDQVZNTOWYHXUSPAIBRCJ    |        1930         |  Enigma I (Wehrmacht)  |\n"
              << "  +----------+---------------------------------+---------------------+------------------------+\n"
              << "  |    II    |   AJDKSIRUXBLHWTMCQGZNPYFVOE    |        1930         |  Enigma I (Wehrmacht)  |\n"
              << "  +----------+---------------------------------+---------------------+------------------------+\n"
              << "  |    III   |   BDFHJLCPRTXVZNYEIWGAKMUSQO    |        1930         |  Enigma I (Wehrmacht)  |\n"
              << "  +----------+---------------------------------+---------------------+------------------------+\n"
              << "\n"
              << "  <ring setting>                                      Specify the ring setting\n"
              << "The ring setting can be given as a number [0-25] or a letter [aA-zZ]\n"
              << "It corresponds to an additional offset between the internal wiring and the rotor"
              << "\n"
              << "  <start position>                                    Specify the starting position of the rotor\n"
              << "The starting position can be given as a number [0-25] or a letter [aA-zZ]\n"
              << "It corresponds to the initial offset that can be seen at the top of the machine\n"
              << "\n"
              << "Examples:         enigma --left-rotor I 0 0 --middle-rotor II 0 0 --right-rotor III 0 0\n"
              << "\n"
              << "equivalent to     enigma --left-rotor I A A --middle-rotor II A A --right-rotor III A A\n";
    }
    else if (helpReflector) {
        std::cout << "Reflector option usage: -R, --reflector <wiring>\n"
              << "\n"
              << "If no reflector is specified the default one is B\n"
              << "Option:\n"
              << "  <wiring>                                            Specify the internal wiring of the rotor\n"
              << "\n"
              << "  +----------+---------------------------------+\n"
              << "  |  option  |             wiring              |\n"
              << "  +----------+---------------------------------+\n"
              << "  |    A     |   EJMZALYXVBWFCRQUONTSPIKHGD    |\n"
              << "  +----------+---------------------------------+\n"
              << "  |    B     |   YRUHQSLDPXNGOKMIEBFZCWVJAT    |\n"
              << "  +----------+---------------------------------+\n"
              << "  |    C     |   FVPJIAOYEDRZXWGCTKUQSBNMHL    |\n"
              << "  +----------+---------------------------------+\n"
              << "\n"
              << "\n"
              << "Examples:         enigma -R A -\n"
              << "\n"
              << "equivalent to     enigma --reflector A\n";
    }
    else {
        std::cout << "Usage: enigma [options]\n"
              << "Options:\n"
              << "  -h, --help <rotor|reflector>                                Display help message\n"
              << "  -l, --left-rotor <wiring> <ring setting> <start position>   Specify the left rotor parameters\n"
              << "  -m, --middle-rotor <wiring> <ring setting> <start position> Specify the middle rotor parameters\n"
              << "  -r, --right-rotor <wiring> <ring setting> <start position>  Specify the right rotor parameters\n"
              << "  -R, --reflector <wiring>                                    Specify the reflector wiring\n"
              << "\n"
              << "Example:          enigma --left-rotor I 0 0 --middle-rotor II 0 0 --right-rotor III 0 0 --reflector B\n"
              << "\n"
              << "equivalent to     enigma --left-rotor I A A --middle-rotor II A A --right-rotor III A A --reflector B\n";
    }
    
}