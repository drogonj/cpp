
#pragma once

#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cfloat>
#include <typeinfo>
#include <exception>
#include <iomanip>

# define RESET	"\033[0m"
# define RED 	"\033[31m"
# define GREEN  "\033[32m"
# define BLUE   "\033[34m"
# define YELLOW	"\033[33m"
# define MAGENTA "\033[35m"

// Todod
// operator =

class ScalarConverter
{
private:
    static void convertChar(const char c);
    static void convertInt(const int n);
    static void convertFloat(const float f, const std::string & str);
    static void convertDouble(const double d, const std::string & str);
    static bool pseudoLiteral(const std::string & str);

public:
    ScalarConverter(void) { }
    ScalarConverter(const ScalarConverter &src) { *this = src; }
    ~ScalarConverter(void) { }

    static void convert(const std::string & str);
};