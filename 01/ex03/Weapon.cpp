
#include "Weapon.hpp"

Weapon::Weapon(std::string weapon)
{
	this->_type = weapon;
	std::cout << "Weapon constructor called." << std::endl;
}

Weapon::Weapon( void )
{
	std::string	_default = "none";

	this->_type = _default;
	std::cout << "Weapon constructor called." << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon destructor called." << std::endl;
}

std::string	Weapon::getType()
{
	std::string&	weaponREF = this->_type;

	return (weaponREF);
}

void	Weapon::setType(std::string new_type)
{
	this->_type = new_type;
}