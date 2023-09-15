
#include "FragTrap.hpp"

FragTrap::FragTrap( std::string _name ) : ClapTrap(_name)
{
	std::cout << GREEN << "FragTrap " << this->_name << " constructor called" << RESET << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap( const FragTrap & src ) : ClapTrap(src)
{
	std::cout << GREEN << "FragTrap " << this->_name << " Copy constructor called"
			  << RESET << std::endl;
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << RED << "FragTrap " << this->_name << " destructor called" << RESET << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << YELLOW << this->_name << ": Somebody wants an High Five ?? No one ? ..." << RESET << std::endl;
}

FragTrap& 	FragTrap::operator=( const FragTrap &src )
{
	this->_name = src._name;
	this->_hit_points = src._hit_points;
	this->_energy_points = src._energy_points;
	this->_attack_damage = src._attack_damage;
	return (*this);
}