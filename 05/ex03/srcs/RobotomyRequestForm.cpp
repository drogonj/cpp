
#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request Form", 72, 45), _target("none")
{
	std::cout << GREEN << "RobotomyRequestForm default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string & target) : AForm("Robotomy Request Form", 72, 45), _target(target)
{
	std::cout << GREEN << "RobotomyRequestForm constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & src) : AForm(src), _target(src._target)
{
	std::cout << GREEN << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << RED << "RobotomyRequestForm destructor called" << RESET << std::endl;
}

const std::string & RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(const Bureaucrat &src) const
{
	if (src.getGrade() > this->getRequiredGradeToExecute())
		throw GradeTooLowException();
	else if (!this->isSigned())
		throw FormNotSigned();

	std::cout << BLUE << "*Brrrrrrrrrrrrt*" << RESET << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << BLUE << "*Brrrt Brrt*" << RESET << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));

	std::random_device					rand;	// Initialise le generateur de nb aleatoire
	std::mt19937 						generator(rand()); // Genere le nb aleatoire
	std::uniform_int_distribution<int>	distribution(0, 100); // Redistribue le resultat dans une tranche de nombre

	int									res = distribution(generator);

	if (res >= 50)
		std::cout << BLUE << this->_target << " has been successfully robotomized" << RESET << std::endl;
	else
		std::cout << BLUE << this->_target << " robotomization has failed" << RESET << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	(void)src;
	return (*this);
}
