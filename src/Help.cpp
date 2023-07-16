#include <iostream>

void printHelp(bool helpRotor, bool helpReflector) {

    if (helpRotor) {
        std::cout << "Rotor option usage: -r1, --rotor1 <wiring> <ring setting> <start position>\n"
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
              << "Examples:         enigma -r1 I 0 0 -r2 II 0 0 -r3 III 0 0\n"
              << "\n"
              << "equivalent to     enigma -r1 I A A -r2 II A A -r3 III A A\n";
    }
    if (helpReflector) {
        std::cout << "Reflector option usage: -re, --reflector <wiring>\n"
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
              << "Examples:         enigma -re A -\n"
              << "\n"
              << "equivalent to     enigma --reflector A\n";
    }
    else {
        std::cout << "Usage: enigma [options]\n"
              << "Options:\n"
              << "  -h, --help <rotor|reflector>                            Display general help message\n"
              << "  -r1, --rotor1 <wiring> <ring setting> <start position>  Specify the left rotor parameters\n"
              << "  -r2, --rotor2 <wiring> <ring setting> <start position>  Specify the middle rotor parameters\n"
              << "  -r3, --rotor3 <wiring> <ring setting> <start position>  Specify the right rotor parameters\n"
              << "  -re, --reflector <wiring>                               Specify the reflector wiring\n"
              << "\n"
              << "Example:          enigma -r1 I 0 0 -r2 II 0 0 -r3 III 0 0 -re B\n"
              << "\n"
              << "equivalent to     enigma -r1 I A A -r2 II A A -r3 III A A -re B\n";
    }
    
}