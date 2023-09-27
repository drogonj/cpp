
#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon Form", 25, 5), _target("none")
{
	std::cout << GREEN << "PresidentialPardonForm default constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string & target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
	std::cout << GREEN << "PresidentialPardonForm constructor called" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src) : AForm(src), _target(src._target)
{
	std::cout << GREEN << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << RED << "PresidentialPardonForm destructor called" << RESET << std::endl;
}

const std::string & PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(const Bureaucrat &src) const
{
	if (src.getGrade() > this->getRequiredGradeToExecute())
		throw GradeTooLowException();
	else if (!this->isSigned())
		throw FormNotSigned();

	std::cout << BLUE << this->_target << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	(void)src;
	return (*this);
}