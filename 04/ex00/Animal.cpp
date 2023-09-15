
#include "Animal.hpp"

Animal::Animal( void )
{
	std::cout << GREEN << "Animal constructor called" << RESET << std::endl;
	this->type = "None";
}

Animal::Animal( const Animal & src )
{
	std::cout << GREEN << "Animal copy constructor called" << RESET << std::endl;
	*this = src;
}

Animal::~Animal( void )
{
	std::cout << RED << "Animal destructor called" << RESET << std::endl;
}

std::string	Animal::getType( void ) const
{
	return (this->type);
}

void	Animal::makeSound( void ) const
{

}

Animal & Animal::operator=( const Animal & src )
{
	this->type = src.type;
	return (*this);
}
