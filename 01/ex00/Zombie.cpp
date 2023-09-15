
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "Zombie Constructor Called." << std::endl;
}

Zombie::~Zombie( void )
{
	std::cout << "Zombie " << this->name << " Destructor Called." << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}