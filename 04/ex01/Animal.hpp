
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

# define RESET	"\033[0m"
# define RED 	"\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"
# define YELLOW	"\033[33m"

class	Animal
{
	protected:
		std::string	type;

	public:
		Animal( void );
		Animal( const Animal & src );
		virtual ~Animal( void );

		virtual void	makeSound( void ) const;
		std::string		getType( void ) const;

		Animal & operator=( const Animal & src );
};

#endif