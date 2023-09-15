
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): _name(name), _weapon(weapon)
{
	std::cout << "HumanA constructor called." << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA destructor called." << std::endl;
}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}