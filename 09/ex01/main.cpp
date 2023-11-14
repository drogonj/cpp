
#include "RPN.hpp"

static bool checkArgs(char *args) {
    for (int i = 0; args[i]; i++) {
        if (i % 2 != 0 && args[i] != ' ') {
            if ((args[i] < '0' || args[i] > '9') && args[i] != '+' && args[i] != '-' && args[i] != '*' && args[i] != '/')
                std::cerr << YELLOW << "error: unrecognized character" << RESET << std::endl;
            else
                std::cerr << YELLOW << "error: bad pattern" << RESET << std::endl;
            return (false);
        } else if (i % 2 == 0 && (args[i] < '0' || args[i] > '9') && args[i] != '+' && args[i] != '-' && args[i] != '*' && args[i] != '/') {
            std::cerr << YELLOW << "error: unrecognized character" << RESET << std::endl;
            return (false);
        }
    }
    return (true);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << MAGENTA << "usage exemple: ./RPN \"1 2 * 2 / 2 * 2 4 - +\"" << RESET << std::endl;
    } else if (checkArgs(argv[1])) {
        // Code
        // Ajouter chiffre a la stack tant que pas d'op rencontres
        // Si + d'op que de chiffre return error psq pas possible
        // ex: "3 2 4 - +" = "3 (2 - 4)" = "3 -2" = "3 + -2" = 1
    }
}