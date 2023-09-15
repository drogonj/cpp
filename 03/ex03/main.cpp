
#include "DiamondTrap.hpp"

int	main( void )
{
	DiamondTrap WhatAreYou("god");
	ClapTrap	jarjar("jarjar");

	std::cout << std::endl;

	WhatAreYou.whoAmI();
	WhatAreYou.highFivesGuys();
	WhatAreYou.guardGate();
	WhatAreYou.attack("jarjar");
	WhatAreYou.whoAmI();

	std::cout << std::endl;

	jarjar.takeDamage(30);

	std::cout << std::endl;

	return 0;
}
