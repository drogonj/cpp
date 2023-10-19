
#pragma once

#include <iostream>

class Data
{
public:
    Data(void) {};
    Data(std::string str) : str(str) {};
    Data(const Data & src) : str(src.str) {};
    ~Data(void) {};

    std::string str;

    Data & operator=(const Data & src);
};