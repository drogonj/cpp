
#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string _name ) : ClapTrap(_name)
{
	std::cout << GREEN << "ScavTrap " << this->_name << " constructor called" << RESET << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap(src)
{
	std::cout << GREEN << "ScavTrap " << this->_name << " Copy constructor called"
			  << RESET << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << RED << "ScavTrap " << this->_name << " destructor called" << RESET << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << YELLOW << "ScavTrap " << this->_name << " attacks " << target
				  << ", causing " << this->_attack_damage << " points of damage!" << RESET << std::endl;
		this->_energy_points -= 1;
	}
	else if (this->_hit_points <= 0)
		std::cout << YELLOW << "ScavTrap " << this->_name << " tried to attack " << target << " but he is no longer"
																							  "in condition to fight" << RESET << std::endl;
	else
		std::cout << YELLOW << "ScavTrap " << this->_name << " tried to attack " << target << " but he hasn't enough "
																							  "energy point" << RESET << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << YELLOW << "ScavTrap " << this->_name << " entered Gate Keeper mode" << RESET << std::endl;
}

ScavTrap& 	ScavTrap::operator=( const ScavTrap &src )
{
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	return (*this);
}