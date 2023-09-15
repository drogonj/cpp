
#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <iostream>

# define RESET	"\033[0m"
# define RED 	"\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"
# define YELLOW	"\033[33m"

class	WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal( void );
		WrongAnimal( const WrongAnimal & src );
		virtual ~WrongAnimal( void );

		void				makeSound( void ) const;
		std::string			getType( void ) const;

		WrongAnimal & operator=( const WrongAnimal & src );
};

#endif