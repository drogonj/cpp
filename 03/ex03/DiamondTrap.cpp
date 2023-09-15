
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	std::cout << GREEN << "DiamondTrap " << name << " constructor called" << RESET << std::endl;
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap & src) : ClapTrap(src._name), ScavTrap(src._name), FragTrap(src._name)
{
	std::cout << GREEN << "DiamondTrap " << this->_name << " Copy constructor called"
			  << RESET << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "DiamondTrap " << this->_name << " destructor called" << RESET << std::endl;
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << YELLOW << this->_name << ": I feel like i'm in conflict with myself.. A part of me like chocolate BUT THERE IS THIS F*C***G VOICE IN MY HEAD"
		<< RESET << std::endl;
}

DiamondTrap& 	DiamondTrap::operator=( const DiamondTrap &src )
{
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	return (*this);
}