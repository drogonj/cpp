
#include "Zombie.hpp"

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );

int	main( void )
{
	randomChump("Louis");

	Zombie*	Freddy;
	Freddy = newZombie("Freddy");
	Freddy->announce();

	randomChump("Bob");

	delete Freddy;

	return (0);
}