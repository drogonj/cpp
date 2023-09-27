
#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main(void)
{
	{
		std::cout << MAGENTA << "//// ShrubberyCreationForm Tests ////" << RESET << std::endl;

		std::cout << std::endl;

		ShrubberyCreationForm greenpeace("Home");
		Bureaucrat bob("Bob", 139);

		std::cout << std::endl;
		std::cout << bob << std::endl; // Print bureaucrat's info
		std::cout << std::endl;
		std::cout << greenpeace << std::endl; // Print form's info
		std::cout << std::endl;
		bob.signForm(greenpeace); // Try to sign form "greenpisse"
		std::cout << std::endl;
		bob.executeForm(greenpeace);
		std::cout << std::endl;

		Bureaucrat pdg("Boss", 1);

		std::cout << std::endl;
		std::cout << pdg << std::endl; // Display Bureaucrat's info
		std::cout << std::endl;
		pdg.executeForm(greenpeace); // Execute form "greenpisse"
		std::cout << std::endl;

		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << MAGENTA << "//// RobotomyRequestForm Tests ////" << RESET << std::endl;

		std::cout << std::endl;

		RobotomyRequestForm killerRobotShark("Killer Shark");
		Bureaucrat			crazyDoctor("Crazy Doc", 30);

		std::cout << std::endl;
		std::cout << crazyDoctor << std::endl;
		std::cout << std::endl;

		crazyDoctor.signForm(killerRobotShark);
		std::cout << std::endl << "Ready to create the KILLER ROBOT SHARK mouahahah" << std::endl << std::endl;
		crazyDoctor.executeForm(killerRobotShark);

		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << MAGENTA << "//// PresidentialPardonForm Tests ////" << RESET << std::endl;

		std::cout << std::endl;

		Bureaucrat				bannedGuy("JarJar", 24);
		Bureaucrat				boss("Boss", 4);
		PresidentialPardonForm	pleasePardonMe("JarJar");

		std::cout << std::endl;

		std::cout << bannedGuy << std::endl;
		std::cout << boss << std::endl;
		std::cout << pleasePardonMe << std::endl;

		std::cout << std::endl;

		bannedGuy.signForm(pleasePardonMe);
		bannedGuy.executeForm(pleasePardonMe);

		std::cout << std::endl;

		boss.executeForm(pleasePardonMe);

		std::cout << std::endl;
	}
}
