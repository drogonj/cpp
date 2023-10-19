
#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <unistd.h>

# define RESET	"\033[0m"
# define RED 	"\033[31m"
# define GREEN  "\033[32m"
# define BLUE   "\033[34m"
# define YELLOW	"\033[33m"
# define MAGENTA "\033[35m"

class Base
{
public:
    virtual ~Base(void) {};
};

class   A : public Base { };
class   B : public Base { };
class   C : public Base { };

Base * generate(void);
void identify(Base *p);
void identify(Base &p);