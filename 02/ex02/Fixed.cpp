
#include "Fixed.hpp"

Fixed::Fixed( void )
{
	this->fixedN = 0;
}

Fixed::Fixed( Fixed const & src )
{
	*this = src;
}

Fixed::Fixed( const int n )
{
	this->fixedN = n << Bits;
}

Fixed::Fixed( const float n )
{
	this->fixedN = roundf((float)(n * (1 << this->Bits)));
}

Fixed::~Fixed( void )
{

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

bool	Fixed::operator>( Fixed const & src )
{
	if (this->fixedN > src.fixedN)
		return (true);
	else
		return (false);
}

bool	Fixed::operator<( Fixed const & src )
{
	if (this->fixedN < src.fixedN)
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=( Fixed const & src )
{
	if (this->fixedN >= src.fixedN)
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=( Fixed const & src )
{
	if (this->fixedN <= src.fixedN)
		return (true);
	else
		return (false);
}

bool	Fixed::operator==( Fixed const & src )
{
	if (this->fixedN == src.fixedN)
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=( Fixed const & src )
{
	if (this->fixedN != src.fixedN)
		return (true);
	else
		return (false);
}

Fixed	Fixed::operator+( Fixed const & src )
{
	Fixed	res(this->toFloat() + src.toFloat());

	return (res);
}

Fixed	Fixed::operator-( Fixed const & src )
{
	Fixed	res(this->toFloat() - src.toFloat());

	return (res);
}

Fixed	Fixed::operator*( Fixed const & src )
{
	Fixed	res(this->toFloat() * src.toFloat());

	return (res);
}

Fixed	Fixed::operator/( Fixed const & src )
{
	Fixed	res(this->toFloat() / src.toFloat());

	return (res);
}

Fixed	Fixed::operator++( int )
{
	Fixed	buff(*this);

	this->fixedN += 1;
	return (buff);
}

Fixed	Fixed::operator--( int )
{
	Fixed	buff(*this);

	this->fixedN -= 1;
	return (buff);
}

Fixed & Fixed::operator++( void )
{
	this->fixedN += 1;
	return (*this);
}

Fixed & Fixed::operator--( void )
{
	this->fixedN -= 1;
	return (*this);
}

Fixed &	Fixed::min(Fixed & first, Fixed & second)
{
	if (first < second)
		return (first);
	else
		return (second);
}

Fixed &	Fixed::max(Fixed & first, Fixed & second)
{
	if (first > second)
		return (first);
	else
		return (second);
}

Fixed const &	Fixed::min(Fixed const & first, Fixed const & second)
{
	if (first.fixedN < second.fixedN)
		return (first);
	else
		return (second);
}

Fixed const &	Fixed::max(Fixed const & first, Fixed const & second)
{
	if (first.fixedN > second.fixedN)
		return (first);
	else
		return (second);
}

std::ostream&	operator<<(std::ostream & out, const Fixed & instance)
{
	out << instance.toFloat();
	return (out);
}
