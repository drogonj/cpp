
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

    static uintptr_t serialize(Data *ptr);
    static Data * deserialize(uintptr_t raw);

    Serializer & operator=(const Serializer & src);
};