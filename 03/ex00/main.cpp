
#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	Maul("Maul");
	ClapTrap	Qui_Gon("Qui_Gon");
	ClapTrap	Kenobi("Kenobi");

	std::cout << std::endl;

	Qui_Gon.attack("Maul");
	Kenobi.attack("Maul");
	Maul.attack("Kenobi");
	Kenobi.takeDamage(2);

	std::cout << std::endl;

	Qui_Gon.attack("Maul");

	std::cout << std::endl;

	Kenobi.beRepaired(2);

	std::cout << std::endl;

	Qui_Gon.attack("Maul");
	Maul.attack("Qui Gon");
	Qui_Gon.takeDamage(10);

	std::cout << std::endl;

	Maul.attack("Kenobi");
	Kenobi.takeDamage(8);
	Kenobi.attack("Maul");
	Maul.takeDamage(4);

	std::cout << std::endl;

	Kenobi.attack("Maul");
	Maul.takeDamage(6);

	std::cout << std::endl;
}