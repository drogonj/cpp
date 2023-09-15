
#include "Cat.hpp"

Cat::Cat( void )
{
	std::cout << GREEN << "Cat constructor called" << RESET << std::endl;
	this->type = "Cat";
}

Cat::Cat( const Cat &src )
{
	std::cout << GREEN << "Cat copy constructor called" << RESET << std::endl;
	*this = src;
}

Cat::~Cat( void )
{
	std::cout << RED << "Cat destructor called" << RESET << std::endl;
}

void	Cat::makeSound( void ) const
{
	std::cout << YELLOW << "Miaou Miaou" << RESET << std::endl;
}

Cat	& Cat::operator=( const Cat &src )
{
	this->type = src.type;
	return (*this);
}