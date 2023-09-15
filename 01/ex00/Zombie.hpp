
#include <iostream>
#include <fstream>

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie(std::string name);
		~Zombie( void );
		void	announce( void );
};
