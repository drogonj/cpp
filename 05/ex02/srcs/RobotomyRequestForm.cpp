
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
	std::cout << BLUE << "*Brrrt Brrt*" << RESET << std::endl;

    std::srand(static_cast<unsigned>(std::time(0)));
    int randomNbr = std::rand();
    int randomRes = (randomNbr % 101);

	if (randomRes >= 50)
		std::cout << BLUE << this->_target << " has been successfully robotomized" << RESET << std::endl;
	else
		std::cout << BLUE << this->_target << " robotomization has failed" << RESET << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	(void)src;
	return (*this);
}
