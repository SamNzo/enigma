#include <iostream>

void printHelp(bool helpRotor, bool helpReflector, bool helpPlugboard) {

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
              << "If no rotors are specified the default configuration is <I A A> <II A A> <III A A>\n"
              << "The rotor order is left-to-right: the first rotor used is the right one\n"
              << "\n"
              << "Options:\n"
              << "  <wiring>                                            Specify the internal wiring of the rotor\n"
              << "\n"
              << "  +----------+---------------------------------+-----------+--------------------+--------------------------+\n"
              << "  |  option  |             wiring              |   notch   |  date introduced   |        model name        |\n"
              << "  +----------+---------------------------------+-----------+--------------------+--------------------------+\n"
              << "  |    I     |   EKMFLGDQVZNTOWYHXUSPAIBRCJ    |     Q     |        1930        |   Enigma I (Wehrmacht)   |\n"
              << "  +----------+---------------------------------+-----------+--------------------+--------------------------+\n"
              << "  |    II    |   AJDKSIRUXBLHWTMCQGZNPYFVOE    |     E     |        1930        |   Enigma I (Wehrmacht)   |\n"
              << "  +----------+---------------------------------+-----------+--------------------+--------------------------+\n"
              << "  |    III   |   BDFHJLCPRTXVZNYEIWGAKMUSQO    |     V     |        1930        |   Enigma I (Wehrmacht)   |\n"
              << "  +----------+---------------------------------+-----------+--------------------+--------------------------+\n"
              << "  |    IV    |   ESOVPZJAYQUIRHXLNFTGKDCMWB    |     J     |   December 1938    |         M3 Army          |\n"
              << "  +----------+---------------------------------+-----------+--------------------+--------------------------+\n"
              << "  |    V     |   VZBRGITYUPSDNHLXAWMJQOFECK    |     Z     |   December 1938    |         M3 Army          |\n"
              << "  +----------+---------------------------------+-----------+--------------------+--------------------------+\n"
              << "  |    VI    |   JPGVOUMFYQBENHZRDKASXLICTW    |    Z+M    |        1939        | M3 & M4 Naval (FEB 1942) |\n"
              << "  +----------+---------------------------------+-----------+--------------------+--------------------------+\n"
              << "  |    VII   |   NZJHGRCXMYSWBOUFAIVLPEKQDT    |    Z+M    |        1939        | M3 & M4 Naval (FEB 1942) |\n"
              << "  +----------+---------------------------------+-----------+--------------------+--------------------------+\n"
              << "  |    VIII  |   FKQHTLXOCBJSPDZRAMEWNIUYGV    |    Z+M    |        1939        | M3 & M4 Naval (FEB 1942) |\n"
              << "  +----------+---------------------------------+-----------+--------------------+--------------------------+\n"
              << "\n"
              << "  <ring setting>                                      Specify the ring setting\n"
              << "\n"
              << "      The ring setting is a letter [aA-zZ] (where A represents 0 and Z represents 25)\n"
              << "      It corresponds to an additional offset between the internal wiring and the rotor\n"
              << "\n"
              << "  <start position>                                    Specify the starting position of the rotor\n"
              << "\n"
              << "      The starting position is a letter [aA-zZ] (where A represents 0 and Z represents 25)\n"
              << "      It corresponds to the initial offset that can be seen at the top of the machine\n"
              << "\n"
              << "Examples:             enigma --left-rotor I a a --middle-rotor II a a --right-rotor III a a\n"
              << "\n"
              << "is equivalent to      enigma --left-rotor I A A --middle-rotor II A A --right-rotor III A A\n";
    }
    else if (helpReflector) {
        std::cout << "Reflector option usage: -R, --reflector <wiring>\n"
              << "\n"
              << "If no reflector is specified the default one is B\n"
              << "Option:\n"
              << "  <wiring>                                            Specify the internal wiring of the rotor\n"
              << "\n"
              << "  +----------+---------------------------------+--------------------+--------------------------+\n"
              << "  |  option  |             wiring              |  date introduced   |        model name        |\n"
              << "  +----------+---------------------------------+--------------------+--------------------------+\n"
              << "  |    A     |   EJMZALYXVBWFCRQUONTSPIKHGD    |         x          |            x             |\n"
              << "  +----------+---------------------------------+--------------------+--------------------------+\n"
              << "  |    B     |   YRUHQSLDPXNGOKMIEBFZCWVJAT    |         x          |            x             |\n"
              << "  +----------+---------------------------------+--------------------+--------------------------+\n"
              << "  |    C     |   FVPJIAOYEDRZXWGCTKUQSBNMHL    |         x          |            x             |\n"
              << "  +----------+---------------------------------+--------------------+--------------------------+\n"
              << "  |  B-Thin  |   ENKQAUYWJICOPBLMDXZVFTHRGS    |        1940        |     M4 R1 (M3 + Thin)    |\n"
              << "  +----------+---------------------------------+--------------------+--------------------------+\n"
              << "  |  C-Thin  |   RDOBJNTKVEHMLFCWZAXGYIPSUQ    |        1940        |     M4 R1 (M3 + Thin)    |\n"
              << "  +----------+---------------------------------+--------------------+--------------------------+\n"
              << "\n"
              << "Examples:             enigma -R A \n"
              << "\n"
              << "is equivalent to      enigma --reflector A\n";
    }
    else if (helpPlugboard) {
        std::cout << "Plugboard option usage: -P, --plugboard <couples>\n"
              << "\n"
              << "Historically the plugboard was a security layer added for military machines.\n"
              << "\n"
              << "Option:\n"
              << "  <couples>                                            Specify letters coupled together\n"
              << "\n"
              << "Example: to form couples A-B C-D and E-F\n"
              << "\n"
              << "                  enigma -P AB CD EF      or      enigma --plugboard AB CD EF\n";
    }
    else {
        std::cout << "Usage: enigma [options]\n"
              << "Options:\n"
              << "  -h, --help <rotor|reflector|plugboard>                      Display help message\n"
              << "  -l, --left-rotor <wiring> <ring setting> <start position>   Specify the left rotor parameters\n"
              << "  -m, --middle-rotor <wiring> <ring setting> <start position> Specify the middle rotor parameters\n"
              << "  -r, --right-rotor <wiring> <ring setting> <start position>  Specify the right rotor parameters\n"
              << "  -R, --reflector <wiring>                                    Specify the reflector wiring\n"
              << "  -M  --message <msg>                                         Message to encode/decode\n"
              << "\n"
              << "Example:          enigma --left-rotor I 0 0 --middle-rotor II 0 0 --right-rotor III 0 0 --reflector B --message ENIGMA\n"
              << "\n"
              << "equivalent to     enigma --left-rotor I A A --middle-rotor II A A --right-rotor III A A --reflector B --message ENIGMA\n";
    }
    
}
