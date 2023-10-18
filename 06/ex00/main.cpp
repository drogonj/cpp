
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        if (argc > 2)
            std::cerr << RED << "Too many arguments" << RESET << std::endl;
        else
            std::cerr << RED << "Too few arguments" << RESET << std::endl;
        return (1);
    }

    ScalarConverter sc;
    sc.convert(argv[1]);

    return (0);
}