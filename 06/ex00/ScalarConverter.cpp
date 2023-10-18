
#include "ScalarConverter.hpp"

static bool isInt(const std::string &str)
{
    if (str.length() > 11)
        return (false);
    for (int i = 0; str[i]; i++)
    {
        if (!isdigit(str[i]) && (i != 0 || str[i] != '-'))
            return (false);
    }
    return (true);
}

static int isFloatOrDouble(const std::string & str)
{
    size_t  len = str.length() - 1;
    bool    dot = false;
    bool    f = false;
    bool    exp = false;

    for (size_t i = 0; str[i]; i++)
    {
        if (str[i] == '.')
        {
            if (i == 0 || i == len || dot)
                return (-1);
            dot = true;
        }
        else if (str[i] == 'f')
        {
            if (i != len || !dot)
                return (-1);
            f = true;
        }
        else if (str[i] == 'e')
        {
            if (!dot || exp || (i != 0 && str[i - 1] == '.') || i == len)
                return (-1);
            exp = true;
        }
        else if (!isdigit(str[i]) && (str[i] != '-' || i != 0))
            return (-1);
    }
    if (!dot)
        return (-1);
    if (f)
        return (1);
    else
        return (2);
}

void ScalarConverter::convertChar(const char c)
{
    std::cout << GREEN << "char: ";
    if (c < 32 || c == 127)
        std::cout << BLUE << "Non displayable" << RESET << std::endl;
    else
        std::cout << BLUE << "'" << c << "'" << RESET << std::endl;
    std::cout << GREEN << "int: " << BLUE << static_cast<int>(c) << RESET << std::endl;
    std::cout << GREEN << "float: " << BLUE << static_cast<int>(c) << ".0f" << RESET << std::endl;
    std::cout << GREEN << "double: " << BLUE << static_cast<int>(c) << ".0" << RESET << std::endl;
}

void ScalarConverter::convertInt(const int n)
{
    std::cout << GREEN << "char: ";
    if ((n >= 0 && n < 32) || n == 127)
        std::cout << BLUE << "Non displayable" << RESET << std::endl;
    else if (n < 0 || n > 127)
        std::cout << BLUE << "impossible" << RESET << std::endl;
    else
        std::cout << BLUE << "'" << static_cast<char>(n) << "'" << RESET << std::endl;
    std::cout << GREEN << "int: " << BLUE << n << std::endl;
    std::cout << GREEN << "float: " << BLUE << n << ".0f" << RESET << std::endl;
    std::cout << GREEN << "double: " << BLUE << n << ".0" << RESET << std::endl;
}

void ScalarConverter::convertFloat(const float f, const std::string & str)
{
    double toD;
    double  rounded;

    std::cout << GREEN << "char: ";
    if (f < 32 || f == 127)
        std::cout << BLUE << "Non Displayable" << RESET << std::endl;
    else if (f < 0 || f > 127)
        std::cout << BLUE << "impossible" << RESET << std::endl;
    else
        std::cout << BLUE << "'" << static_cast<char>(f) << "'" << RESET << std::endl;
    std::cout << GREEN << "int: " << BLUE << static_cast<int>(f) << RESET << std::endl;
    rounded = round(f * std::pow(10, 5)) / std::pow(10, 5);
    if (rounded == static_cast<int>(f))
        std::cout << GREEN << "float: " << BLUE << f << ".0f" << RESET << std::endl;
    else
        std::cout << GREEN << "float: " << BLUE << f << "f" << RESET << std::endl;
    toD = std::strtold(str.c_str(), NULL);
    if (rounded == static_cast<int>(f))
        std::cout << GREEN << "double: " << BLUE << toD << ".0" << RESET << std::endl;
    else
        std::cout << GREEN << "double: " << BLUE << toD << RESET << std::endl;
}

void ScalarConverter::convertDouble(const double d, const std::string & str)
{
    float   toF;
    double  rounded;

    std::cout << GREEN << "char: ";
    if (d < 32 || d == 127)
        std::cout << BLUE << "Non Displayable" << RESET << std::endl;
    else if (d < 0 || d > 127)
        std::cout << BLUE << "impossible" << RESET << std::endl;
    else
        std::cout << BLUE << "'" << static_cast<char>(d) << "'" << RESET << std::endl;
    std::cout << GREEN << "int: " << BLUE << static_cast<int>(d) << RESET << std::endl;
    toF = std::strtof(str.c_str(), NULL);
    rounded = round(d * std::pow(10, 5)) / std::pow(10, 5);
    std::cout << rounded << std::endl;
    if (rounded == static_cast<int>(d))
        std::cout << GREEN << "float: " << BLUE << toF << ".0f" << RESET << std::endl;
    else
        std::cout << GREEN << "float: " << BLUE << toF << "f" << RESET << std::endl;
    if (rounded == static_cast<int>(d))
        std::cout << GREEN << "double: " << BLUE << d << ".0" << RESET << std::endl;
    else
        std::cout << GREEN << "double: " << BLUE << d << RESET << std::endl;
}

bool ScalarConverter::pseudoLiteral(const std::string & str)
{
    if (str != "nan" && str != "nanf" && str != "+inf"
        && str != "-inf" && str != "+inff" && str != "-inff")
        return (false);
    std::cout << GREEN << "char: " << BLUE << "impossible" << RESET << std::endl;
    std::cout << GREEN << "int: " << BLUE << "impossible" << RESET << std::endl;
    if (str == "nan" || str == "+inf" || str == "-inf")
        std::cout << GREEN << "float: " << BLUE << str << "f" << RESET << std::endl;
    else
        std::cout << GREEN << "float: " << BLUE << str << RESET << std::endl;
    if (str == "nanf" || str == "+inff" || str == "-inff")
    {
        std::string cpy = str;
        cpy.resize(cpy.size() - 1);
        std::cout << GREEN << "double: " << BLUE << cpy << RESET << std::endl;
    }
    else
        std::cout << GREEN << "double: " << BLUE << str << RESET << std::endl;
    return (true);
}

void ScalarConverter::convert(const std::string & str)
{
    long long int   toN;
    long double     toD;
    short int       float_or_double;

    toN = std::atoll(str.c_str());
    float_or_double = isFloatOrDouble(str);
    toD = std::strtod(str.c_str(), NULL);
    if (str.length() == 1 && !isdigit(str[0]))
        convertChar(str[0]);
    else if (isInt(str) && toN >= INT_MIN && toN <= INT_MAX)
        convertInt(toN);
    else if (float_or_double == 1)
        convertFloat(static_cast<float>(toD), str);
    else if (float_or_double == 2)
        convertDouble(toD, str);
    else if (!pseudoLiteral(str))
        std::cerr << RED << "Non-recognized or non-supported format" << RESET << std::endl;
}