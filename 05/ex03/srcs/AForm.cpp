
#include "../includes/AForm.hpp"

AForm::AForm(void) :_name("none"), _isSigned(false), _requiredGradeToSign(150), _requiredGradeToExec(150)
{
	std::cout << GREEN << "AForm default constructor called" << RESET << std::endl;
}

AForm::AForm(const std::string & name, int requiredGradeToSign, int requiredGradeToExec) : _name(name),  _isSigned(false), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExec(requiredGradeToExec)
{
	if (this->_requiredGradeToSign < 1 || this->_requiredGradeToExec < 1)
		throw GradeTooHighException();
	else if (this->_requiredGradeToSign > 150 || this->_requiredGradeToExec > 150)
		throw GradeTooLowException();
	std::cout << GREEN << "AForm constructor called" << RESET << std::endl;
}

AForm::AForm(const AForm & src) : _name(src._name), _isSigned(src._isSigned), _requiredGradeToSign(src._requiredGradeToSign), _requiredGradeToExec(src._requiredGradeToExec)
{
	std::cout << GREEN << "AForm copy constructor called" << RESET << std::endl;
}

AForm::~AForm(void)
{
	std::cout << RED << "AForm destructor called" << RESET << std::endl;
}

const std::string & AForm::getName(void) const
{
	return (this->_name);
}

int	AForm::getRequiredGradeToSign(void) const
{
	return (this->_requiredGradeToSign);
}

int	AForm::getRequiredGradeToExecute(void) const
{
	return (this->_requiredGradeToExec);
}

bool AForm::isSigned(void) const
{
	return (this->_isSigned);
}

void	AForm::beSigned(const Bureaucrat & src)
{
	if (src.getGrade() > this->_requiredGradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

void	AForm::execute(const Bureaucrat &src) const
{
	(void)src;
}

AForm & AForm::operator=(const AForm &src)
{
	(void)src;
	return (*this);
}

std::ostream & operator<<(std::ostream & out, const AForm & src)
{
    out << "Form \"" << src.getName() << "\" ";
    src.isSigned() ? out << "is signed." : out << "is not signed." << std::endl;
    out << "A grade of " << src.getRequiredGradeToSign() << " is required to sign it." << std::endl;;
    out << "A grade of " << src.getRequiredGradeToExecute() << " is required to execute it.";
    return (out);
}

