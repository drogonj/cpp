
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# define RESET	"\033[0m"
# define RED 	"\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"
# define YELLOW	"\033[33m"

class	Fixed
{
	private:
		int					fixedN;
		static const int	StaConFixedN = 8;

	public:
		//Constructor && destructor
		Fixed( void );
		Fixed( Fixed const & src);
		~Fixed();
		//Functions
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		//Operators
		Fixed &	operator=( Fixed const & src);
};

#endif