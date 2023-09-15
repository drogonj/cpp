
#include <iostream>

int	main( void )
{
	std::string		stringORG = "HI THIS IS BRAIN";

	std::string*	stringPTR = &stringORG;

	std::string&	stringREF = stringORG;

	std::cout << "stringORG address: " << &stringORG << std::endl;
	std::cout << "stringPTR address: " << stringPTR << std::endl;
	std::cout << "stringREF address: " << &stringREF << std::endl;

	std::cout << "\n" << std::endl;

	std::cout << "stringORG value: " << stringORG << std::endl;
	std::cout << "stringPTR value: " << *stringPTR << std::endl;
	std::cout << "stringREF value: " << stringREF << std::endl;

	return (0);
}