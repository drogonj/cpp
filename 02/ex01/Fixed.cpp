
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

Fixed::Fixed( const int n )
{
	std::cout << GREEN << "Int constructor called" << RESET << std::endl;
	this->fixedN = n << Bits;
}

Fixed::Fixed( const float n )
{
	std::cout << GREEN <<  "Float constructor called" << RESET << std::endl;
	this->fixedN = roundf((float)(n * (1 << Bits)));
}

Fixed::~Fixed( void )
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	return (this->fixedN);
}

void	Fixed::setRawBits( const int raw )
{
	this->fixedN = raw;
}

int	Fixed::toInt() const
{
	return (this->fixedN >> this->Bits);
}

float	Fixed::toFloat() const
{
	return ((float)this->fixedN / roundf((float)(1 << this->Bits)));
}

Fixed& 	Fixed::operator=( const Fixed &src )
{
	this->setRawBits(src.getRawBits());
	return (*this);
}

std::ostream&	operator<<(std::ostream & out, const Fixed & instance)
{
	out << instance.toFloat();
	return (out);
}
