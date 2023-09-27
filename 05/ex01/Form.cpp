
#include "Form.hpp"

Form::Form(void) :_name("none"), _isSigned(false), _requiredGradeToSign(150), _requiredGradeToExec(150)
{
	std::cout << GREEN << "Form default constructor called" << RESET << std::endl;
}

Form::Form(const std::string & name, int requiredGradeToSign, int requiredGradeToExec) : _name(name),  _isSigned(false), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExec(requiredGradeToExec)
{
	if (this->_requiredGradeToSign < 1 || this->_requiredGradeToExec < 1)
		throw GradeTooHighException();
	else if (this->_requiredGradeToSign > 150 || this->_requiredGradeToExec > 150)
		throw GradeTooLowException();
	std::cout << GREEN << "Form constructor called" << RESET << std::endl;
}

Form::Form(const Form & src) : _name(src._name), _isSigned(src._isSigned), _requiredGradeToSign(src._requiredGradeToSign), _requiredGradeToExec(src._requiredGradeToExec)
{
	std::cout << GREEN << "Form copy constructor called" << RESET << std::endl;
}

Form::~Form(void)
{
	std::cout << RED << "Form destructor called" << RESET << std::endl;
}

const std::string & Form::getName(void)
{
	return (this->_name);
}

void	Form::beSigned(const Bureaucrat & src)
{
	if (src.getGrade() > this->_requiredGradeToSign)
		throw GradeTooLowException();
	this->_isSigned = true;
}

Form & Form::operator=(const Form &src)
{
	(void)src;
	return (*this);
}

std::ostream & operator<<(std::ostream & out, const Form & src)
{
	out << "Form \"" << src._name << "\" ";
	src._isSigned ? out << "is signed." : out << "is not signed." << std::endl;
	out << "A grade of " << src._requiredGradeToSign << " is required to sign it." << std::endl;;
	out << "A grade of " << src._requiredGradeToExec << " is required to execute it.";
	return (out);
}

