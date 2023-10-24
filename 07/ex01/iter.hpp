
#pragma once

#include <iostream>

# define RESET	"\033[0m"
# define RED 	"\033[31m"
# define GREEN  "\033[32m"
# define BLUE   "\033[34m"
# define YELLOW	"\033[33m"
# define MAGENTA "\033[35m"

template<typename T>
void    iter(T *array, size_t size, void (*func)(T&))
{
    for (size_t i = 0; i < size; i++)
    {
        (*func)(array[i]);
    }
}