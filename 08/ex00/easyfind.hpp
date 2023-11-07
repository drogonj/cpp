
#pragma once

#include <iostream>
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
    (void)o;
    typename T::iterator    it = c.begin();
    typename T::iterator    end = c.end();
    for ( ; it != end; ++it) {
        if (*it == o)
            return (std::distance(c.begin(), it));
    }
    return (-1);
}