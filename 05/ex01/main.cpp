
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void)
{
	Bureaucrat	Daniel("Daniel", 121);
	Form		ri("Internal Rules", 150, 20);
	Form		cv("Company Sales Contract", 1, 1);

	std::cout << std::endl;

	std::cout << Daniel << std::endl;
	Daniel.signForm(ri);

	std::cout << std::endl;

	std::cout << BLUE << cv << RESET << std::endl;
	Daniel.signForm(cv);

	std::cout << std::endl;

	Bureaucrat	Besos("Besos", 1);
	std::cout << Besos << std::endl;
	Besos.signForm(cv);

	std::cout << std::endl;
}
