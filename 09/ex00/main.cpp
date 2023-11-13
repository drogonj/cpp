
#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << MAGENTA << "usage: \"./btc <input.txt/csv/...>\"" << RESET << std::endl;
        return (-1);
    }
    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cerr << YELLOW << "error: can't open file" << RESET << std::endl;
        return (-1);
    }
    BitcoinExchange btc;
    try {
        btc.loadDataBase();
    } catch (std::exception &e) {
        std::cout << YELLOW << e.what() << RESET << std::endl;
        return (-1);
    }
    try {
        btc.exec();
    } catch (std::exception &e) {
        std::cout << YELLOW << e.what() << RESET << std::endl;
        return (-1);
    }
    file.close();
}
