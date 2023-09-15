
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

# define RESET	"\033[0m"
# define RED 	"\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"
# define YELLOW	"\033[33m"

class	Fixed
{
	private:
		int					fixedN;
		static const int	Bits = 8;

	public:
		//Constructor && destructor
		Fixed( void );
		Fixed( Fixed const & src);
		Fixed( const int n );
		Fixed( const float  n );
		~Fixed();
		//Functions
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		//Operators
		Fixed &	operator=( Fixed const & src );
};

//Operators
std::ostream&	operator<<(std::ostream & out, const Fixed & instance);

#endif