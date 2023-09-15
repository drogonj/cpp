
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void )
{
	std::cout << GREEN << "WrongAnimal constructor called" << RESET << std::endl;
	this->type = "None";
}

WrongAnimal::WrongAnimal( const WrongAnimal & src )
{
	std::cout << GREEN << "WrongAnimal copy constructor called" << RESET << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << RED << "WrongAnimal destructor called" << RESET << std::endl;
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->type);
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "* silence *" << std::endl;
}

WrongAnimal & WrongAnimal::operator=( const WrongAnimal & src )
{
	this->type = src.type;
	return (*this);
}
