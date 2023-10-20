
#include "includes.hpp"

int main(void)
{

    std::cout << YELLOW << "Identifying by pointer: " << std::endl;
    Base * p = generate();
    identify(p);

    // usleep(1000000); // Uncomment if p and r are always the same (because of the bad random gen)
    std::cout << std::endl;

    std::cout << YELLOW << "Identifying by reference: " << std::endl;
    Base & r = *generate();
    identify(r);

    delete p;
    delete &r;

    return (0);
}