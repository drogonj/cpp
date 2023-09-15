
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

# define RESET	"\033[0m"
# define RED 	"\033[31m"
# define GREEN   "\033[32m"
# define BLUE    "\033[34m"
# define YELLOW	"\033[33m"

class	ClapTrap
{
	protected:
		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;

	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap & src);
		~ClapTrap( void );
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		ClapTrap & operator=(ClapTrap const & src);
};

#endif