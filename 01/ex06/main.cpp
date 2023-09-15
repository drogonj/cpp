
#include "Harl.hpp"

void	complaining( void )
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

int	which_one(std::string arg)
{
	std::string		wordList[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		if (arg == wordList[i])
			return (i);
	return (-1);
}

int	main(int argc, char **argv)
{
	Harl	himself;

	if (argc != 2)
		complaining();
	else
	{
		switch (which_one(argv[1]))
		{
			case 0:
				himself.complain("DEBUG");
				break;
			case 1:
				himself.complain("INFO");
				break;
			case 2:
				himself.complain("WARNING");
				break;
			case 3:
				himself.complain("ERROR");
				break;
			default:
				complaining();
		}
	}
	return (0);
}
