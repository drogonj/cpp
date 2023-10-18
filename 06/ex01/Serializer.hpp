
#pragma once

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class   Serializer
{
public:
    Serializer(void);
    Serializer(const Serializer & src);
    ~Serializer(void);

    uintptr_t serialize(Data *ptr);
    Data *deserialize(uintptr_t raw);

    Serializer & operator=(const Serializer & src);
};