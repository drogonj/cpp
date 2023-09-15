
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie(std::string name);
		Zombie( void );
		~Zombie( void );
		void	announce( void );
		void	give_name(std::string new_name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif