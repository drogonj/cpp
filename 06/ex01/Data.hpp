
#pragma once

#include <iostream>

class Data
{
public:
    Data(void);
    Data(std::string str);
    Data(const Data & src);
    ~Data(void);

    std::string str;

    Data & operator=(const Data & src);
};