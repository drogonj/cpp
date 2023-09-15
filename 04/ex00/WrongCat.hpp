
#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"

class	WrongCat	: public WrongAnimal
{

	protected:
		std::string	type;

	public:
		WrongCat( void );
		WrongCat( const WrongCat & src );
		~WrongCat( void );

		void	makeSound( void ) const;

	WrongCat & operator=( const WrongCat & src );
};

#endif