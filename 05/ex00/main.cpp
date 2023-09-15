
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat  Louis("Louis", 5);

	try {
		Louis.setGrade(-1);
	} catch (std::exception & err) {
		std::cout << YELLOW << err.what() << RESET << std::endl;
	}
    std::cout << Louis.getName() << std::endl;
    std::cout << Louis.getGrade() << std::endl;
	std::cout << Louis << std::endl;

    return (0);
}
