
#include "includes.hpp"

Base * generate(void)
{
    std::srand(static_cast<unsigned>(std::time(0)));
    int randomNbr = std::rand();
    int res = randomNbr % 900;

    if (res < 300) {
        std::cout << BLUE << "Generating class A object" << RESET << std::endl;
        return (new A());
    } else if (res < 600) {
        std::cout << BLUE << "Generating class B object" << RESET << std::endl;
        return (new B());
    } else {
        std::cout << BLUE << "Generating class C object" << RESET << std::endl;
        return (new C());
    }
}

void identify(Base *p)
{
    A   *a = dynamic_cast<A *>(p);
    B   *b = dynamic_cast<B *>(p);
    C   *c = dynamic_cast<C *>(p);
    if (a)
        std::cout << GREEN << "Object of class A identified" << RESET << std::endl;
    else if (b)
        std::cout << GREEN << "Object of class B identified" << RESET << std::endl;
    else if (c)
        std::cout << GREEN << "Object of class C identified" << RESET << std::endl;
}

void identify(Base &p)
{
    try {
        A   &a = dynamic_cast<A &>(p); (void)a;
        std::cout << GREEN << "Object of class A identified" << RESET << std::endl;
    } catch (std::exception &bc) {}

    try {
        B   &b = dynamic_cast<B &>(p); (void)b;
        std::cout << GREEN << "Object of class B identified" << RESET << std::endl;
    } catch (std::exception &bc) {}

    try {
        C   &c = dynamic_cast<C &>(p); (void)c;
        std::cout << GREEN << "Object of class C identified" << RESET << std::endl;
    } catch (std::exception &bc) {}
}
