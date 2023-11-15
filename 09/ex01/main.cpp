
#include "RPN.hpp"

static bool checkArgs(char *args) {
    int i = 0;
    for ( ; args[i]; i++) {
        if (i % 2 != 0 && args[i] != ' ') {
            if ((args[i] < '0' || args[i] > '9') && args[i] != '+' && args[i] != '-' && args[i] != '*' && args[i] != '/')
                std::cout << YELLOW << "error: unrecognized character" << RESET << std::endl;
            else
                std::cout << YELLOW << "error: bad pattern" << RESET << std::endl;
            return (false);
        } else if (i % 2 == 0 && (args[i] < '0' || args[i] > '9') && args[i] != '+' && args[i] != '-' && args[i] != '*' && args[i] != '/') {
            if (args[i] == ' ')
                std::cout << YELLOW << "error: bad pattern" << RESET << std::endl;
            else
                std::cout << YELLOW << "error: unrecognized character" << RESET << std::endl;
            return (false);
        }
    }
    if (i > 0 && args[i - 1] == ' ') {
        std::cout << YELLOW << "error: bad pattern" << RESET << std::endl;
        return (false);
    }
    return (true);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << MAGENTA << "usage exemple: ./RPN \"1 2 * 2 / 2 * 2 4 - +\"" << RESET << std::endl;
    } else if (checkArgs(argv[1])) {
        RPN     rpn;
        try {
            std::cout << GREEN << rpn.calculate(argv[1]) << RESET << std::endl;
        } catch (std::exception &e) {
            std::cout << YELLOW << e.what() << RESET << std::endl;
            return (-1);
        }
    }
    return (0);
}