
#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>

# define RESET	"\033[0m"
# define RED 	"\033[31m"
# define GREEN  "\033[32m"
# define BLUE   "\033[34m"
# define YELLOW	"\033[33m"
# define MAGENTA "\033[35m"

template<typename T>
int easyfind(T & c, int o)
{
    typename T::iterator it = std::find(c.begin(), c.end(), o);

    if (it == c.end()) {
        return (-1);
    } else {
        return (std::distance(c.begin(), it));
    }
}