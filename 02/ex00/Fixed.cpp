
#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
	this->fixedN = 0;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
	*this = src;
}

Fixed::~Fixed( void )
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << YELLOW <<  "getRawBits member function called" <<  RESET << std::endl;
	return (this->fixedN);
}

void	Fixed::setRawBits( const int raw )
{
	this->fixedN = raw;
}

Fixed& 	Fixed::operator=( const Fixed &src )
{
	std::cout << BLUE << "Copy assignment operator called" << RESET << std::endl;
	this->setRawBits(src.getRawBits());
	return (*this);
}
