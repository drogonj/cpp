
#pragma once

#include <iostream>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <iomanip>

# define RESET	"\033[0m"
# define RED 	"\033[31m"
# define GREEN  "\033[32m"
# define BLUE   "\033[34m"
# define YELLOW	"\033[33m"
# define MAGENTA "\033[35m"

class ScalarConverter
{
private:
    ScalarConverter(void) { }
    ScalarConverter(const ScalarConverter &src) { *this = src; }

    static void convertChar(const char c);
    static void convertInt(const int n);
    static void convertFloat(const float f, const std::string & str);
    static void convertDouble(const double d, const std::string & str);
    static bool pseudoLiteral(const std::string & str);

public:
    ~ScalarConverter(void) { }

    static void convert(const std::string & str);

    ScalarConverter & operator=(const ScalarConverter & src);
};