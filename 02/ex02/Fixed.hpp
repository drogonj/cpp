
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
		static const int	Bits = 8;

	public:
		//Constructor && destructor
		Fixed( void );
		Fixed( Fixed const & src);
		Fixed( const int n );
		Fixed( const float  n );
		~Fixed();
		//Functions
		int				getRawBits( void ) const;
		void			setRawBits( int const raw );
		float			toFloat( void ) const;
		int				toInt( void ) const;
		static Fixed &	min(Fixed & first, Fixed & second);
		static Fixed &	max(Fixed & first, Fixed & second);
		static const Fixed &	min(Fixed const & first, Fixed const & second);
		static const Fixed &	max(Fixed const & first, Fixed const & second);

		//Operators
		bool	operator>( Fixed const & src );
		bool	operator<( Fixed const & src );
		bool	operator>=( Fixed const & src );
		bool	operator<=( Fixed const & src );
		bool	operator==( Fixed const & src );
		bool	operator!=( Fixed const & src );

		Fixed &	operator=( Fixed const & src );
		Fixed	operator+( Fixed const & src );
		Fixed	operator-( Fixed const & src );
		Fixed	operator*(Fixed const & src );
		Fixed	operator/(Fixed const & src );
		Fixed	operator++( int n );
		Fixed	operator--( int n );
		Fixed & operator++( void );
		Fixed & operator--( void );
};

//Operators
std::ostream&	operator<<(std::ostream & out, const Fixed & instance);

#endif