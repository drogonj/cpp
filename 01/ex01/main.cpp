
#include "Zombie.hpp"

int main( void )
{
	Zombie* Horde = zombieHorde(6, "White walker");

	for (int i = 0; i < 6; i++)
		std::cout << "I'm white walker number " << i << std::endl;

	for (int i = 0; i < 6; i++)
		Horde[i].announce();

	delete [] Horde;
	return (0);
}