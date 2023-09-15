
#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
public:
	ScavTrap( std::string name );
	ScavTrap( const ScavTrap & src );
	~ScavTrap( void );

	void	attack(const std::string &target);
	void	guardGate( void );

	ScavTrap & operator=(const ScavTrap & src);
};

#endif