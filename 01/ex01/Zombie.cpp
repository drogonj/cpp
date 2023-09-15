
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "Zombie Constructor Called." << std::endl;
}

Zombie::Zombie( void )
{
	this->name = "default";
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

void	Zombie::give_name(std::string new_name)
{
	this->name = new_name;
}
