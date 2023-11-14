
#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << MAGENTA << "usage: \"./btc <input.txt/csv/...>\"" << RESET << std::endl;
        return (-1);
    }
    BitcoinExchange btc;
    try {
        btc.loadDataBase();
    } catch (std::exception &e) {
        std::cerr << YELLOW << "database: " << e.what() << RESET << std::endl;
        return (-1);
    }
    try {
        btc.exec(argv[1]);
    } catch (std::exception &e) {
        std::cout << YELLOW << e.what() << RESET << std::endl;
        return (-1);
    }
}
