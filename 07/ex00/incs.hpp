
#pragma once

#include <iostream>

# define RESET	"\033[0m"
# define RED 	"\033[31m"
# define GREEN  "\033[32m"
# define BLUE   "\033[34m"
# define YELLOW	"\033[33m"
# define MAGENTA "\033[35m"

template<typename T>
void    swap(T & a, T & b)
{
    T   tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T       max(const T & a, const T & b)
{
    return (a > b ? a : b);
}

template<typename T>
T       min(const T & a, const T & b)
{
    return (a > b ? b : a);
}
