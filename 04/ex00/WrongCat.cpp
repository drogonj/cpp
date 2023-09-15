
#include "WrongCat.hpp"

WrongCat::WrongCat( void )
{
	std::cout << GREEN << "WrongCat constructor called" << RESET << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat &src )
{
	std::cout << GREEN << "WrongCat copy constructor called" << RESET << std::endl;
	*this = src;
}

WrongCat::~WrongCat( void )
{
	std::cout << RED << "WrongCat destructor called" << RESET << std::endl;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << YELLOW << "MIOU MIOU" << RESET << std::endl;
}

WrongCat	& WrongCat::operator=( const WrongCat &src )
{
	this->type = src.type;
	return (*this);
}