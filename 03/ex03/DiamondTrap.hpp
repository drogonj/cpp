
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;

	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap & src);
		~DiamondTrap( void );

		void	whoAmI( void );
		void	attack(const std::string& target)
		{
			ScavTrap::attack(target);
		}

		DiamondTrap & operator=(const DiamondTrap & src);
};

#endif