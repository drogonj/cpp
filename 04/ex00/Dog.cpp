
#include "Dog.hpp"

Dog::Dog( void )
{
	std::cout << GREEN << "Dog constructor called" << RESET << std::endl;
	this->type = "Dog";
}

Dog::Dog( const Dog &src )
{
	std::cout << GREEN << "Dog copy constructor called" << RESET << std::endl;
	*this = src;
}

Dog::~Dog( void )
{
	std::cout << RED << "Dog destructor called" << RESET << std::endl;
}

void	Dog::makeSound( void ) const
{
	std::cout << YELLOW << "Wouaf Wouaf" << RESET << std::endl;
}

Dog	& Dog::operator=( const Dog &src )
{
	this->type = src.type;
	return (*this);
}