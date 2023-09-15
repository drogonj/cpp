
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << GREEN << "ClapTrap " << name << " constructor called" << RESET << std::endl;
	this->_name = name;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
}

ClapTrap::ClapTrap( const ClapTrap &src )
{
	std::cout << GREEN << "ClapTrap " << this->_name << " Copy constructor called"
	<< RESET << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << RED << "ClapTrap " << this->_name << " has been destructed" << RESET << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << YELLOW << "ClapTrap " << this->_name << " attacks " << target
				  << ", causing " << this->_attack_damage << " points of damage!" << RESET << std::endl;
		this->_energy_points -= 1;
	}
	else if (this->_hit_points <= 0)
		std::cout << YELLOW << "ClapTrap " << this->_name << " tried to attack " << target << " but he is no longer"
		"in condition to fight" << RESET << std::endl;
	else
		std::cout << YELLOW << "ClapTrap " << this->_name << " tried to attack " << target << " but he hasn't enough "
		"energy point" << RESET << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points <= 0)
	{
		std::cout << RED << "ClapTrap " << this->_name << " received " << amount
				  << " points of damage! He's already KO, but after all better make sure" << RESET << std::endl;
	}
	else
	{
		std::cout << RED << "ClapTrap " << this->_name << " received " << amount
				  << " points of damage!" << RESET << std::endl;
		this->_hit_points -= amount;
		if (this->_hit_points <= 0)
			std::cout << RED << "ClapTrap " << this->_name << " is KO" << RESET << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		std::cout << BLUE << "ClapTrap " << this->_name << " is repaired and gains "
				  << amount << " life points" << RESET << std::endl;
		this->_energy_points -= 1;
		this->_hit_points += amount;
	}
	else if (this->_hit_points <= 0)
		std::cout << BLUE << "ClapTrap " << this->_name << " tried to repair but he is no longer in condition to fight"
				  << RESET << std::endl;
	else
		std::cout << BLUE << "ClapTrap " << this->_name << " tried to repair but he hasn't enough energy point"
				  << RESET << std::endl;
}

ClapTrap& 	ClapTrap::operator=( const ClapTrap &src )
{
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	return (*this);
}