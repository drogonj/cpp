
#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
public:
	FragTrap( std::string _name );
	FragTrap( const FragTrap & src );
	~FragTrap( void );

	void	highFivesGuys( void );

	FragTrap & operator=( const FragTrap & src );
};

#endif
