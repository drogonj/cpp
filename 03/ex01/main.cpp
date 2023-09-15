
#include "ScavTrap.hpp"

int	main( void )
{
	ClapTrap	bob("bob");
	ScavTrap	test("john");
	ScavTrap	john(test);

	bob.attack("john");
	john.guardGate();
	john.attack("bob");
	bob.takeDamage(20);

	std::cout << std::endl;

	ScavTrap	bile("bile");

	bile.attack("john");
	john.takeDamage(20);
	john.beRepaired(10);
	bile.attack("john");
	john.takeDamage(20);
	bile.attack("john");
	john.takeDamage(20);
	bile.attack("john");
	john.takeDamage(20);
	bile.attack("john");
	john.takeDamage(20);
	bile.attack("john");
	john.takeDamage(20);

	std::cout << std::endl;

	bile.attack("john");
	john.takeDamage(20);

	std::cout << std::endl;

	return 0;
}