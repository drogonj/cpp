
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main( void )
{
	ScavTrap	Benoit("Benoit");
	FragTrap	test("Jacqueline");
	FragTrap	Jacqueline(test);

	std::cout << std::endl;

	Jacqueline.highFivesGuys();
	Benoit.attack("Jacqueline");

	std::cout << std::endl;
	std::cout << "Jacqueline: You're too weak against my immeasurable power !!!" << std::endl << std::endl;

	Jacqueline.beRepaired(1000);
	Jacqueline.takeDamage(20);
	Jacqueline.attack("Benoit");
	Benoit.guardGate();

	std::cout << std::endl;
	std::cout << "Jacqueline: Planetary devastation!!!" << std::endl << std::endl;

	Jacqueline.attack("Benoit");
	Jacqueline.attack("Benoit");
	Jacqueline.attack("Benoit");
	Jacqueline.attack("Benoit");
	Benoit.takeDamage(120);

	std::cout << std::endl;
	std::cout << "Jacqueline: Pathetic..." << std::endl << std::endl;

	return 0;
}
