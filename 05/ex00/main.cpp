
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
	std::cout << std::endl;
	std::cout << "Changing Louis's grade to 150" << std::endl;
	Louis.setGrade(150);
	std::cout << Louis << std::endl;
	std::cout << std::endl;
	std::cout << "Trying to increment Louis's grade..." << std::endl;
	try {
		Louis.incrementGrade();
	} catch (std::exception & err){
		std::cout << YELLOW << err.what() << RESET << std::endl;
	}
    return (0);
}
